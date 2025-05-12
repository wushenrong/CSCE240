/**
 * @file weight.cc
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "assignment4/weight.h"

#include <iostream>
#include <string_view>
#include <utility>

using std::string_view;

constexpr double POUNDS_OUNCES_RATIO{16};
constexpr double POUNDS_KILOGRAMS_RATIO{2.20462262};
constexpr double POUNDS_GRAMS_RATIO{453.59237};

constexpr double OUNCES_KILOGRAMS_RATIO{35.273962};
constexpr double OUNCES_GRAMS_RATIO{28.3495231};

constexpr double KILOGRAMS_GRAMS_RATIO{1000};

Weight::Weight(double value, string_view units) : value_{0}, units_{"pounds"} {
  SetValue(value);
  SetUnits(units);
}

auto Weight::SetValue(double value) -> void {
  if (value >= 0) {
    value_ = value;
  }
}

auto Weight::SetUnits(string_view units) -> void {
  if (units == "pounds" || units == "ounces" || units == "kilograms" ||
      units == "grams") {
    units_ = units;
  }
}

auto Weight::operator<=(Weight rhs) const -> bool {
  rhs.ConvertUnits(units_);
  return value_ <= rhs.value_;
}

auto Weight::operator>=(Weight rhs) const -> bool {
  rhs.ConvertUnits(units_);
  return value_ >= rhs.value_;
}

auto Weight::operator>(Weight rhs) const -> bool {
  return !(operator<=(std::move(rhs)));
}

/**
 * Converts the current weight to pounds, ounces, kilograms, or grams by
 * multiplying or dividing the ratio between the units.
 */
void Weight::ConvertUnits(string_view units) {
  if (units == "pounds") {
    if (units_ == "ounces") {
      units_ = units;
      value_ /= POUNDS_OUNCES_RATIO;
    } else if (units_ == "kilograms") {
      units_ = units;
      value_ *= POUNDS_KILOGRAMS_RATIO;
    } else if (units_ == "grams") {
      units_ = units;
      value_ /= POUNDS_GRAMS_RATIO;
    }
  } else if (units == "ounces") {
    if (units_ == "pounds") {
      units_ = units;
      value_ *= POUNDS_OUNCES_RATIO;
    } else if (units_ == "kilograms") {
      units_ = units;
      value_ *= OUNCES_KILOGRAMS_RATIO;
    } else if (units_ == "grams") {
      units_ = units;
      value_ /= OUNCES_GRAMS_RATIO;
    }
  } else if (units == "kilograms") {
    if (units_ == "pounds") {
      units_ = units;
      value_ /= POUNDS_KILOGRAMS_RATIO;
    } else if (units_ == "ounces") {
      units_ = units;
      value_ /= OUNCES_KILOGRAMS_RATIO;
    } else if (units_ == "grams") {
      units_ = units;
      value_ /= KILOGRAMS_GRAMS_RATIO;
    }
  } else if (units == "grams") {
    if (units_ == "pounds") {
      units_ = units;
      value_ *= POUNDS_GRAMS_RATIO;
    } else if (units_ == "ounces") {
      units_ = units;
      value_ *= OUNCES_GRAMS_RATIO;
    } else if (units_ == "kilograms") {
      units_ = units;
      value_ *= KILOGRAMS_GRAMS_RATIO;
    }
  }
}

auto operator<<(std::ostream& out, const Weight& weight) -> std::ostream& {
  return out << weight.GetValue() << ' ' << weight.GetUnits();
}
