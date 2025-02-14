/*
 * Copyright 2025 Samuel Wu
 */

#include <iostream>

using std::cin;
using std::cout;

int main() {
  // Set the radix/base we are converting to, which is base 10
  constexpr int radix{10};

  // Variables for number of inputs and the largest input
  int number_of_values{0};
  int position_of_largest_value{1};
  int largest_value{0};

  // Variables to get values from stdin/cin
  int number{};
  int base{};
  char more_numbers{'y'};

  while (more_numbers == 'y') {
    cin >> number >> base >> more_numbers;

    // Reject value if the base is not 2 to 9 inclusive
    if (base < 2 || base >= radix) {
      cout << "Base Not Accepted" << '\n';
      return 0;
    }

    int converted_number = 0;

    bool negative = false;

    // Check if the value inputted is negative and make the value positive.
    if (number < 0) {
      negative = true;
      number *= -1;
    }

    int current_base_exponentiation = 1;

    // Convert the value from base n to base 10 from right to left
    while (number > 0) {
      int current_digit = number % radix;

      // Reject value if the current digit is not in base n
      if (current_digit >= base) {
        cout << "Invalid Digit(s) in Number" << '\n';
        return 0;
      }

      converted_number += current_digit * current_base_exponentiation;
      number /= radix;
      current_base_exponentiation *= base;
    }  // End of inner while loop

    // If the value was negative, make the converted value negative
    if (negative) {
      converted_number *= -1;
    }

    cout << converted_number << '\n';

    ++number_of_values;
    if (number_of_values < 2) {
      largest_value = converted_number;
    } else if (converted_number > largest_value) {
      largest_value = converted_number;
      position_of_largest_value = number_of_values;
    }
  }  // End of outer while loop

  cout << "Of the " << number_of_values << " values input, the "
       << position_of_largest_value;

  // Make sure 11th, 12th, and 13th is correctly outputted
  bool is_position_a_10s_position =
      (position_of_largest_value / radix) % radix == 1;

  if (!is_position_a_10s_position) {
    switch (position_of_largest_value % radix) {
      case 1:
        cout << "st";
        break;
      case 2:
        cout << "nd";
        break;
      case 3:
        cout << "rd";
        break;
      default:
        cout << "th";
        break;
    }
  } else {
    cout << "th";
  }

  cout << " value entered (" << largest_value << ") was the largest" << '\n';

  return 0;
}
