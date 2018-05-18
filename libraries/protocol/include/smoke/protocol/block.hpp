#pragma once
#include <smoke/protocol/block_header.hpp>
#include <smoke/protocol/transaction.hpp>

namespace smoke { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // smoke::protocol

FC_REFLECT_DERIVED( smoke::protocol::signed_block, (smoke::protocol::signed_block_header), (transactions) )
