/*
 * Copyright 2025 Samuel Wu
 */

#include <catch2/catch_test_macros.hpp>

#include "assignment2/program2functions.h"

TEST_CASE("Check perfect squares", "[square]") {
  // Accept perfect squares
  CHECK(IsSquare(0));
  CHECK(IsSquare(4));
  CHECK(IsSquare(36));
  CHECK(IsSquare(121));
  CHECK(IsSquare(225));
  CHECK(IsSquare(1024));

  // Reject non perfect squares
  CHECK_FALSE(IsSquare(8));
  CHECK_FALSE(IsSquare(20));
  CHECK_FALSE(IsSquare(140));
  CHECK_FALSE(IsSquare(-1));
  CHECK_FALSE(IsSquare(-13));
  CHECK_FALSE(IsSquare(-25));
}

TEST_CASE("Check perfect numbers", "[perfect]") {
  // Accept perfect numbers
  CHECK(IsPerfect(6));
  CHECK(IsPerfect(28));
  CHECK(IsPerfect(496));

  // Reject non perfect numbers
  CHECK_FALSE(IsPerfect(12));
  CHECK_FALSE(IsPerfect(27));
  CHECK_FALSE(IsPerfect(-6));
}

TEST_CASE("Check vowels", "[vowels]") {
  // Accept vowels
  CHECK(IsVowel('A'));
  CHECK(IsVowel('e'));
  CHECK(IsVowel('i'));
  CHECK(IsVowel('o'));
  CHECK(IsVowel('u'));
  CHECK(IsVowel('y'));

  // Reject non vowels
  CHECK_FALSE(IsVowel('b'));
  CHECK_FALSE(IsVowel('z'));
  CHECK_FALSE(IsVowel('@'));
  CHECK_FALSE(IsVowel('y', false));
}

TEST_CASE("Check consonant", "[consonant]") {
  // Accept consonant
  CHECK(IsConsonant('C'));
  CHECK(IsConsonant('g'));
  CHECK(IsConsonant('k'));
  CHECK(IsConsonant('s'));
  CHECK(IsConsonant('w'));
  CHECK(IsConsonant('z'));
  CHECK(IsConsonant('y'));

  // Reject non consonant
  CHECK_FALSE(IsConsonant('e'));
  CHECK_FALSE(IsConsonant('a'));
  CHECK_FALSE(IsConsonant('!'));
  CHECK_FALSE(IsConsonant('y', false));
}

TEST_CASE("Convert digit to int", "[todigit]") {
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

TEST_CASE("Get range between numbers", "[range]") {
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

TEST_CASE("Get digit in position", "[digitinposition]") {
  constexpr double test_positive_number{12345.06789};
  constexpr double test_negative_number{12345.06789};

  CHECK(DigitInPosition(test_positive_number, 0) == 5);
  CHECK(DigitInPosition(test_positive_number, -3) == 2);
  CHECK(DigitInPosition(test_positive_number, 4) == 8);

  CHECK(DigitInPosition(test_negative_number, 0) == 5);
  CHECK(DigitInPosition(test_negative_number, -3) == 2);
  CHECK(DigitInPosition(test_negative_number, 4) == 8);
}
