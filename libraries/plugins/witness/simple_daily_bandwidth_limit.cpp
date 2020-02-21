#include <smoke/witness/simple_daily_bandwidth_limit.hpp>
#include <smoke/chain/database_exceptions.hpp>

namespace smoke {
namespace witness {

int64_t stakeRanges[] = {
    1000,           // 0: 1
    10000,          // 1: 10
    100000,         // 2: 100
    1000000,        // 3: 1K
    10000000,       // 4: 10K
    100000000,      // 5: 100K
    1000000000,     // 6: 1M
    10000000000,    // 7: 10M
    100000000000,   // 8: 100M
    1000000000000,  // 9: 1B
};

/**
 * base bandwidth 4KB + additional bandwidth depending on STAKED
 *
 * range (vesting) daily_bandwidth (KB)
 * 10 (> 1B    STAKED): 1024
 *  9 (> 100M  STAKED): 512
 *  8 (> 10    STAKED): 256
 *  7 (> 1M    STAKED): 128
 *  6 (> 100K  STAKED): 64
 *  5 (> 10K   STAKED): 32
 *  4 (> 1K    STAKED): 16
 *  3 (> 100   STAKED): 8
 *  2 (> 10    STAKED): 4
 *  1 (> 1     STAKED): 2
 *  0 (< 1     STAKED): 1
 *
 * @param stake
 * @return
 */
int64_t simple_daily_bandwidth_limit(int64_t stake) {
  int64_t range = 0;

  if (stake >= stakeRanges[8]) {         // 100M
    range = 9;
  } else if (stake >= stakeRanges[7]) {  // 10M
    range = 8;
  } else if (stake >= stakeRanges[6]) {  // 1M
    range = 7;
  } else if (stake >= stakeRanges[5]) {  // 100K
    range = 6;
  } else if (stake >= stakeRanges[4]) {  // 10K
    range = 5;
  } else if (stake >= stakeRanges[3]) {  // 1K
    range = 4;
  } else if (stake >= stakeRanges[2]) {  // 100
    range = 3;
  } else if (stake >= stakeRanges[1]) {  // 10
    range = 2;
  } else if (stake >= stakeRanges[0]) {  // 1
    range = 1;
  } else {
    range = 0;
  }

  // return min/max if range = 0 or 9 here
  if (range >= 9) {
    return BASE_BANDWIDTH + 512*1024;
  } else if (range <= 0) {
    return BASE_BANDWIDTH + 1024; // make sure everyone has a minimum daily bandwidth
  }

  int64_t max_threshold = 1024 * (uint16_t(1) << (range + 1));
  int64_t min_threshold = max_threshold/2;
  int64_t bw_range = max_threshold - min_threshold;

  int64_t max_stake = stakeRanges[range];
  int64_t min_stake = stakeRanges[range - 1];
  int64_t stake_range = max_stake - min_stake;
  //  ilog("max_threshold=${max_threshold}, min_threshold=${min_threshold}, bw_range=${bw_range}, stake_range=${stake_range}",
  //       ("max_threshold", max_threshold)("min_threshold", min_threshold)("bw_range", bw_range)("stake_range", stake_range));
  SMOKE_ASSERT(stake_range > 0, smoke::chain::plugin_exception, "stake_range must > 0");
  int64_t daily_limit = ((stake - min_stake) * bw_range / stake_range) + min_threshold;

  return BASE_BANDWIDTH + daily_limit;
}


}  // namespace witness
}  // namespace smoke
