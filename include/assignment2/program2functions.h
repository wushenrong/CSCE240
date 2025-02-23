/*
 * Copyright 2025 Samuel Wu
 */

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

/**
 * Checks if an integer is a perfect square. If the integer is negative, return
 * false.
 */
DLLEXPORT bool IsSquare(int n);

/**
 * Checks if an positive integer is a perfect number where the sum of its
 * proper divisors equals the integer. If a negative integer is passed into the
 * function, return false.
 */
DLLEXPORT bool IsPerfect(int n);

/**
 * Checks if a charater is a vowel (i.e. 'a', 'e', 'i', 'o', 'u'). If check_y
 * is true, then the character 'y' is a vowel and 'y' returns true.
 */
DLLEXPORT bool IsVowel(char c, bool check_y = true);

/**
 * Checks if a character is a consonant (i.e. not 'a', 'e', 'i', 'o', 'u'). If
 * check_y is true, then the character 'y' is a consonant and 'y' returns true,.
 */
DLLEXPORT bool IsConsonant(char c, bool check_y = true);

/**
 * Converts a character to an integer if the character between '1' to '9'
 * inclusive, else return '0'.
 */
DLLEXPORT int ToDigit(char c);

/**
 * Returns the range between two numbers. If x is greater than y, then the
 * values of those variables are swapped.
 */
DLLEXPORT int Range(int& x, int& y);

/**
 * Returns a digit in a double based on its position. The position left of the
 * one's place is negative, the right of the one's place is positive and the
 * one's place is the 0th position.
 */
DLLEXPORT int DigitInPosition(double x, int position);

#endif  // ASSIGNMENT2_PROGRAM2FUNCTIONS_H_
