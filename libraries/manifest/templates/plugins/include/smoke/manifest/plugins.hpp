
#pragma once

#include <memory>
#include <string>
#include <vector>

namespace smoke { namespace app {

class abstract_plugin;
class application;

} }

namespace smoke { namespace plugin {

void initialize_plugin_factories();
std::shared_ptr< smoke::app::abstract_plugin > create_plugin( const std::string& name, smoke::app::application* app );
std::vector< std::string > get_available_plugins();

} }
