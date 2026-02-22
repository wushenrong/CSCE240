/**
 * @file program1.cc
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <cmath>
#include <gsl-lite/gsl-lite.hpp>
#include <iostream>

using std::cin;

// Set the radix/base we are converting to, which is base 10
constexpr int kRadix{10};

static const char* get_position_ending(int position) {
  if ((position / kRadix) % kRadix == 1) {
    return "th";
  }

  switch (position % kRadix) {
    case 1:
      return "st";
    case 2:
      return "nd";
    case 3:
      return "rd";
    default:
      return "th";
  }
}

int main() {
  // Variables for number of inputs and the largest input
  int num_values{};
  int largest_value_index{1};
  int largest_value{};

  // Variables to get values from stdin/cin
  int number{};
  int base{};
  char have_more_numbers{'y'};

  while (have_more_numbers == 'y') {
    cin >> number >> base >> have_more_numbers;

    // Reject value if the base is not 2 to 9 inclusive
    if (base < 2 || base >= kRadix) {
      std::cout << "Base Not Accepted\n";
      return 1;
    }

    int converted_value{};
    bool negative{};

    // Check if the value inputted is negative and make the value positive.
    if (number < 0) {
      negative = true;
      number *= -1;
    }

    int current_position{1};

    // Convert the value from base n to base 10 from right to left
    while (number > 0) {
      const int digit{number % kRadix};

      // Reject value if the current digit is not in base n
      if (digit >= base) {
        std::cout << "Invalid Digit(s) in Number\n";
        return 1;
      }

      converted_value +=
          gsl_lite::narrow_cast<int>(digit * std::pow(base, current_position));
      number /= kRadix;
      ++current_position;
    }  // End of inner while loop

    // If the value was negative, make the converted value negative
    if (negative) {
      converted_value *= -1;
    }

    std::cout << converted_value;

    ++num_values;

    if (converted_value > largest_value) {
      largest_value = converted_value;
      largest_value_index = num_values;
    }
  }  // End of outer while loop

  std::cout << "Of the " << num_values << " values input, the "
            << largest_value_index << get_position_ending(largest_value_index)
            << " value entered (" << largest_value << ") was the largest.\n";

  return 0;
}
