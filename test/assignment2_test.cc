/*
 * Copyright 2025 Samuel Wu
 */

#include <catch2/catch_test_macros.hpp>

#include "assignment2/program2functions.h"

TEST_CASE("Check perfect squares", "[IsSquare]") {
  // Accept perfect squares
  REQUIRE(IsSquare(0));
  REQUIRE(IsSquare(4));
  REQUIRE(IsSquare(36));
  REQUIRE(IsSquare(121));
  REQUIRE(IsSquare(225));
  REQUIRE(IsSquare(1024));

  // Reject non perfect squares
  REQUIRE(!IsSquare(8));
  REQUIRE(!IsSquare(20));
  REQUIRE(!IsSquare(140));
  REQUIRE(!IsSquare(-1));
  REQUIRE(!IsSquare(-13));
  REQUIRE(!IsSquare(-25));
}

TEST_CASE("Check perfect numbers", "[IsPerfect]") {
  // Accept perfect numbers
  REQUIRE(IsPerfect(6));
  REQUIRE(IsPerfect(28));
  REQUIRE(IsPerfect(496));

  // Reject non perfect numbers
  REQUIRE(!IsPerfect(12));
  REQUIRE(!IsPerfect(27));
  REQUIRE(!IsPerfect(-6));
}

TEST_CASE("Check vowels", "[IsVowels]") {
  // Accept vowels
  REQUIRE(IsVowel('A'));
  REQUIRE(IsVowel('e'));
  REQUIRE(IsVowel('i'));
  REQUIRE(IsVowel('o'));
  REQUIRE(IsVowel('u'));
  REQUIRE(IsVowel('y'));

  // Reject non vowels
  REQUIRE(!IsVowel('b'));
  REQUIRE(!IsVowel('z'));
  REQUIRE(!IsVowel('@'));
  REQUIRE(!IsVowel('y', false));
}

TEST_CASE("Check consonant", "[IsConsonant]") {
  // Accept consonant
  REQUIRE(IsConsonant('C'));
  REQUIRE(IsConsonant('g'));
  REQUIRE(IsConsonant('k'));
  REQUIRE(IsConsonant('s'));
  REQUIRE(IsConsonant('w'));
  REQUIRE(IsConsonant('z'));
  REQUIRE(IsConsonant('y'));

  // Reject non consonant
  REQUIRE(!IsConsonant('e'));
  REQUIRE(!IsConsonant('a'));
  REQUIRE(!IsConsonant('!'));
  REQUIRE(!IsConsonant('y', false));
}

TEST_CASE("Convert digit to int", "[ToDigit]") {
  REQUIRE(ToDigit('1') == 1);
  REQUIRE(ToDigit('2') == 2);
  REQUIRE(ToDigit('3') == 3);
  REQUIRE(ToDigit('4') == 4);
  REQUIRE(ToDigit('5') == 5);
  REQUIRE(ToDigit('6') == 6);
  REQUIRE(ToDigit('7') == 7);
  REQUIRE(ToDigit('8') == 8);
  REQUIRE(ToDigit('9') == 9);

  REQUIRE(ToDigit('a') == 0);
}

TEST_CASE("Get range between numbers", "[Range]") {
  int x{9};
  int y{-3};
  int result = Range(x, y);

  REQUIRE(result == 12);
  REQUIRE(x == -3);
  REQUIRE(y == 9);

  x = 4;
  y = 7;
  result = Range(x, y);

  REQUIRE(result == 3);
  REQUIRE(x == 4);
  REQUIRE(y == 7);
}

TEST_CASE("Get digit in position", "[DigitInPosition]") {
  constexpr double test_positive_number{12345.06789};
  constexpr double test_negative_number{12345.06789};

  REQUIRE(DigitInPosition(test_positive_number, 0) == 5);
  REQUIRE(DigitInPosition(test_positive_number, -3) == 2);
  REQUIRE(DigitInPosition(test_positive_number, 4) == 8);

  REQUIRE(DigitInPosition(test_negative_number, 0) == 5);
  REQUIRE(DigitInPosition(test_negative_number, -3) == 2);
  REQUIRE(DigitInPosition(test_negative_number, 4) == 8);
}
