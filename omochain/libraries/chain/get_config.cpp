/*
 * Copyright (c) 2017, Respective Authors.
 *
 * The MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <omo/chain/get_config.hpp>
#include <omo/chain/config.hpp>
#include <omo/chain/protocol/types.hpp>

namespace omo { namespace chain {

fc::variant_object get_config()
{
   fc::mutable_variant_object result;

   result[ "OMO_KEY_PREFIX" ] = OMO_KEY_PREFIX;
   result[ "OMO_MIN_TRANSACTION_SIZE_LIMIT" ] = OMO_MIN_TRANSACTION_SIZE_LIMIT;
   result[ "OMO_MIN_BLOCK_INTERVAL" ] = OMO_MIN_BLOCK_INTERVAL;
   result[ "OMO_MAX_BLOCK_INTERVAL" ] = OMO_MAX_BLOCK_INTERVAL;
   result[ "OMO_DEFAULT_BLOCK_INTERVAL" ] = OMO_DEFAULT_BLOCK_INTERVAL;
   result[ "OMO_DEFAULT_MAX_TRANSACTION_SIZE" ] = OMO_DEFAULT_MAX_TRANSACTION_SIZE;
   result[ "OMO_DEFAULT_MAX_BLOCK_SIZE" ] = OMO_DEFAULT_MAX_BLOCK_SIZE;
   result[ "OMO_DEFAULT_MAX_TIME_UNTIL_EXPIRATION" ] = OMO_DEFAULT_MAX_TIME_UNTIL_EXPIRATION;
   result[ "OMO_DEFAULT_MAINTENANCE_INTERVAL" ] = OMO_DEFAULT_MAINTENANCE_INTERVAL;
   result[ "OMO_DEFAULT_MAINTENANCE_SKIP_SLOTS" ] = OMO_DEFAULT_MAINTENANCE_SKIP_SLOTS;
   result[ "OMO_MIN_UNDO_HISTORY" ] = OMO_MIN_UNDO_HISTORY;
   result[ "OMO_MAX_UNDO_HISTORY" ] = OMO_MAX_UNDO_HISTORY;
   result[ "OMO_MIN_BLOCK_SIZE_LIMIT" ] = OMO_MIN_BLOCK_SIZE_LIMIT;
   result[ "OMO_MIN_TRANSACTION_EXPIRATION_LIMIT" ] = OMO_MIN_TRANSACTION_EXPIRATION_LIMIT;
   result[ "OMO_100_PERCENT" ] = OMO_100_PERCENT;
   result[ "OMO_1_PERCENT" ] = OMO_1_PERCENT;
   result[ "OMO_DEFAULT_MAX_PRODUCERES" ] = OMO_DEFAULT_MAX_PRODUCERES;
   result[ "OMO_MAX_URL_LENGTH" ] = OMO_MAX_URL_LENGTH;
   result[ "OMO_NEAR_SCHEDULE_CTR_IV" ] = OMO_NEAR_SCHEDULE_CTR_IV;
   result[ "OMO_FAR_SCHEDULE_CTR_IV" ] = OMO_FAR_SCHEDULE_CTR_IV;
   result[ "OMO_CORE_ASSET_CYCLE_RATE" ] = OMO_CORE_ASSET_CYCLE_RATE;
   result[ "OMO_CORE_ASSET_CYCLE_RATE_BITS" ] = OMO_CORE_ASSET_CYCLE_RATE_BITS;

   return result;
}

} } // omo::chain
