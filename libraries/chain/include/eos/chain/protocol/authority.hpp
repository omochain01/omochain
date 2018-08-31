#pragma once
#include <omo/chain/protocol/types.hpp>


namespace omo { namespace chain {

   struct PermissionLevel {
      account_name      account;
      permission_name   level;
      uint16_t          weight;
   };

   struct KeyPermission {
      public_key_type key;
      uint16_t        weight;
   };

   struct Authority {
      uint32_t                threshold = 0;
      vector<PermissionLevel> accounts;
      vector<KeyPermission>   keys;
   };

} }  // omo::chain

FC_REFLECT( omo::chain::Authority, (threshold)(accounts)(keys) )
