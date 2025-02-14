/*
 * Copyright 2025 Samuel Wu
 */

#ifndef SRC_ASSIGNMENT2_PROGRAM2FUNCTIONS_H_
#define SRC_ASSIGNMENT2_PROGRAM2FUNCTIONS_H_

/**
 * Checks if an integer is a perfect square. If the integer is negative, return
 * false.
 */
bool IsSquare(int n);

/**
 * Checks if an positive integer is a perfect number where the sum of its
 * proper divisors equals the integer. If a negative integer is passed into the
 * function, return false.
 */
bool IsPerfect(int n);

/**
 * Checks if a charater is a vowel (i.e. 'a', 'e', 'i', 'o', 'u'). If check_y
 * is true, then the character 'y' is a vowel and 'y' returns true.
 */
bool IsVowel(char c, bool check_y = true);

/**
 * Checks if a character is a consonant (i.e. not 'a', 'e', 'i', 'o', 'u'). If
 * check_y is true, then the character 'y' is a consonant and 'y' returns true,.
 */
bool IsConsonant(char c, bool check_y = true);

/**
 * Converts a character to an integer if the character between '1' to '9'
 * inclusive, else return '0'.
 */
int ToDigit(char c);

/**
 * Returns the range between two numbers. If x is greater than y, then the
 * values of those variables are swapped.
 */
int Range(int& x, int& y);  // NOLINT: We need reference to swap values

/**
 * Returns a digit in a double based on its position. The position left of the
 * one's place is negative, the right of the one's place is positive and the
 * one's place is the 0th position.
 */
int DigitInPosition(double x, int position);

#endif  // SRC_ASSIGNMENT2_PROGRAM2FUNCTIONS_H_
