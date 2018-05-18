#pragma once

#include <smoke/protocol/base.hpp>
#include <smoke/protocol/operation_util.hpp>

#include <smoke/app/plugin.hpp>

namespace smoke { namespace witness {

using namespace std;
using smoke::protocol::base_operation;
using smoke::chain::database;

class witness_plugin;

struct enable_content_editing_operation : base_operation
{
   protocol::account_name_type   account;
   fc::time_point_sec            relock_time;

   void validate()const;

   void get_required_active_authorities( flat_set< protocol::account_name_type>& a )const { a.insert( account ); }
};

typedef fc::static_variant<
         enable_content_editing_operation
      > witness_plugin_operation;

DEFINE_PLUGIN_EVALUATOR( witness_plugin, witness_plugin_operation, enable_content_editing );

} } // smoke::witness

FC_REFLECT( smoke::witness::enable_content_editing_operation, (account)(relock_time) )

FC_REFLECT_TYPENAME( smoke::witness::witness_plugin_operation )

DECLARE_OPERATION_TYPE( smoke::witness::witness_plugin_operation )
