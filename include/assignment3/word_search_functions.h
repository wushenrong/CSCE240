/**
 * @file word_search_functions.h
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ASSIGNMENT3_WORD_SEARCH_FUNCTIONS_H_
#define ASSIGNMENT3_WORD_SEARCH_FUNCTIONS_H_

#include <array>
#include <string>
#include <string_view>

#include "wordsearchfunctions_export.h"

/**
 * The size of word search
 */
constexpr int kSize{10};

/**
 * The word search structure as an equal sized 2D array.
 */
using WordSearch = std::array<std::array<char, kSize>, kSize>;

/**
 * Reads and load a word search from a file.
 *
 * @param file_name The file to read.
 * @param grid The word search to fill.
 *
 * @return True if the file was correctly read. Otherwise false.
 */
WORDSEARCHFUNCTIONS_EXPORT bool ReadWordSearch(const std::string& file_name,
                                               WordSearch& grid);

/**
 * Reads and load a word search from a file.
 *
 * @param file_name The file to read.
 * @param grid The word search to fill.
 *
 * @return True if the file was correctly read. Otherwise false.
 */
WORDSEARCHFUNCTIONS_EXPORT void PrintWordSearch(const WordSearch& grid);

/**
 * Finds a word that is written from left to right.
 *
 * @param grid The word search to find the word in.
 * @param to_find The string to find.
 * @param row The row of where the word was found. If the word was not found,
 *   this variable will not be modified.
 * @param col The column of where the word was found. If the word was not
 *   found, this variable will not be modified.
 *
 * @return True if the word was found. Otherwise return false.
 */
WORDSEARCHFUNCTIONS_EXPORT bool FindWordRight(const WordSearch& grid,
                                              std::string_view to_find,
                                              int& row, int& col);

/**
 * Finds a word that is written from right to left.
 *
 * @param grid The word search to find the word in.
 * @param to_find The string to find.
 * @param row The row of where the word was found. If the word was not found,
 *   this variable will not be modified.
 * @param col The column of where the word was found. If the word was not
 *   found, this variable will not be modified.
 *
 * @return True if the word was found. Otherwise return false.
 */
WORDSEARCHFUNCTIONS_EXPORT bool FindWordLeft(const WordSearch& grid,
                                             std::string_view to_find, int& row,
                                             int& col);

/**
 * Finds a word that is written from top to bottom.
 *
 * @param grid The word search to find the word in.
 * @param to_find The string to find.
 * @param row The row of where the word was found. If the word was not found,
 *   this variable will not be modified.
 * @param col The column of where the word was found. If the word was not
 *   found, this variable will not be modified.
 *
 * @return True if the word was found. Otherwise return false.
 */
WORDSEARCHFUNCTIONS_EXPORT bool FindWordDown(const WordSearch& grid,
                                             std::string_view to_find, int& row,
                                             int& col);

/**
 * Finds a word that is written from bottom to top.
 *
 * @param grid The word search to find the word in.
 * @param to_find The string to find.
 * @param row The row of where the word was found. If the word was not found,
 *   this variable will not be modified.
 * @param col The column of where the word was found. If the word was not
 *   found, this variable will not be modified.
 *
 * @return True if the word was found. Otherwise return false.
 */
WORDSEARCHFUNCTIONS_EXPORT bool FindWordUp(const WordSearch& grid,
                                           std::string_view to_find, int& row,
                                           int& col);

/**
 * Finds a word that is written diagonally from left to right, top to bottom.
 *
 * @param grid The word search to find the word in.
 * @param to_find The string to find.
 * @param row The row of where the word was found. If the word was not found,
 *   this variable will not be modified.
 * @param col The column of where the word was found. If the word was not
 *   found, this variable will not be modified.
 *
 * @return True if the word was found. Otherwise return false.
 */
WORDSEARCHFUNCTIONS_EXPORT bool FindWordDiagonal(const WordSearch& grid,
                                                 std::string_view to_find,
                                                 int& row, int& col);

#endif  // ASSIGNMENT3_WORD_SEARCH_FUNCTIONS_H_
