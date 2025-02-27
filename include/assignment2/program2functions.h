/// @file program2functions.h
/// @author Samuel Wu
/// @brief Utility functions for character and mathmatical calculations.
/// @version 0.0.0
/// @date 2025-02-27
///
/// @copyright Copyright (c) 2025
///

#ifndef ASSIGNMENT2_PROGRAM2FUNCTIONS_H_
#define ASSIGNMENT2_PROGRAM2FUNCTIONS_H_

#ifdef WIN32
#ifdef program2functions_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif  // program2functions_EXPORTS
#else
#define DLLEXPORT
#endif  // WIN32

/// Checks if an integer is a perfect square.
///
/// @param n The integer to check.
/// @return True if the number is a perfect square, false if the integer is not
///   a perfect square or it is a negative integer.
DLLEXPORT bool IsSquare(int n);

/// Checks if an positive integer is a perfect number where the sum of its
/// proper divisors equals the integer.
///
/// @param n The integer to check.
/// @return True if the number is a perfect number, false if the integer is not
///   a perfect number or it is a negative integer.
DLLEXPORT bool IsPerfect(int n);

/// Checks if a charater is a vowel (i.e. 'a', 'e', 'i', 'o', 'u').
///
/// @param c The character to check.
/// @param check_y Makes the character 'y' a vowel.
/// @return True if the character is a vowel, otherwise returns false.
DLLEXPORT bool IsVowel(char c, bool check_y = true);

/// Checks if a character is a consonant (i.e. not 'a', 'e', 'i', 'o', 'u').
///
/// @param c The character to check.
/// @param check_y Makes the character 'y' a consonant.
/// @return True if the character is a consonant, otherwise returns false.
DLLEXPORT bool IsConsonant(char c, bool check_y = true);

/// Converts a character to an integer if the character between '1' to '9'
/// inclusive.
///
/// @param c The character to convert.
/// @return The integer 1 to 9 if the character is '1' to '9', otherwise return.
///   0
DLLEXPORT int ToDigit(char c);

/// Calculates the range of two integers. If x is greater than y, then the
/// values of those variables are swapped.
///
/// @param x The staring integer.
/// @param y The ending integer.
/// @return The range of x and y.
DLLEXPORT int Range(int& x, int& y);

/// Calculates the digit based on its position in a real number.
///
/// @param x The real number.
/// @param pos Position of the digit to get. If positive, get the digit in
///   the decimals place. If negative, get the digit in the tens place.
///   Otherwise if 0, get the one's place digit.
/// @return The digit in the real number based on its position.
DLLEXPORT int DigitInPosition(double x, int pos);

#endif  // ASSIGNMENT2_PROGRAM2FUNCTIONS_H_
