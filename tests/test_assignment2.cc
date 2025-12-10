/**
 * @file test_assignment2.cc
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "assignment2/program2functions.h"

TEST_CASE("Check perfect squares", "[assignment2]") {
  auto accept = GENERATE(0, 4, 36, 121, 225, 1024);
  CHECK(IsSquare(accept));

  auto reject = GENERATE(8, 20, 140, -1, -13, -25);
  CHECK_FALSE(IsSquare(reject));
}

TEST_CASE("Check perfect numbers", "[assignment2]") {
  auto accept = GENERATE(6, 28, 496);
  CHECK(IsPerfect(accept));

  auto reject = GENERATE(12, 27, -6);
  CHECK_FALSE(IsPerfect(reject));
}

TEST_CASE("Check vowels", "[assignment2]") {
  auto accept = GENERATE('A', 'e', 'i', 'o', 'u', 'y');
  CHECK(IsVowel(accept));

  auto reject = GENERATE('b', 'z', '@');
  CHECK_FALSE(IsVowel(reject));
  CHECK_FALSE(IsVowel('y', false));
}

TEST_CASE("Check consonant", "[assignment2]") {
  auto accept = GENERATE('C', 'g', 'k', 's', 'w', 'z', 'y');
  CHECK(IsConsonant(accept));

  auto reject = GENERATE('e', 'a', '!');
  CHECK_FALSE(IsConsonant(reject));
  CHECK_FALSE(IsConsonant('y', false));
}

TEST_CASE("Convert digit to int", "[assignment2]") {
  CHECK(ToDigit('1') == 1);
  CHECK(ToDigit('2') == 2);
  CHECK(ToDigit('3') == 3);
  CHECK(ToDigit('4') == 4);
  CHECK(ToDigit('5') == 5);
  CHECK(ToDigit('6') == 6);
  CHECK(ToDigit('7') == 7);
  CHECK(ToDigit('8') == 8);
  CHECK(ToDigit('9') == 9);

  CHECK(ToDigit('a') == 0);
}

TEST_CASE("Get range between numbers", "[assignment2]") {
  int x{9};
  int y{-3};
  int result = Range(x, y);

  CHECK(result == 12);
  CHECK(x == -3);
  CHECK(y == 9);

  x = 4;
  y = 7;
  result = Range(x, y);

  CHECK(result == 3);
  CHECK(x == 4);
  CHECK(y == 7);
}

TEST_CASE("Get digit in position", "[assignment2]") {
  constexpr double test_positive_number{12345.06789};
  constexpr double test_negative_number{-12345.06789};

  CHECK(DigitInPosition(test_positive_number, 0) == 5);
  CHECK(DigitInPosition(test_positive_number, -3) == 2);
  CHECK(DigitInPosition(test_positive_number, 4) == 8);

  CHECK(DigitInPosition(test_negative_number, 0) == 5);
  CHECK(DigitInPosition(test_negative_number, -3) == 2);
  CHECK(DigitInPosition(test_negative_number, 4) == 8);
}
