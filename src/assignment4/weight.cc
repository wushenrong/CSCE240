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

#include <ostream>
#include <stdexcept>
#include <string>
#include <string_view>

using std::string_view;

constexpr double kPoundsToOuncesRatio{16};
constexpr double kPoundsToKilogramsRatio{0.45359237};
constexpr double kPoundsToGramsRatio{453.59237};

constexpr double kOuncesToPoundsRatio{0.0625};
constexpr double kOuncesToKilogramsRatio{0.02834952};
constexpr double kOuncesToGramsRatio{28.3495231};

constexpr double kKilogramsToPoundsRatio{2.20462262};
constexpr double kKilogramsToOuncesRatio{35.273962};
constexpr double kKilogramsToGramsRatio{1000};

constexpr double kGramsToPoundsRatio{0.00220462};
constexpr double kGramsToOuncesRatio{0.03527396};
constexpr double kGramsToKilogramsRatio{0.001};

inline static bool IsValidUnit(string_view units) {
  return units == "pounds" || units == "ounces" || units == "kilograms" ||
         units == "grams";
}

Weight::Weight(double value, string_view units) : value_{value}, units_{units} {
  if (value < 0) {
    throw std::invalid_argument{"Value cannot be negative"};
  }

  if (!IsValidUnit(units)) {
    throw std::invalid_argument{"Units is unsupported"};
  }
}

void Weight::SetValue(double value) {
  if (value >= 0) {
    value_ = value;
  }
}

void Weight::SetUnits(string_view units) {
  if (IsValidUnit(units)) {
    units_ = units;
  }
}

/**
 * Converts the current weight to pounds, ounces, kilograms, or grams by
 * multiplying or dividing the ratio between the units.
 */
void Weight::ConvertUnits(string_view units) {
  if (units == "pounds") {
    if (units_ == "ounces") {
      units_ = units;
      value_ *= kOuncesToPoundsRatio;
    } else if (units_ == "kilograms") {
      units_ = units;
      value_ *= kKilogramsToPoundsRatio;
    } else if (units_ == "grams") {
      units_ = units;
      value_ *= kGramsToPoundsRatio;
    }
  } else if (units == "ounces") {
    if (units_ == "pounds") {
      units_ = units;
      value_ *= kPoundsToOuncesRatio;
    } else if (units_ == "kilograms") {
      units_ = units;
      value_ *= kKilogramsToOuncesRatio;
    } else if (units_ == "grams") {
      units_ = units;
      value_ *= kGramsToOuncesRatio;
    }
  } else if (units == "kilograms") {
    if (units_ == "pounds") {
      units_ = units;
      value_ *= kPoundsToKilogramsRatio;
    } else if (units_ == "ounces") {
      units_ = units;
      value_ *= kOuncesToKilogramsRatio;
    } else if (units_ == "grams") {
      units_ = units;
      value_ *= kGramsToKilogramsRatio;
    }
  } else if (units == "grams") {
    if (units_ == "pounds") {
      units_ = units;
      value_ *= kPoundsToGramsRatio;
    } else if (units_ == "ounces") {
      units_ = units;
      value_ *= kOuncesToGramsRatio;
    } else if (units_ == "kilograms") {
      units_ = units;
      value_ *= kKilogramsToGramsRatio;
    }
  }
}

std::ostream& operator<<(std::ostream& out, const Weight& weight) {
  return out << weight.GetValue() << ' ' << weight.GetUnits();
}
