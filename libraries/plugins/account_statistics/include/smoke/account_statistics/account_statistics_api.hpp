#pragma once

#include <smoke/account_statistics/account_statistics_plugin.hpp>

#include <fc/api.hpp>

namespace smoke{ namespace app {
   struct api_context;
} }

namespace smoke { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl;
}

class account_statistics_api
{
   public:
      account_statistics_api( const smoke::app::api_context& ctx );

      void on_api_startup();

   private:
      std::shared_ptr< detail::account_statistics_api_impl > _my;
};

} } // smoke::account_statistics

FC_API( smoke::account_statistics::account_statistics_api, )