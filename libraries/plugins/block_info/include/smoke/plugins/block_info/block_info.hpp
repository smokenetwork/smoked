
#pragma once

#include <smoke/chain/steem_object_types.hpp>

namespace smoke { namespace plugin { namespace block_info {

struct block_info
{
   chain::block_id_type      block_id;
   uint32_t                  block_size                  = 0;
   uint64_t                  aslot                       = 0;
   uint32_t                  last_irreversible_block_num = 0;
};

struct block_with_info
{
   chain::signed_block       block;
   block_info                info;
};

} } }

FC_REFLECT( smoke::plugin::block_info::block_info,
   (block_id)
   (block_size)
   (aslot)
   (last_irreversible_block_num)
   )

FC_REFLECT( smoke::plugin::block_info::block_with_info,
   (block)
   (info)
   )
