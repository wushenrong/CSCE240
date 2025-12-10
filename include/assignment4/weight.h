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

#include <compare>
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
  PROGRAM4FUNCTIONS_EXPORT
  explicit Weight(double value = 0.0, std::string_view units = "pounds");

  [[nodiscard]]
  PROGRAM4FUNCTIONS_EXPORT auto GetValue() const -> double {
    return value_;
  }
  [[nodiscard]]
  auto GetUnits() const -> PROGRAM4FUNCTIONS_EXPORT const std::string& {
    return units_;
  }

  PROGRAM4FUNCTIONS_EXPORT
  void SetValue(double value);
  PROGRAM4FUNCTIONS_EXPORT
  void SetUnits(std::string_view units);

  /**
   * Operator overloads for comparing weights.
   */
  PROGRAM4FUNCTIONS_EXPORT
  friend auto operator<=>(const Weight& lhs, const Weight& rhs)
      -> std::partial_ordering {
    Weight weight{rhs};
    weight.ConvertUnits(lhs.units_);
    return lhs.value_ <=> weight.value_;
  };

  /**
   * Convert the current weight to pounds, ounces, kilograms, or grams.
   */
  PROGRAM4FUNCTIONS_EXPORT
  void ConvertUnits(std::string_view units);
};

PROGRAM4FUNCTIONS_EXPORT
auto operator<<(std::ostream&, const Weight&) -> std::ostream&;

#endif  // ASSIGNMENT4_WEIGHT_H_
