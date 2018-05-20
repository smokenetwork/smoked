#pragma once

#include <smoke/protocol/asset.hpp>

namespace smoke { namespace chain { namespace util {

using smoke::protocol::asset;
using smoke::protocol::price;

inline asset to_sbd( const price& p, const asset& steem )
{
   FC_ASSERT( steem.symbol == SMOKE_SYMBOL );
   if( p.is_null() )
      return asset( 0, SBD_SYMBOL );
   return steem * p;
}

inline asset to_steem( const price& p, const asset& sbd )
{
   FC_ASSERT( sbd.symbol == SBD_SYMBOL );
   if( p.is_null() )
      return asset( 0, SMOKE_SYMBOL );
   return sbd * p;
}

} } }
