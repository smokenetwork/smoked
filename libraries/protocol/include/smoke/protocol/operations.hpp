#pragma once

#include <smoke/protocol/operation_util.hpp>
#include <smoke/protocol/steem_operations.hpp>
#include <smoke/protocol/steem_virtual_operations.hpp>

namespace smoke { namespace protocol {

   /** NOTE: do not change the order of any operations prior to the virtual operations
    * or it will trigger a hardfork.
    */
   typedef fc::static_variant<
            vote_operation,
            comment_operation,

            transfer_operation,
            transfer_to_vesting_operation,
            withdraw_vesting_operation,

            account_create_operation,
            account_update_operation,

            witness_update_operation,
            account_witness_vote_operation,
            account_witness_proxy_operation,

            custom_operation,

            delete_comment_operation,
            custom_json_operation,
            comment_options_operation,
            set_withdraw_vesting_route_operation,
            challenge_authority_operation,
            prove_authority_operation,
            request_account_recovery_operation,
            recover_account_operation,
            change_recovery_account_operation,
            escrow_transfer_operation,
            escrow_dispute_operation,
            escrow_release_operation,
            escrow_approve_operation,
            custom_binary_operation,
            decline_voting_rights_operation,
            claim_reward_balance_operation,
            delegate_vesting_shares_operation,
            account_create_with_delegation_operation,

            /// virtual operations below this point
            author_reward_operation,
            curation_reward_operation,
            comment_reward_operation,
            liquidity_reward_operation,
            fill_vesting_withdraw_operation,
            shutdown_witness_operation,
            hardfork_operation,
            comment_payout_update_operation,
            return_vesting_delegation_operation,
            comment_benefactor_reward_operation,
            producer_reward_operation
         > operation;

   /*void operation_get_required_authorities( const operation& op,
                                            flat_set<string>& active,
                                            flat_set<string>& owner,
                                            flat_set<string>& posting,
                                            vector<authority>&  other );

   void operation_validate( const operation& op );*/

   bool is_market_operation( const operation& op );

   bool is_virtual_operation( const operation& op );

} } // smoke::protocol

/*namespace fc {
    void to_variant( const smoke::protocol::operation& var,  fc::variant& vo );
    void from_variant( const fc::variant& var,  smoke::protocol::operation& vo );
}*/

DECLARE_OPERATION_TYPE( smoke::protocol::operation )
FC_REFLECT_TYPENAME( smoke::protocol::operation )
