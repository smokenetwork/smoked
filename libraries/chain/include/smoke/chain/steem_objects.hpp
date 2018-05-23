#pragma once

#include <smoke/protocol/authority.hpp>
#include <smoke/protocol/steem_operations.hpp>

#include <smoke/chain/steem_object_types.hpp>

#include <boost/multi_index/composite_key.hpp>
#include <boost/multiprecision/cpp_int.hpp>


namespace smoke { namespace chain {

   using smoke::protocol::asset;
   using smoke::protocol::price;
   using smoke::protocol::asset_symbol_type;

   typedef protocol::fixed_string_16 reward_fund_name_type;

   /**
    *  This object is used to track pending requests to convert sbd to steem
    */
   class convert_request_object : public object< convert_request_object_type, convert_request_object >
   {
      public:
         template< typename Constructor, typename Allocator >
         convert_request_object( Constructor&& c, allocator< Allocator > a )
         {
            c( *this );
         }

         convert_request_object(){}

         id_type           id;

         account_name_type owner;
         uint32_t          requestid = 0; ///< id set by owner, the owner,requestid pair must be unique
         asset             amount;
         time_point_sec    conversion_date; ///< at this time the feed_history_median_price * amount
   };


   class escrow_object : public object< escrow_object_type, escrow_object >
   {
      public:
         template< typename Constructor, typename Allocator >
         escrow_object( Constructor&& c, allocator< Allocator > a )
         {
            c( *this );
         }

         escrow_object(){}

         id_type           id;

         uint32_t          escrow_id = 20;
         account_name_type from;
         account_name_type to;
         account_name_type agent;
         time_point_sec    ratification_deadline;
         time_point_sec    escrow_expiration;
         asset             sbd_balance;
         asset             steem_balance;
         asset             pending_fee;
         bool              to_approved = false;
         bool              agent_approved = false;
         bool              disputed = false;

         bool              is_approved()const { return to_approved && agent_approved; }
   };

   /**
    *  If last_update is greater than 1 week, then volume gets reset to 0
    *
    *  When a user is a maker, their volume increases
    *  When a user is a taker, their volume decreases
    *
    *  Every 1000 blocks, the account that has the highest volume_weight() is paid the maximum of
    *  1000 SMOKE or 1000 * virtual_supply / (100*blocks_per_year) aka 10 * virtual_supply / blocks_per_year
    *
    *  After being paid volume gets reset to 0
    */
   class liquidity_reward_balance_object : public object< liquidity_reward_balance_object_type, liquidity_reward_balance_object >
   {
      public:
         template< typename Constructor, typename Allocator >
         liquidity_reward_balance_object( Constructor&& c, allocator< Allocator > a )
         {
            c( *this );
         }

         liquidity_reward_balance_object(){}

         id_type           id;

         account_id_type   owner;
         int64_t           steem_volume = 0;
         int64_t           sbd_volume = 0;
         uint128_t         weight = 0;

         time_point_sec    last_update = fc::time_point_sec::min(); /// used to decay negative liquidity balances. block num

         /// this is the sort index
         uint128_t volume_weight()const
         {
            return steem_volume * sbd_volume * is_positive();
         }

         uint128_t min_volume_weight()const
         {
            return std::min(steem_volume,sbd_volume) * is_positive();
         }

         void update_weight( bool hf9 )
         {
             weight = hf9 ? min_volume_weight() : volume_weight();
         }

         inline int is_positive()const
         {
            return ( steem_volume > 0 && sbd_volume > 0 ) ? 1 : 0;
         }
   };


   /**
    *  This object gets updated once per hour, on the hour
    */
   class feed_history_object  : public object< feed_history_object_type, feed_history_object >
   {
      feed_history_object() = delete;

      public:
         template< typename Constructor, typename Allocator >
         feed_history_object( Constructor&& c, allocator< Allocator > a )
            :price_history( a.get_segment_manager() )
         {
            c( *this );
         }

         id_type                                   id;

         price                                     current_median_history; ///< the current median of the price history, used as the base for convert operations
         bip::deque< price, allocator< price > >   price_history; ///< tracks this last week of median_feed one per hour
   };


   /**
    * @breif a route to send withdrawn vesting shares.
    */
   class withdraw_vesting_route_object : public object< withdraw_vesting_route_object_type, withdraw_vesting_route_object >
   {
      public:
         template< typename Constructor, typename Allocator >
         withdraw_vesting_route_object( Constructor&& c, allocator< Allocator > a )
         {
            c( *this );
         }

         withdraw_vesting_route_object(){}

         id_type  id;

         account_id_type   from_account;
         account_id_type   to_account;
         uint16_t          percent = 0;
         bool              auto_vest = false;
   };


   class decline_voting_rights_request_object : public object< decline_voting_rights_request_object_type, decline_voting_rights_request_object >
   {
      public:
         template< typename Constructor, typename Allocator >
         decline_voting_rights_request_object( Constructor&& c, allocator< Allocator > a )
         {
            c( *this );
         }

         decline_voting_rights_request_object(){}

         id_type           id;

         account_id_type   account;
         time_point_sec    effective_date;
   };

   enum curve_id
   {
      quadratic,
      quadratic_curation,
      linear,
      square_root
   };

   class reward_fund_object : public object< reward_fund_object_type, reward_fund_object >
   {
      public:
         template< typename Constructor, typename Allocator >
         reward_fund_object( Constructor&& c, allocator< Allocator > a )
         {
            c( *this );
         }

         reward_fund_object() {}

         reward_fund_id_type     id;
         reward_fund_name_type   name;
         asset                   reward_balance = asset( 0, SMOKE_SYMBOL );
         fc::uint128_t           recent_claims = 0;
         time_point_sec          last_update;
         uint128_t               content_constant = 0;
         uint16_t                percent_curation_rewards = 0;
         uint16_t                percent_content_rewards = 0;
         curve_id                author_reward_curve = linear;
         curve_id                curation_reward_curve = square_root;
   };

   struct by_price;
   struct by_expiration;
   struct by_account;

   struct by_owner;
   struct by_conversion_date;
   typedef multi_index_container<
      convert_request_object,
      indexed_by<
         ordered_unique< tag< by_id >, member< convert_request_object, convert_request_id_type, &convert_request_object::id > >,
         ordered_unique< tag< by_conversion_date >,
            composite_key< convert_request_object,
               member< convert_request_object, time_point_sec, &convert_request_object::conversion_date >,
               member< convert_request_object, convert_request_id_type, &convert_request_object::id >
            >
         >,
         ordered_unique< tag< by_owner >,
            composite_key< convert_request_object,
               member< convert_request_object, account_name_type, &convert_request_object::owner >,
               member< convert_request_object, uint32_t, &convert_request_object::requestid >
            >
         >
      >,
      allocator< convert_request_object >
   > convert_request_index;

   struct by_owner;
   struct by_volume_weight;
   typedef multi_index_container<
      liquidity_reward_balance_object,
      indexed_by<
         ordered_unique< tag< by_id >, member< liquidity_reward_balance_object, liquidity_reward_balance_id_type, &liquidity_reward_balance_object::id > >,
         ordered_unique< tag< by_owner >, member< liquidity_reward_balance_object, account_id_type, &liquidity_reward_balance_object::owner > >,
         ordered_unique< tag< by_volume_weight >,
            composite_key< liquidity_reward_balance_object,
                member< liquidity_reward_balance_object, fc::uint128, &liquidity_reward_balance_object::weight >,
                member< liquidity_reward_balance_object, account_id_type, &liquidity_reward_balance_object::owner >
            >,
            composite_key_compare< std::greater< fc::uint128 >, std::less< account_id_type > >
         >
      >,
      allocator< liquidity_reward_balance_object >
   > liquidity_reward_balance_index;

   typedef multi_index_container<
      feed_history_object,
      indexed_by<
         ordered_unique< tag< by_id >, member< feed_history_object, feed_history_id_type, &feed_history_object::id > >
      >,
      allocator< feed_history_object >
   > feed_history_index;

   struct by_withdraw_route;
   struct by_destination;
   typedef multi_index_container<
      withdraw_vesting_route_object,
      indexed_by<
         ordered_unique< tag< by_id >, member< withdraw_vesting_route_object, withdraw_vesting_route_id_type, &withdraw_vesting_route_object::id > >,
         ordered_unique< tag< by_withdraw_route >,
            composite_key< withdraw_vesting_route_object,
               member< withdraw_vesting_route_object, account_id_type, &withdraw_vesting_route_object::from_account >,
               member< withdraw_vesting_route_object, account_id_type, &withdraw_vesting_route_object::to_account >
            >,
            composite_key_compare< std::less< account_id_type >, std::less< account_id_type > >
         >,
         ordered_unique< tag< by_destination >,
            composite_key< withdraw_vesting_route_object,
               member< withdraw_vesting_route_object, account_id_type, &withdraw_vesting_route_object::to_account >,
               member< withdraw_vesting_route_object, withdraw_vesting_route_id_type, &withdraw_vesting_route_object::id >
            >
         >
      >,
      allocator< withdraw_vesting_route_object >
   > withdraw_vesting_route_index;

   struct by_from_id;
   struct by_to;
   struct by_agent;
   struct by_ratification_deadline;
   struct by_sbd_balance;
   typedef multi_index_container<
      escrow_object,
      indexed_by<
         ordered_unique< tag< by_id >, member< escrow_object, escrow_id_type, &escrow_object::id > >,
         ordered_unique< tag< by_from_id >,
            composite_key< escrow_object,
               member< escrow_object, account_name_type,  &escrow_object::from >,
               member< escrow_object, uint32_t, &escrow_object::escrow_id >
            >
         >,
         ordered_unique< tag< by_to >,
            composite_key< escrow_object,
               member< escrow_object, account_name_type,  &escrow_object::to >,
               member< escrow_object, escrow_id_type, &escrow_object::id >
            >
         >,
         ordered_unique< tag< by_agent >,
            composite_key< escrow_object,
               member< escrow_object, account_name_type,  &escrow_object::agent >,
               member< escrow_object, escrow_id_type, &escrow_object::id >
            >
         >,
         ordered_unique< tag< by_ratification_deadline >,
            composite_key< escrow_object,
               const_mem_fun< escrow_object, bool, &escrow_object::is_approved >,
               member< escrow_object, time_point_sec, &escrow_object::ratification_deadline >,
               member< escrow_object, escrow_id_type, &escrow_object::id >
            >,
            composite_key_compare< std::less< bool >, std::less< time_point_sec >, std::less< escrow_id_type > >
         >,
         ordered_unique< tag< by_sbd_balance >,
            composite_key< escrow_object,
               member< escrow_object, asset, &escrow_object::sbd_balance >,
               member< escrow_object, escrow_id_type, &escrow_object::id >
            >,
            composite_key_compare< std::greater< asset >, std::less< escrow_id_type > >
         >
      >,
      allocator< escrow_object >
   > escrow_index;


   struct by_account;
   struct by_effective_date;
   typedef multi_index_container<
      decline_voting_rights_request_object,
      indexed_by<
         ordered_unique< tag< by_id >, member< decline_voting_rights_request_object, decline_voting_rights_request_id_type, &decline_voting_rights_request_object::id > >,
         ordered_unique< tag< by_account >,
            member< decline_voting_rights_request_object, account_id_type, &decline_voting_rights_request_object::account >
         >,
         ordered_unique< tag< by_effective_date >,
            composite_key< decline_voting_rights_request_object,
               member< decline_voting_rights_request_object, time_point_sec, &decline_voting_rights_request_object::effective_date >,
               member< decline_voting_rights_request_object, account_id_type, &decline_voting_rights_request_object::account >
            >,
            composite_key_compare< std::less< time_point_sec >, std::less< account_id_type > >
         >
      >,
      allocator< decline_voting_rights_request_object >
   > decline_voting_rights_request_index;

   struct by_name;
   typedef multi_index_container<
      reward_fund_object,
      indexed_by<
         ordered_unique< tag< by_id >, member< reward_fund_object, reward_fund_id_type, &reward_fund_object::id > >,
         ordered_unique< tag< by_name >, member< reward_fund_object, reward_fund_name_type, &reward_fund_object::name > >
      >,
      allocator< reward_fund_object >
   > reward_fund_index;

} } // smoke::chain

#include <smoke/chain/comment_object.hpp>
#include <smoke/chain/account_object.hpp>

FC_REFLECT_ENUM( smoke::chain::curve_id,
                  (quadratic)(quadratic_curation)(linear)(square_root))


FC_REFLECT( smoke::chain::feed_history_object,
             (id)(current_median_history)(price_history) )
CHAINBASE_SET_INDEX_TYPE( smoke::chain::feed_history_object, smoke::chain::feed_history_index )

FC_REFLECT( smoke::chain::convert_request_object,
             (id)(owner)(requestid)(amount)(conversion_date) )
CHAINBASE_SET_INDEX_TYPE( smoke::chain::convert_request_object, smoke::chain::convert_request_index )

FC_REFLECT( smoke::chain::liquidity_reward_balance_object,
             (id)(owner)(steem_volume)(sbd_volume)(weight)(last_update) )
CHAINBASE_SET_INDEX_TYPE( smoke::chain::liquidity_reward_balance_object, smoke::chain::liquidity_reward_balance_index )

FC_REFLECT( smoke::chain::withdraw_vesting_route_object,
             (id)(from_account)(to_account)(percent)(auto_vest) )
CHAINBASE_SET_INDEX_TYPE( smoke::chain::withdraw_vesting_route_object, smoke::chain::withdraw_vesting_route_index )


FC_REFLECT( smoke::chain::escrow_object,
             (id)(escrow_id)(from)(to)(agent)
             (ratification_deadline)(escrow_expiration)
             (sbd_balance)(steem_balance)(pending_fee)
             (to_approved)(agent_approved)(disputed) )
CHAINBASE_SET_INDEX_TYPE( smoke::chain::escrow_object, smoke::chain::escrow_index )

FC_REFLECT( smoke::chain::decline_voting_rights_request_object,
             (id)(account)(effective_date) )
CHAINBASE_SET_INDEX_TYPE( smoke::chain::decline_voting_rights_request_object, smoke::chain::decline_voting_rights_request_index )

FC_REFLECT( smoke::chain::reward_fund_object,
            (id)
            (name)
            (reward_balance)
            (recent_claims)
            (last_update)
            (content_constant)
            (percent_curation_rewards)
            (percent_content_rewards)
            (author_reward_curve)
            (curation_reward_curve)
         )
CHAINBASE_SET_INDEX_TYPE( smoke::chain::reward_fund_object, smoke::chain::reward_fund_index )
