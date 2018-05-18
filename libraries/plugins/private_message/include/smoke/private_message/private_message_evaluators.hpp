#pragma once

#include <smoke/chain/evaluator.hpp>

#include <smoke/private_message/private_message_operations.hpp>
#include <smoke/private_message/private_message_plugin.hpp>

namespace smoke { namespace private_message {

DEFINE_PLUGIN_EVALUATOR( private_message_plugin, smoke::private_message::private_message_plugin_operation, private_message )

} }
