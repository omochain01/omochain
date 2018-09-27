#pragma once
#include <appbase/application.hpp>
#include <hotc/chain_plugin/chain_plugin.hpp>

namespace hotc {
   using namespace appbase;

   class net_plugin : public appbase::plugin<net_plugin>
   {
      public:
        net_plugin();
        virtual ~net_plugin();

        APPBASE_PLUGIN_REQUIRES((chain_plugin))
        virtual void set_program_options(options_description& cli, options_description& cfg) override;

        void plugin_initialize(const variables_map& options);
        void plugin_startup();
        void plugin_shutdown();

        void broadcast_block(const chain::signed_block &sb);
        void broadcast_transaction (const chain::SignedTransaction &txn);

      private:
        std::unique_ptr<class net_plugin_impl> my;
   };

}
