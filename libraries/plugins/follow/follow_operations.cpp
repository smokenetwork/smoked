#include <smoke/follow/follow_operations.hpp>

#include <smoke/protocol/operation_util_impl.hpp>

namespace smoke { namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } //smoke::follow

DEFINE_OPERATION_TYPE( smoke::follow::follow_plugin_operation )
