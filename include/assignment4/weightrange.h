/**
 * @file weightrange.h
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ASSIGNMENT4_WEIGHTRANGE_H_
#define ASSIGNMENT4_WEIGHTRANGE_H_

#include <iosfwd>

#include "assignment4/weight.h"

/**
 * A class to represent the range of a weight that is allowed.
 */
class WeightRange {
 private:
  Weight small_;
  Weight large_;

 public:
  WeightRange();
  WeightRange(const Weight& small, const Weight& large);

  Weight GetSmallest() const { return small_; }
  Weight GetLargest() const { return large_; }

  void SetSmallest(const Weight&);
  void SetLargest(const Weight&);

  /**
   * Check if a given weight is in the weight range.
   *
   * @param isClosed Include the smallest and largest weight as a part of the
   *    weight range.
   * @return true if the weight is in the range, otherwise false.
   */
  bool InRange(const Weight&, bool isClosed = true) const;

  /**
   * @return Difference of the largest weight and the smallest weight.
   */
  Weight Width();
};

std::ostream& operator<<(std::ostream&, const WeightRange&);

#endif  // ASSIGNMENT4_WEIGHTRANGE_H_
