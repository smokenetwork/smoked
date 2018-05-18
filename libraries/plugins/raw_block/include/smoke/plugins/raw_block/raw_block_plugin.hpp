
#pragma once

#include <smoke/app/plugin.hpp>

namespace smoke { namespace plugin { namespace raw_block {

using smoke::app::application;

class raw_block_plugin : public smoke::app::plugin
{
   public:
      raw_block_plugin( application* app );
      virtual ~raw_block_plugin();

      virtual std::string plugin_name()const override;
      virtual void plugin_initialize( const boost::program_options::variables_map& options ) override;
      virtual void plugin_startup() override;
      virtual void plugin_shutdown() override;
};

} } }
