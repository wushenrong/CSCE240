/*
 * Copyright 2025 Samuel Wu
 */

#include "assignment2/program2functions.h"

// clang-format: off -- GSL is currently an external library
#include <gsl/util>
// clang-format: on

#include <algorithm>
#include <cmath>
#include <utility>

/**
 * Check if an integer is a perfect square by first checking if the integer is
 * negative. If true, return false. Else calculate the square root of the
 * integer. Then flooring the root and check if the floored root is the same as
 * the root.
 */
bool IsSquare(int n) {
  if (n < 0) {
    return false;
  }

  const double root = std::sqrt(n);
  const double flooredRoot = std::floor(root);

  // Compare the root and the floored root using an percentage threshold because
  // of possible floating point rounding errors
  // https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/
  constexpr double relEpsilon{1e-8};

  return (std::abs(root - flooredRoot) <=
          std::max(std::abs(root), std::abs(flooredRoot)) * relEpsilon);
}

/**
 * Checking if a integer is a perfect number by first checking if the integer
 * is negative. If true, return false. Else manually find all the integer's
 * proper divisors and check if the sum of the divisors equals the integer.
 */
bool IsPerfect(int n) {
  if (n < 0) {
    return false;
  }

  int runningCount = 0;

  for (int i = 1; i < n; ++i) {
    if (n % i == 0) {
      runningCount += i;
    }
  }

  return runningCount == n;
}

/**
 * Checks if a character is a vowel by first checking if the character is an
 * uppercase character between 'A' and 'Z' inclusive. Convert the character to
 * lowercase by adding the ASCII difference of 'a' and 'A'. If the character is
 * 'y', return check_y. Else check if the character is either 'a', 'e', 'i',
 * 'o', 'u'.
 */
bool IsVowel(char c, bool check_y) {
  if (c >= 'A' && c <= 'Z') {
    c += 'a' - 'A';
  }

  if (c == 'y') {
    return check_y;
  }

  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

/**
 * Checks if a character is a vowel by first checking if the character is an
 * uppercase character between 'A' and 'Z' inclusive. Convert the character to
 * lowercase by adding the ASCII difference of 'a' and 'A'. If the character is
 * 'y', return check_y. Else check if the character is a consonant between
 * 'a' to 'z' excluding 'a', 'e', 'i', 'o', 'u', and 'y'.
 */
bool IsConsonant(char c, bool check_y) {
  if (c >= 'A' && c <= 'Z') {
    c += 'a' - 'A';
  }

  if (c == 'y') {
    return check_y;
  }

  return (c > 'a' && c < 'e') || (c > 'e' && c < 'i') || (c > 'i' && c < 'o') ||
         (c > 'o' && c < 'u') || (c > 'u' && c < 'y') || (c == 'z');
}

/**
 * Converts a digit character to an integer by checking if the character is '1'
 * to '9' inclusive and returns 1 to 9 respectively. Else return 0.
 */
int ToDigit(char c) {
  switch (c) {
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
    default:
      return 0;
  }
}

/**
 * Returns the range between two numbers by first checking if x is greater than
 * y. If true swap the values of the variables referenced by x and y. Then
 * return the difference of y and x.
 */
int Range(int &x, int &y) {
  if (x > y) {
    std::swap(x, y);
  }

  return y - x;
}

/**
 * Returns the digit from a double based on its position by first shifting the
 * digits from its current position to the one place through multiplying by the
 * powers of 10. Then module the double by 10 to get the digit before returning
 * and truncating the digit to an int.
 */
int DigitInPosition(double x, int position) {
  constexpr int base = 10;
  return gsl::narrow_cast<int>(std::fmod(x * std::pow(base, position), base));
}
