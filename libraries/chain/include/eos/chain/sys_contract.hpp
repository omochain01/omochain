#pragma once

#include <omo/chain/protocol/types.hpp>
#include <omo/chain/protocol/authority.hpp>


/**
 *  @file sys_contract
 *  @brief defines logic for the native omo system contract
 */

namespace omo { namespace chain {


   struct Transfer {
      account_name to;
      uint64_t     amount = 0;
      string       memo;
   };

   struct CreateAccount {
      account_name  new_account;
      Authority     owner;
      Authority     active;
      uint64_t      initial_balance = 0;
   };


} }

FC_REFLECT( omo::chain::Transfer, (to)(amount)(memo) )
FC_REFLECT( omo::chain::CreateAccount, (new_account)(owner)(active)(initial_balance) )
