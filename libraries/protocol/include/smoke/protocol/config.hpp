/*
 * Copyright (c) 2016 Steemit, Inc., and contributors.
 */
#pragma once

#define SMOKE_BLOCKCHAIN_VERSION              ( version(0, 0, 0) )
#define SMOKE_BLOCKCHAIN_HARDFORK_VERSION     ( hardfork_version( SMOKE_BLOCKCHAIN_VERSION ) )

#ifdef IS_TEST_NET
#define SMOKE_INIT_PRIVATE_KEY                (fc::ecc::private_key::regenerate(fc::sha256::hash(std::string("init_key"))))
#define SMOKE_INIT_PUBLIC_KEY_STR             (std::string( smoke::protocol::public_key_type(SMOKE_INIT_PRIVATE_KEY.get_public_key()) ))
#define SMOKE_CHAIN_ID                        (fc::sha256::hash("testnet"))

#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define SMOKE_SYMBOL  (uint64_t(3) | (uint64_t('T') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< TESTS with 3 digits of precision

#define SMOKE_SYMBOL_STR                      "TESTS"
#define SMOKE_ADDRESS_PREFIX                  "TST"

#define SMOKE_GENESIS_TIME                    (fc::time_point_sec(1515765200))
#define SMOKE_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define SMOKE_UPVOTE_LOCKOUT                  (fc::minutes(5))

#define SMOKE_MIN_ACCOUNT_CREATION_FEE          0

#define SMOKE_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define SMOKE_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define SMOKE_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define SMOKE_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1
#else // IS LIVE SMOKE NETWORK

#define SMOKE_INIT_PUBLIC_KEY_STR             "SMK6EC5NtQBvLRJ1m3Fs4GQpH4fnZZq4M1sDSnDfTKdLfqB2aoSV9"
#define SMOKE_CHAIN_ID                        (fc::sha256::hash("smoke")) // a66e00caa50e6817bbe24e927bf48c5d4ba1b33f36bdbb5fa262a04012c4e3ee
#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define SMOKE_SYMBOL  (uint64_t(3) | (uint64_t('S') << 8) | (uint64_t('M') << 16) | (uint64_t('O') << 24) | (uint64_t('K') << 32) | (uint64_t('E') << 40)) ///< SMOKE with 3 digits of precision
#define SMOKE_SYMBOL_STR                      "SMOKE"
#define SMOKE_ADDRESS_PREFIX                  "SMK"

#define SMOKE_GENESIS_TIME_EPOCH              1533055724  // Tue Jul 31 2018 23:48:44 GMT+0700 (Indochina Time)
#define SMOKE_GENESIS_TIME                    (fc::time_point_sec(SMOKE_GENESIS_TIME_EPOCH))
#define SMOKE_CASHOUT_WINDOW_SECONDS          (60*60*24*7)  /// 7 days
#define SMOKE_UPVOTE_LOCKOUT                  (fc::hours(12))

#define SMOKE_MIN_ACCOUNT_CREATION_FEE         4200 // 4.2 SMOKE

#define SMOKE_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
#define SMOKE_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define SMOKE_OWNER_UPDATE_LIMIT                          fc::minutes(60)
#define SMOKE_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1 // 3186477

#endif

#define SMOKE_BLOCK_INTERVAL                  3
#define SMOKE_BLOCKS_PER_YEAR                 (365*24*60*60/SMOKE_BLOCK_INTERVAL)
#define SMOKE_BLOCKS_PER_DAY                  (24*60*60/SMOKE_BLOCK_INTERVAL)
#define SMOKE_START_MINER_VOTING_BLOCK        (1 * 30) // (SMOKE_BLOCKS_PER_DAY * 30)

#define SMOKE_MAX_WITNESSES                   21

#define SMOKE_INIT_MINER_NAME                 "initminer"

#define SMOKE_MAX_VOTED_WITNESSES             20
#define SMOKE_MAX_MINER_WITNESSES             0
#define SMOKE_MAX_RUNNER_WITNESSES            1

#define SMOKE_HARDFORK_REQUIRED_WITNESSES     17 // 17 of the 21 dpos witnesses (20 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.
#define SMOKE_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define SMOKE_MAX_MEMO_SIZE                   2048
#define SMOKE_MAX_PROXY_RECURSION_DEPTH       4
#define SMOKE_VESTING_WITHDRAW_INTERVALS      13
#define SMOKE_VESTING_WITHDRAW_INTERVAL_SECONDS (60*60*24*7) /// 1 week per interval

#define SMOKE_MAX_WITHDRAW_ROUTES             10
#define SMOKE_VOTE_REGENERATION_SECONDS       (5*60*60*24) // 5 day
#define SMOKE_MAX_VOTE_CHANGES                5
#define SMOKE_REVERSE_AUCTION_WINDOW_SECONDS  (60*30) /// 30 minutes
#define SMOKE_MIN_VOTE_INTERVAL_SEC           3
#define SMOKE_VOTE_DUST_THRESHOLD             (32000) // make sure new user with 4.2 SMOKE in VESTS be able to vote

#define SMOKE_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(60*5)) // 5 minutes
#define SMOKE_MIN_REPLY_INTERVAL              (fc::seconds(20)) // 20 seconds

#define SMOKE_MAX_ACCOUNT_WITNESS_VOTES       30

#define SMOKE_100_PERCENT                     10000
#define SMOKE_1_PERCENT                       (SMOKE_100_PERCENT/100)
#define SMOKE_1_TENTH_PERCENT                 (SMOKE_100_PERCENT/1000)

#define SMOKE_INFLATION_RATE_START_PERCENT    (978) // 9.5%
#define SMOKE_INFLATION_RATE_STOP_PERCENT     (487) // 4.87%
#define SMOKE_INFLATION_NARROWING_PERIOD      (250000) // Narrow 0.01% every 250k blocks
#define SMOKE_CONTENT_REWARD_PERCENT          (75*SMOKE_1_PERCENT) //75% of inflation, 7.125% inflation
#define SMOKE_VESTING_FUND_PERCENT            (15*SMOKE_1_PERCENT) //15% of inflation, 1.425% inflation

#define SMOKE_CONTENT_CURATE_REWARD_PERCENT   (50*SMOKE_1_PERCENT) // % of SMOKE_CONTENT_REWARD_PERCENT only

#define SMOKE_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define SMOKE_BANDWIDTH_PRECISION             (uint64_t(1000000)) ///< 1 million
#define SMOKE_MAX_COMMENT_DEPTH               0xffff // 64k
#define SMOKE_SOFT_MAX_COMMENT_DEPTH          0xff // 255

#define SMOKE_MAX_RESERVE_RATIO               (20000)

#define SMOKE_CREATE_ACCOUNT_WITH_STEEM_MODIFIER 30
#define SMOKE_CREATE_ACCOUNT_DELEGATION_RATIO    5
#define SMOKE_CREATE_ACCOUNT_DELEGATION_TIME     fc::days(30)

#define SMOKE_EQUIHASH_N                      140
#define SMOKE_EQUIHASH_K                      6

#define SMOKE_ACTIVE_CHALLENGE_FEE            asset( 2000, SMOKE_SYMBOL )
#define SMOKE_OWNER_CHALLENGE_FEE             asset( 30000, SMOKE_SYMBOL )

#define SMOKE_POST_REWARD_FUND_NAME           ("post")
#define SMOKE_RECENT_RSHARES_DECAY_RATE       (fc::days(15))
#define SMOKE_CONTENT_CONSTANT                (uint128_t(uint64_t(2000000000000ll)))

#define SMOKE_MIN_PAYOUT_STEEM                20
#define SMOKE_MIN_ACCOUNT_NAME_LENGTH          3
#define SMOKE_MAX_ACCOUNT_NAME_LENGTH         16

#define SMOKE_MIN_PERMLINK_LENGTH             0
#define SMOKE_MAX_PERMLINK_LENGTH             256
#define SMOKE_MAX_WITNESS_URL_LENGTH          2048

#define SMOKE_INIT_SUPPLY                     int64_t(42000000000ll) // 42m SMOKE
#define SMOKE_MAX_SHARE_SUPPLY                int64_t(1000000000000000ll)
#define SMOKE_MAX_SIG_CHECK_DEPTH             2

#define SMOKE_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

#define SMOKE_MAX_TRANSACTION_SIZE            (1024*64)
#define SMOKE_MIN_BLOCK_SIZE_LIMIT            (SMOKE_MAX_TRANSACTION_SIZE)
#define SMOKE_MAX_BLOCK_SIZE                  (SMOKE_MAX_TRANSACTION_SIZE*SMOKE_BLOCK_INTERVAL*2000)
#define SMOKE_SOFT_MAX_BLOCK_SIZE             (2*1024*1024)
#define SMOKE_MIN_BLOCK_SIZE                  115
#define SMOKE_BLOCKS_PER_HOUR                 (60*60/SMOKE_BLOCK_INTERVAL)
#define SMOKE_MIN_UNDO_HISTORY                10
#define SMOKE_MAX_UNDO_HISTORY                10000

#define SMOKE_MIN_TRANSACTION_EXPIRATION_LIMIT (SMOKE_BLOCK_INTERVAL * 5) // 5 transactions per block

#define SMOKE_IRREVERSIBLE_THRESHOLD          (75 * SMOKE_1_PERCENT)
#define VIRTUAL_SCHEDULE_LAP_LENGTH           ( fc::uint128::max_value() )

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

#define SMOKE_SMOKE_ACCOUNT                   "smoke"