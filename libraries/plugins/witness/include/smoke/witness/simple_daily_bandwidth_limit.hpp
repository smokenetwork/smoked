#pragma once

#include <cstdint>

namespace smoke {
namespace witness {

#define BASE_BANDWIDTH ((int64_t)(1024 * 4))

/**
 * simple daily bw based on SP:
 * - break into ranges based on log10 scale (0-10, 10-100, 100-1K...)
 * - then find the max-threshold in linear within that range.
 */
int64_t simple_daily_bandwidth_limit(int64_t stake);


}  // namespace witness
}  // namespace smoke
