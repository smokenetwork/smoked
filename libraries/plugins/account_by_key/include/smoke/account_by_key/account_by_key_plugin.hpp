#pragma once
#include <smoke/app/plugin.hpp>
#include <smoke/chain/database.hpp>

#include <smoke/account_by_key/account_by_key_api.hpp>

namespace smoke { namespace account_by_key {

#define ACCOUNT_BY_KEY_PLUGIN_NAME "account_by_key"

namespace detail { class account_by_key_plugin_impl; }

class account_by_key_plugin : public smoke::app::plugin
{
   public:
      account_by_key_plugin( smoke::app::application* app );

      std::string plugin_name()const override { return ACCOUNT_BY_KEY_PLUGIN_NAME; }
      virtual void plugin_set_program_options(
         boost::program_options::options_description& cli,
         boost::program_options::options_description& cfg ) override;
      virtual void plugin_initialize( const boost::program_options::variables_map& options ) override;
      virtual void plugin_startup() override;

      friend class detail::account_by_key_plugin_impl;
      std::unique_ptr< detail::account_by_key_plugin_impl > my;
};

} } // smoke::account_by_key
