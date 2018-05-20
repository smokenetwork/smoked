/*
 * Copyright (c) 2016 Steemit, Inc., and contributors.
 */
#pragma once

#define SMOKE_BLOCKCHAIN_VERSION              ( version(0, 20, 0) )
#define SMOKE_BLOCKCHAIN_HARDFORK_VERSION     ( hardfork_version( SMOKE_BLOCKCHAIN_VERSION ) )

#ifdef IS_TEST_NET
#define SMOKE_INIT_PRIVATE_KEY                (fc::ecc::private_key::regenerate(fc::sha256::hash(std::string("init_key"))))
#define SMOKE_INIT_PUBLIC_KEY_STR             (std::string( smoke::protocol::public_key_type(SMOKE_INIT_PRIVATE_KEY.get_public_key()) ))
#define SMOKE_CHAIN_ID                        (fc::sha256::hash("testnet"))

#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define STEEM_SYMBOL  (uint64_t(3) | (uint64_t('T') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< STEEM with 3 digits of precision
#define SBD_SYMBOL    (uint64_t(3) | (uint64_t('T') << 8) | (uint64_t('B') << 16) | (uint64_t('D') << 24) ) ///< Test Backed Dollars with 3 digits of precision
#define STMD_SYMBOL   (uint64_t(3) | (uint64_t('T') << 8) | (uint64_t('S') << 16) | (uint64_t('T') << 24) | (uint64_t('D') << 32) ) ///< Test Dollars with 3 digits of precision

#define SMOKE_SYMBOL_STR                      "TEST"
#define SMOKE_ADDRESS_PREFIX                  "TST"

// 1451606400 ~ Sun Jan 18 1970 02:13:26 GMT+0700 (+08)
// 1515765200 ~ Fri Jan 12 2018 20:53:20 GMT+0700 (+08)
//#define SMOKE_GENESIS_TIME                    (fc::time_point_sec(1451606400))
#define SMOKE_GENESIS_TIME                    (fc::time_point_sec(1515765200))
//#define SMOKE_MINING_TIME                     (fc::time_point_sec(1451606400))
#define SMOKE_MINING_TIME                     (fc::time_point_sec(1515765200))
#define SMOKE_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define SMOKE_CASHOUT_WINDOW_SECONDS_PRE_HF12 (SMOKE_CASHOUT_WINDOW_SECONDS)
#define SMOKE_CASHOUT_WINDOW_SECONDS_PRE_HF17 (SMOKE_CASHOUT_WINDOW_SECONDS)
#define SMOKE_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define SMOKE_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define SMOKE_VOTE_CHANGE_LOCKOUT_PERIOD      (60*10) /// 10 minutes
#define SMOKE_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define SMOKE_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define SMOKE_ORIGINAL_MIN_ACCOUNT_CREATION_FEE 0
#define SMOKE_MIN_ACCOUNT_CREATION_FEE          0

#define SMOKE_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define SMOKE_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define SMOKE_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define SMOKE_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1
#else // IS LIVE SMOKE NETWORK

#define SMOKE_INIT_PUBLIC_KEY_STR             "SMK6LLegbAgLAy28EHrffBVuANFWcFgmqRMW13wBmTExqFE9SCkg4"
#define SMOKE_CHAIN_ID                        (fc::sha256::hash("smoke")) // a66e00caa50e6817bbe24e927bf48c5d4ba1b33f36bdbb5fa262a04012c4e3ee
#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define STEEM_SYMBOL  (uint64_t(3) | (uint64_t('S') << 8) | (uint64_t('M') << 16) | (uint64_t('O') << 24) | (uint64_t('K') << 32) | (uint64_t('E') << 40)) ///< SMOKE with 3 digits of precision
#define SBD_SYMBOL    (uint64_t(3) | (uint64_t('S') << 8) | (uint64_t('B') << 16) | (uint64_t('D') << 24) ) ///< SMOKE Backed Dollars with 3 digits of precision
#define STMD_SYMBOL   (uint64_t(3) | (uint64_t('S') << 8) | (uint64_t('M') << 16) | (uint64_t('K') << 24) | (uint64_t('D') << 32) ) ///< SMOKE Dollars with 3 digits of precision
#define SMOKE_SYMBOL_STR                      "SMOKE"
#define SMOKE_ADDRESS_PREFIX                  "SMK"

#define SMOKE_GENESIS_TIME_EPOCH              1518000000  // Wed Feb 07 2018 17:40:00 GMT+0700 (+07)
#define SMOKE_GENESIS_TIME                    (fc::time_point_sec(SMOKE_GENESIS_TIME_EPOCH))
#define SMOKE_MINING_TIME                     (fc::time_point_sec(SMOKE_GENESIS_TIME_EPOCH + 9000))
#define SMOKE_CASHOUT_WINDOW_SECONDS_PRE_HF12 (60*60*24)    /// 1 day
#define SMOKE_CASHOUT_WINDOW_SECONDS_PRE_HF17 (60*60*12)    /// 12 hours
#define SMOKE_CASHOUT_WINDOW_SECONDS          (60*60*24*7)  /// 7 days
#define SMOKE_SECOND_CASHOUT_WINDOW           (60*60*24*30) /// 30 days
#define SMOKE_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24*14) /// 2 weeks
#define SMOKE_VOTE_CHANGE_LOCKOUT_PERIOD      (60*60*2)     /// 2 hours
#define SMOKE_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define SMOKE_UPVOTE_LOCKOUT_HF17             (fc::hours(12))

#define SMOKE_ORIGINAL_MIN_ACCOUNT_CREATION_FEE  100000
#define SMOKE_MIN_ACCOUNT_CREATION_FEE           0 // 1

#define SMOKE_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
#define SMOKE_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define SMOKE_OWNER_UPDATE_LIMIT                          fc::minutes(60)
#define SMOKE_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1 // 3186477

#endif

#define SMOKE_BLOCK_INTERVAL                  3
#define SMOKE_BLOCKS_PER_YEAR                 (365*24*60*60/SMOKE_BLOCK_INTERVAL)
#define SMOKE_BLOCKS_PER_DAY                  (24*60*60/SMOKE_BLOCK_INTERVAL)
#define SMOKE_START_VESTING_BLOCK             (SMOKE_BLOCKS_PER_DAY * 7)
//#define SMOKE_START_MINER_VOTING_BLOCK        (SMOKE_BLOCKS_PER_DAY * 30)
#define SMOKE_START_MINER_VOTING_BLOCK        (1 * 30)

#define SMOKE_INIT_MINER_NAME                 "initminer"
#define SMOKE_NUM_INIT_MINERS                 1
#define SMOKE_INIT_TIME                       (fc::time_point_sec());

#define SMOKE_MAX_WITNESSES                   5 // 21
#define SMOKE_MAX_VOTED_WITNESSES_HF0         3 // 19
#define SMOKE_MAX_MINER_WITNESSES_HF0         1
#define SMOKE_MAX_RUNNER_WITNESSES_HF0        1

#define SMOKE_MAX_VOTED_WITNESSES_HF17        4 // 20
#define SMOKE_MAX_MINER_WITNESSES_HF17        0
#define SMOKE_MAX_RUNNER_WITNESSES_HF17       1

#define SMOKE_HARDFORK_REQUIRED_WITNESSES     3 // 17 of the 21 dpos witnesses (20 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.
#define SMOKE_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define SMOKE_MAX_MEMO_SIZE                   2048
#define SMOKE_MAX_PROXY_RECURSION_DEPTH       4
#define SMOKE_VESTING_WITHDRAW_INTERVALS_PRE_HF_16 104
#define SMOKE_VESTING_WITHDRAW_INTERVALS      13
#define SMOKE_VESTING_WITHDRAW_INTERVAL_SECONDS (60*60*24*7) /// 1 week per interval

#define SMOKE_MAX_WITHDRAW_ROUTES             10
#define SMOKE_SAVINGS_WITHDRAW_TIME        	(fc::days(3))
#define SMOKE_SAVINGS_WITHDRAW_REQUEST_LIMIT  100
#define SMOKE_VOTE_REGENERATION_SECONDS       (5*60*60*24) // 5 day
#define SMOKE_MAX_VOTE_CHANGES                5
#define SMOKE_REVERSE_AUCTION_WINDOW_SECONDS  (60*30) /// 30 minutes
#define SMOKE_MIN_VOTE_INTERVAL_SEC           3
#define SMOKE_VOTE_DUST_THRESHOLD             (50000000)

#define SMOKE_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(60*5)) // 5 minutes
#define SMOKE_MIN_REPLY_INTERVAL              (fc::seconds(20)) // 20 seconds
#define SMOKE_POST_AVERAGE_WINDOW             (60*60*24u) // 1 day
#define SMOKE_POST_MAX_BANDWIDTH              (4*SMOKE_100_PERCENT) // 2 posts per 1 days, average 1 every 12 hours
#define SMOKE_POST_WEIGHT_CONSTANT            (uint64_t(SMOKE_POST_MAX_BANDWIDTH) * SMOKE_POST_MAX_BANDWIDTH)

#define SMOKE_MAX_ACCOUNT_WITNESS_VOTES       30

#define SMOKE_100_PERCENT                     10000
#define SMOKE_1_PERCENT                       (SMOKE_100_PERCENT/100)
#define SMOKE_1_TENTH_PERCENT                 (SMOKE_100_PERCENT/1000)
#define SMOKE_DEFAULT_SBD_INTEREST_RATE       (10*SMOKE_1_PERCENT) ///< 10% APR

#define SMOKE_INFLATION_RATE_START_PERCENT    (978) // 9.5%
#define SMOKE_INFLATION_RATE_STOP_PERCENT     (487) // 4.87%
#define SMOKE_INFLATION_NARROWING_PERIOD      (250000) // Narrow 0.01% every 250k blocks
#define SMOKE_CONTENT_REWARD_PERCENT          (75*SMOKE_1_PERCENT) //75% of inflation, 7.125% inflation
#define SMOKE_VESTING_FUND_PERCENT            (15*SMOKE_1_PERCENT) //15% of inflation, 1.425% inflation

#define SMOKE_MINER_PAY_PERCENT               (SMOKE_1_PERCENT) // 1%
#define SMOKE_MIN_RATION                      100000
#define SMOKE_MAX_RATION_DECAY_RATE           (1000000)
#define SMOKE_FREE_TRANSACTIONS_WITH_NEW_ACCOUNT 100

#define SMOKE_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define SMOKE_BANDWIDTH_PRECISION             (uint64_t(1000000)) ///< 1 million
#define SMOKE_MAX_COMMENT_DEPTH_PRE_HF17      6
#define SMOKE_MAX_COMMENT_DEPTH               0xffff // 64k
#define SMOKE_SOFT_MAX_COMMENT_DEPTH          0xff // 255

#define SMOKE_MAX_RESERVE_RATIO               (20000)

#define SMOKE_CREATE_ACCOUNT_WITH_STEEM_MODIFIER 30
#define SMOKE_CREATE_ACCOUNT_DELEGATION_RATIO    5
#define SMOKE_CREATE_ACCOUNT_DELEGATION_TIME     fc::days(30)

#define SMOKE_MINING_REWARD                   asset( 1000, STEEM_SYMBOL )
#define SMOKE_EQUIHASH_N                      140
#define SMOKE_EQUIHASH_K                      6

#define SMOKE_LIQUIDITY_TIMEOUT_SEC           (fc::seconds(60*60*24*7)) // After one week volume is set to 0
#define SMOKE_MIN_LIQUIDITY_REWARD_PERIOD_SEC (fc::seconds(60)) // 1 minute required on books to receive volume
#define SMOKE_LIQUIDITY_REWARD_PERIOD_SEC     (60*60)
#define SMOKE_LIQUIDITY_REWARD_BLOCKS         (SMOKE_LIQUIDITY_REWARD_PERIOD_SEC/SMOKE_BLOCK_INTERVAL)
#define SMOKE_MIN_LIQUIDITY_REWARD            (asset( 1000*SMOKE_LIQUIDITY_REWARD_BLOCKS, STEEM_SYMBOL )) // Minumum reward to be paid out to liquidity providers
#define SMOKE_MIN_CONTENT_REWARD              SMOKE_MINING_REWARD
#define SMOKE_MIN_CURATE_REWARD               SMOKE_MINING_REWARD
#define SMOKE_MIN_PRODUCER_REWARD             SMOKE_MINING_REWARD
#define SMOKE_MIN_POW_REWARD                  SMOKE_MINING_REWARD

#define SMOKE_ACTIVE_CHALLENGE_FEE            asset( 2000, STEEM_SYMBOL )
#define SMOKE_OWNER_CHALLENGE_FEE             asset( 30000, STEEM_SYMBOL )
#define SMOKE_ACTIVE_CHALLENGE_COOLDOWN       fc::days(1)
#define SMOKE_OWNER_CHALLENGE_COOLDOWN        fc::days(1)

#define SMOKE_POST_REWARD_FUND_NAME           ("post")
#define SMOKE_COMMENT_REWARD_FUND_NAME        ("comment")
#define SMOKE_RECENT_RSHARES_DECAY_RATE_HF17  (fc::days(30))
#define SMOKE_RECENT_RSHARES_DECAY_RATE_HF19  (fc::days(15))
#define SMOKE_CONTENT_CONSTANT_HF0            (uint128_t(uint64_t(2000000000000ll)))
// note, if redefining these constants make sure calculate_claims doesn't overflow

// 5ccc e802 de5f
// int(expm1( log1p( 1 ) / BLOCKS_PER_YEAR ) * 2**SMOKE_APR_PERCENT_SHIFT_PER_BLOCK / 100000 + 0.5)
// we use 100000 here instead of 10000 because we end up creating an additional 9x for vesting
#define SMOKE_APR_PERCENT_MULTIPLY_PER_BLOCK          ( (uint64_t( 0x5ccc ) << 0x20) \
                                                        | (uint64_t( 0xe802 ) << 0x10) \
                                                        | (uint64_t( 0xde5f )        ) \
                                                        )
// chosen to be the maximal value such that SMOKE_APR_PERCENT_MULTIPLY_PER_BLOCK * 2**64 * 100000 < 2**128
#define SMOKE_APR_PERCENT_SHIFT_PER_BLOCK             87

#define SMOKE_APR_PERCENT_MULTIPLY_PER_ROUND          ( (uint64_t( 0x79cc ) << 0x20 ) \
                                                        | (uint64_t( 0xf5c7 ) << 0x10 ) \
                                                        | (uint64_t( 0x3480 )         ) \
                                                        )

#define SMOKE_APR_PERCENT_SHIFT_PER_ROUND             83

// We have different constants for hourly rewards
// i.e. hex(int(math.expm1( math.log1p( 1 ) / HOURS_PER_YEAR ) * 2**SMOKE_APR_PERCENT_SHIFT_PER_HOUR / 100000 + 0.5))
#define SMOKE_APR_PERCENT_MULTIPLY_PER_HOUR           ( (uint64_t( 0x6cc1 ) << 0x20) \
                                                        | (uint64_t( 0x39a1 ) << 0x10) \
                                                        | (uint64_t( 0x5cbd )        ) \
                                                        )

// chosen to be the maximal value such that SMOKE_APR_PERCENT_MULTIPLY_PER_HOUR * 2**64 * 100000 < 2**128
#define SMOKE_APR_PERCENT_SHIFT_PER_HOUR              77

// These constants add up to GRAPHENE_100_PERCENT.  Each GRAPHENE_1_PERCENT is equivalent to 1% per year APY
// *including the corresponding 9x vesting rewards*
#define SMOKE_CURATE_APR_PERCENT              3875
#define SMOKE_CONTENT_APR_PERCENT             3875
#define SMOKE_LIQUIDITY_APR_PERCENT            750
#define SMOKE_PRODUCER_APR_PERCENT             750
#define SMOKE_POW_APR_PERCENT                  750

#define SMOKE_MIN_PAYOUT_SBD                  (asset(20,SBD_SYMBOL))
#define SMOKE_MIN_PAYOUT_STEEM                20

#define SMOKE_SBD_STOP_PERCENT                (5*SMOKE_1_PERCENT ) // Stop printing SBD at 5% Market Cap
#define SMOKE_SBD_START_PERCENT               (2*SMOKE_1_PERCENT) // Start reducing printing of SBD at 2% Market Cap

#define SMOKE_MIN_ACCOUNT_NAME_LENGTH          3
#define SMOKE_MAX_ACCOUNT_NAME_LENGTH         16

#define SMOKE_MIN_PERMLINK_LENGTH             0
#define SMOKE_MAX_PERMLINK_LENGTH             256
#define SMOKE_MAX_WITNESS_URL_LENGTH          2048

#define SMOKE_INIT_SUPPLY                     int64_t(42000000000ll) // 42m SMOKE
#define SMOKE_MAX_SHARE_SUPPLY                int64_t(1000000000000000ll)
#define SMOKE_MAX_SIG_CHECK_DEPTH             2

#define SMOKE_MIN_TRANSACTION_SIZE_LIMIT      1024
#define SMOKE_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

#define SMOKE_SBD_INTEREST_COMPOUND_INTERVAL_SEC  (60*60*24*30)
#define SMOKE_MAX_TRANSACTION_SIZE            (1024*64)
#define SMOKE_MIN_BLOCK_SIZE_LIMIT            (SMOKE_MAX_TRANSACTION_SIZE)
#define SMOKE_MAX_BLOCK_SIZE                  (SMOKE_MAX_TRANSACTION_SIZE*SMOKE_BLOCK_INTERVAL*2000)
#define SMOKE_SOFT_MAX_BLOCK_SIZE             (2*1024*1024)
#define SMOKE_MIN_BLOCK_SIZE                  115
#define SMOKE_BLOCKS_PER_HOUR                 (60*60/SMOKE_BLOCK_INTERVAL)
#define SMOKE_FEED_INTERVAL_BLOCKS            (SMOKE_BLOCKS_PER_HOUR)
//#define SMOKE_FEED_INTERVAL_BLOCKS            (120)
#define SMOKE_FEED_HISTORY_WINDOW_PRE_HF_16   (24*7) /// 7 days * 24 hours per day
//#define SMOKE_FEED_HISTORY_WINDOW_PRE_HF_16   (1)
#define SMOKE_FEED_HISTORY_WINDOW             (12*7) // 3.5 days
//#define SMOKE_FEED_HISTORY_WINDOW             (1) // 1h
//#define SMOKE_MAX_FEED_AGE_SECONDS            (60*60*24*7) // 7 days
#define SMOKE_MAX_FEED_AGE_SECONDS            (60*60*24*365*10) // 10 years
#define SMOKE_MIN_FEEDS                       (SMOKE_MAX_WITNESSES/3) /// protects the network from conversions before price has been established
//#define SMOKE_MIN_FEEDS                       (1) /// protects the network from conversions before price has been established
#define SMOKE_CONVERSION_DELAY_PRE_HF_16      (fc::days(7))
#define SMOKE_CONVERSION_DELAY                (fc::hours(SMOKE_FEED_HISTORY_WINDOW)) //3.5 day conversion

#define SMOKE_MIN_UNDO_HISTORY                10
#define SMOKE_MAX_UNDO_HISTORY                10000

#define SMOKE_MIN_TRANSACTION_EXPIRATION_LIMIT (SMOKE_BLOCK_INTERVAL * 5) // 5 transactions per block
#define SMOKE_BLOCKCHAIN_PRECISION            uint64_t( 1000 )

#define SMOKE_BLOCKCHAIN_PRECISION_DIGITS     3
#define SMOKE_MAX_INSTANCE_ID                 (uint64_t(-1)>>16)
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define SMOKE_MAX_AUTHORITY_MEMBERSHIP        10
#define SMOKE_MAX_ASSET_WHITELIST_AUTHORITIES 10
#define SMOKE_MAX_URL_LENGTH                  127

#define SMOKE_IRREVERSIBLE_THRESHOLD          (75 * SMOKE_1_PERCENT)

#define VIRTUAL_SCHEDULE_LAP_LENGTH  ( fc::uint128(uint64_t(-1)) )
#define VIRTUAL_SCHEDULE_LAP_LENGTH2 ( fc::uint128::max_value() )

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current witnesses
#define SMOKE_MINER_ACCOUNT                   "miners"
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define SMOKE_NULL_ACCOUNT                    "null"
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define SMOKE_TEMP_ACCOUNT                    "temp"
/// Represents the canonical account for specifying you will vote for directly (as opposed to a proxy)
#define SMOKE_PROXY_TO_SELF_ACCOUNT           ""
/// Represents the canonical root post parent account
#define SMOKE_ROOT_POST_PARENT                (account_name_type())
///@}
