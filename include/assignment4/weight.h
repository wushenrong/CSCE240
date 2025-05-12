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

#include <string>
#include <string_view>

/**
 * A class to represent how much an object weights in pounds, ounces, kilograms,
 * or grams.
 */
class Weight {
 private:
  double value_;
  std::string units_;

 public:
  explicit Weight(double value = 0.0, std::string_view units = "pounds");

  double GetValue() const { return value_; }
  std::string GetUnits() const { return units_; }

  void SetValue(double);
  void SetUnits(std::string_view);

  /**
   * Operator overloads for comparing weights.
   */
  bool operator<=(Weight) const;
  bool operator>=(Weight) const;
  bool operator>(Weight) const;

  /**
   * Convert the current weight to pounds, ounces, kilograms, or grams.
   */
  void ConvertUnits(std::string_view units);
};

std::ostream& operator<<(std::ostream&, const Weight&);

#endif  // ASSIGNMENT4_WEIGHT_H_
