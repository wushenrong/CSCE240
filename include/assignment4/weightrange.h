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
#include "program4functions_export.h"

/**
 * A class to represent the range of a weight that is allowed.
 */
class WeightRange {
 private:
  Weight small_;
  Weight large_;

 public:
  PROGRAM4FUNCTIONS_EXPORT
  WeightRange(const Weight& small, const Weight& large);

  [[nodiscard]]
  PROGRAM4FUNCTIONS_EXPORT Weight GetSmallest() const {
    return small_;
  }
  [[nodiscard]]
  PROGRAM4FUNCTIONS_EXPORT Weight GetLargest() const {
    return large_;
  }

  PROGRAM4FUNCTIONS_EXPORT
  void SetSmallest(const Weight&);
  PROGRAM4FUNCTIONS_EXPORT
  void SetLargest(const Weight&);

  /**
   * Check if a given weight is in the weight range.
   *
   * @param isClosed Include the smallest and largest weight as a part of the
   *    weight range.
   * @return true if the weight is in the range, otherwise false.
   */
  [[nodiscard]]
  PROGRAM4FUNCTIONS_EXPORT bool InRange(const Weight&,
                                        bool isClosed = true) const;

  /**
   * @return Difference of the largest weight and the smallest weight.
   */
  PROGRAM4FUNCTIONS_EXPORT
  const Weight Width() const;
};

PROGRAM4FUNCTIONS_EXPORT
std::ostream& operator<<(std::ostream&, const WeightRange&);

#endif  // ASSIGNMENT4_WEIGHTRANGE_H_
