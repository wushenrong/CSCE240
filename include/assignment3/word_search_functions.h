/*
 * Copyright 2025 Samuel Wu
 */

#ifndef ASSIGNMENT3_WORD_SEARCH_FUNCTIONS_H_
#define ASSIGNMENT3_WORD_SEARCH_FUNCTIONS_H_

#include <array>
#include <string>

constexpr int kSize{10};
using WordSearch = std::array<std::array<char, kSize>, kSize>;

bool ReadWordSearch(const std::string& file_name, WordSearch& grid);

void PrintWordSearch(const WordSearch& grid);

bool FindWordRight(const WordSearch& grid, const std::string& to_find, int& row,
                   int& col);

bool FindWordLeft(const WordSearch& grid, const std::string& to_find, int& row,
                  int& col);

bool FindWordDown(const WordSearch& grid, const std::string& to_find, int& row,
                  int& col);

bool FindWordUp(const WordSearch& grid, const std::string& to_find, int& row,
                int& col);

bool FindWordDiagonal(const WordSearch& grid, const std::string& to_find,
                      int& row, int& col);

#endif  // ASSIGNMENT3_WORD_SEARCH_FUNCTIONS_H_
