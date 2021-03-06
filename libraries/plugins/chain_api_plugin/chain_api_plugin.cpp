#include <omo/chain_api_plugin/chain_api_plugin.hpp>
#include <omo/chain/exceptions.hpp>

#include <fc/io/json.hpp>

namespace omo {

using namespace omo;

class chain_api_plugin_impl {
public:
   chain_api_plugin_impl(database& db)
      : db(db) {}

   database& db;
};


chain_api_plugin::chain_api_plugin()
   :my(new chain_api_plugin_impl(app().get_plugin<chain_plugin>().db())) {}
chain_api_plugin::~chain_api_plugin(){}

void chain_api_plugin::set_program_options(options_description&, options_description&) {}
void chain_api_plugin::plugin_initialize(const variables_map&) {}

#define CALL(api_name, api_handle, api_namespace, call_name) \
{std::string("/v1/" #api_name "/" #call_name), [this, api_handle](string, string body, url_response_callback cb) { \
          try { \
             if (body.empty()) body = "{}"; \
             auto result = api_handle.call_name(fc::json::from_string(body).as<api_namespace::call_name ## _params>()); \
             cb(200, fc::json::to_string(result)); \
          } catch (fc::eof_exception) { \
             cb(400, "Invalid arguments"); \
             elog("Unable to parse arguments: ${args}", ("args", body)); \
          } catch (fc::exception& e) { \
             cb(500, e.what()); \
             elog("Exception encountered while processing ${call}: ${e}", ("call", #api_name "." #call_name)("e", e)); \
          } \
       }}

#define CHAIN_RO_CALL(call_name) CALL(chain, ro_api, chain_apis::read_only, call_name)

void chain_api_plugin::plugin_startup() {
   auto ro_api = app().get_plugin<chain_plugin>().get_read_only_api();

   app().get_plugin<http_plugin>().add_api({
      CHAIN_RO_CALL(get_info),
      CHAIN_RO_CALL(get_block)
   });
}

void chain_api_plugin::plugin_shutdown() {}

}
