/**
 * @file weightrange.cc
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "assignment4/weightrange.h"

#include <iostream>

#include "assignment4/weight.h"

WeightRange::WeightRange() : small_{0}, large_{0} {}

WeightRange::WeightRange(const Weight& small, const Weight& large)
    : small_{small}, large_{large} {
  if (small > large) {
    small_ = large;
    large_ = small;
  }
}

void WeightRange::SetSmallest(const Weight& weight) {
  if (weight <= large_) {
    small_ = weight;
  }
}

void WeightRange::SetLargest(const Weight& weight) {
  if (weight >= small_) {
    large_ = weight;
  }
}

/**
 * Checks if a given weight is in the weight range by comparing if the width
 * is smaller than the large weight and is larger than the small weight.
 * If isClosed is false, the weights are not included in the range.
 */
auto WeightRange::InRange(const Weight& weight, bool isClosed) -> bool {
  return isClosed ? (large_ >= weight) && (weight >= small_)
                  : (large_ > weight) && (weight > small_);
}

/**
 * Get the difference of the weight range by converting the small weight to
 * the same units as the large weight. Then return a new weight that contains
 * the difference of the large and the small weigh in the same units as the
 * large weight.
 */
auto WeightRange::Width() -> Weight {
  small_.ConvertUnits(large_.GetUnits());
  return Weight(large_.GetValue() - small_.GetValue(), large_.GetUnits());
}

auto operator<<(std::ostream& out, const WeightRange& weight) -> std::ostream& {
  return out << weight.GetSmallest() << " - " << weight.GetLargest();
}
