#pragma once

#include <smoke/protocol/operations.hpp>
#include <smoke/chain/steem_object_types.hpp>

namespace smoke { namespace app {

struct applied_operation
{
   applied_operation();
   applied_operation( const smoke::chain::operation_object& op_obj );

   smoke::protocol::transaction_id_type trx_id;
   uint32_t                               block = 0;
   uint32_t                               trx_in_block = 0;
   uint16_t                               op_in_trx = 0;
   uint64_t                               virtual_op = 0;
   fc::time_point_sec                     timestamp;
   smoke::protocol::operation           op;
};

} }

FC_REFLECT( smoke::app::applied_operation,
   (trx_id)
   (block)
   (trx_in_block)
   (op_in_trx)
   (virtual_op)
   (timestamp)
   (op)
)
