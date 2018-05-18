#include <smoke/witness/witness_operations.hpp>

#include <smoke/protocol/operation_util_impl.hpp>

namespace smoke { namespace witness {

void enable_content_editing_operation::validate()const
{
   chain::validate_account_name( account );
}

} } // smoke::witness

DEFINE_OPERATION_TYPE( smoke::witness::witness_plugin_operation )
