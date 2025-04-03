/*
 * Copyright 2025 Samuel Wu
 */

#ifndef ASSIGNMENT4_WEIGHTRANGE_H_
#define ASSIGNMENT4_WEIGHTRANGE_H_

#include "./weight.h"

/**
 * A class to represent the range of a weight that is allowed.
 */
class WeightRange {
  friend std::ostream& operator<<(std::ostream&, const WeightRange&);

 public:
  WeightRange() = default;
  WeightRange(const Weight&, const Weight&);

  Weight GetSmallest() const { return small_; }
  Weight GetLargest() const { return large_; }

  void SetSmallest(const Weight&);
  void SetLargest(const Weight&);

  /**
   * Check if a given weight is in the weight range. If isClosed is false, then
   * the end points of the range is excluded.
   */
  bool InRange(const Weight&, bool isClosed = true);

  /**
   * Return the difference of the largest weight and the smallest weight.
   */
  Weight Width();

 private:
  Weight small_;
  Weight large_;
};

#endif  // ASSIGNMENT4_WEIGHTRANGE_H_
