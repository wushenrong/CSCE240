/**
 * @file weight.h
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ASSIGNMENT4_WEIGHT_H_
#define ASSIGNMENT4_WEIGHT_H_

#include <iosfwd>
#include <string>
#include <string_view>

#include "program4functions_export.h"

/**
 * A class to represent how much an object weights in pounds, ounces, kilograms,
 * or grams.
 */
class Weight {
 private:
  double value_;
  std::string units_;

 public:
  PROGRAM4FUNCTIONS_EXPORT explicit Weight(double value = 0.0,
                                           std::string_view units = "pounds");

  PROGRAM4FUNCTIONS_EXPORT double GetValue() const { return value_; }
  PROGRAM4FUNCTIONS_EXPORT std::string GetUnits() const { return units_; }

  PROGRAM4FUNCTIONS_EXPORT void SetValue(double);
  PROGRAM4FUNCTIONS_EXPORT void SetUnits(std::string_view);

  /**
   * Operator overloads for comparing weights.
   */
  PROGRAM4FUNCTIONS_EXPORT bool operator<=(Weight) const;
  PROGRAM4FUNCTIONS_EXPORT bool operator>=(Weight) const;
  PROGRAM4FUNCTIONS_EXPORT bool operator>(Weight) const;
  PROGRAM4FUNCTIONS_EXPORT bool operator<(Weight) const;

  /**
   * Convert the current weight to pounds, ounces, kilograms, or grams.
   */
  PROGRAM4FUNCTIONS_EXPORT void ConvertUnits(std::string_view units);
};

PROGRAM4FUNCTIONS_EXPORT std::ostream& operator<<(std::ostream&, const Weight&);

#endif  // ASSIGNMENT4_WEIGHT_H_
