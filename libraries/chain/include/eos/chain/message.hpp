#pragma once

#include <omo/chain/protocol/types.hpp>

namespace omo { namespace chain {

/**
 * @brief The message struct defines a blockchain message
 *
 * Messages are the heart of all activity on the blockchain -- all events and actions which take place in the chain are
 * recorded as messages. Messages are sent from one account (@ref sender) to another account (@ref recipient), and are
 * optionally also delivered to several other accounts (@ref notify_accounts).
 *
 * A message has a header that defines who sent it and who will be processing it. The message content is a binary blob,
 * @ref data, whose type is determined by @ref type, which is dynamic and defined by the scripting language.
 */
struct message {
   /// The account which sent the message
   account sender;
   /// The account to receive the message
   account recipient;
   /// Other accounts to notify about this message
   vector<account> notify_accounts;
   /// The message type -- this is defined by the contract(s) which create and/or process this message
   message_type type;
   /// The message contents
   vector<char> data;
};

} } // namespace omo::chain

FC_REFLECT(omo::chain::message, (sender)(recipient)(notify_accounts)(type)(data))
