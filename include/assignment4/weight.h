/*
 * Copyright 2025 Samuel Wu
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
  friend std::ostream& operator<<(std::ostream&, const Weight&);

 public:
  explicit Weight(double value = 0, std::string_view units_ = "pounds");

  void SetValue(double value);
  void SetUnits(std::string_view units);

  double GetValue() const { return value_; }
  std::string GetUnits() const { return units_; }

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

 private:
  double value_;
  std::string units_;
};

#endif  // ASSIGNMENT4_WEIGHT_H_
