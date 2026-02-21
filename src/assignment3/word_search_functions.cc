/**
 * @file word_search_functions.cc
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "assignment3/word_search_functions.h"

#include <array>
#include <cstddef>
#include <fstream>
#include <gsl/gsl>
#include <iostream>
#include <string>
#include <string_view>

using std::string;
using std::string_view;

/**
 * Read a word search file and put it in an existing character array of
 * kSize by kSize characters. If the file does not exists, return false for
 * failing to open the file. Otherwise, read the file and read kSize * kSize
 * characters from the file without any newlines, tab or space characters.
 * If the number of characters read does not equals kSize * kSize, return
 * false. Otherwise, fill the character array and return true.
 */
bool ReadWordSearch(const string& file_name, WordSearch& grid) {
  std::ifstream word_search{file_name};

  if (!word_search) {
    return false;
  }

  std::array<char, kSize * kSize> letters{};
  size_t number_of_letters{};

  char letter{};
  while (word_search.good() && number_of_letters < letters.size()) {
    word_search.get(letter);
    if (letter != '\n' && letter != ' ') {
      letters.at(number_of_letters) = letter;
      ++number_of_letters;
    }
  }

  if (number_of_letters != letters.size()) {
    return false;
  }

  number_of_letters = 0;

  for (auto& row : grid) {
    for (auto& col : row) {
      col = letters.at(number_of_letters);
      ++number_of_letters;
    }
  }

  return true;
}

/**
 * Print out the word search by iterating though the word search row by row.
 */
void PrintWordSearch(const WordSearch& grid) {
  for (const auto& row : grid) {
    for (const auto& col : row) {
      std::cout << col;
    }

    std::cout << '\n';
  }
}

/**
 * Find a word in the word search that is written from left to right by
 * iterating though the grid. Then if the first charater of the word matches a
 * character on the word search and the word fits at that position on the word
 * search, assume we found the word. Then iterate through the string and the
 * characters at that position of the word search. If any of the characters
 * does not match, then continue to find the next match. Else if the characters
 * matches, set the row and col to the position of the first character of the
 * word on the word search and return true. Otherwise if we iterated through
 * the word search without matching the word, then the word is not in the word
 * search and return false.
 */
bool FindWordRight(const WordSearch& grid, string_view to_find, int& row,
                   int& col) {
  for (size_t grid_row = 0; grid_row < grid.size(); ++grid_row) {
    for (size_t grid_col = 0; grid_col < grid.at(grid_row).size(); ++grid_col) {
      if (grid.at(grid_row).at(grid_col) == to_find[0] &&
          grid_col + to_find.length() <= grid.at(grid_row).size()) {
        bool found{true};

        for (size_t i = 1; i < to_find.length(); ++i) {
          if (grid.at(grid_row).at(grid_col + i) != to_find[i]) {
            found = false;
            break;
          }
        }

        if (found) {
          row = gsl::narrow_cast<int>(grid_row);
          col = gsl::narrow_cast<int>(grid_col);
          return true;
        }
      }
    }
  }

  return false;
}

/**
 * Find a word in the word search that is written from right to left by
 * iterating though the grid. The implementation is the same as FindWordRight
 * but we check if the word fits and matches in the word search in reverse.
 */
bool FindWordLeft(const WordSearch& grid, string_view to_find, int& row,
                  int& col) {
  for (size_t grid_row = 0; grid_row < grid.size(); ++grid_row) {
    for (size_t grid_col = 0; grid_col < grid.at(grid_row).size(); ++grid_col) {
      if (grid.at(grid_row).at(grid_col) == to_find[0] &&
          grid_col >= to_find.length() - 1) {
        bool found{true};

        for (size_t i = 1; i < to_find.length(); ++i) {
          if (grid.at(grid_row).at(grid_col - i) != to_find[i]) {
            found = false;
            break;
          }
        }

        if (found) {
          row = gsl::narrow_cast<int>(grid_row);
          col = gsl::narrow_cast<int>(grid_col);
          return true;
        }
      }
    }
  }

  return false;
}

/**
 * Find a word in the word search that is written from top to bottom by
 * iterating though the grid. The implementation is the same as FindWordRight
 * but we check if the word fits and matches in the word search in from top to
 * bottom.
 */
bool FindWordDown(const WordSearch& grid, string_view to_find, int& row,
                  int& col) {
  for (size_t grid_row = 0; grid_row < grid.size(); ++grid_row) {
    for (size_t grid_col = 0; grid_col < grid.at(grid_row).size(); ++grid_col) {
      if (grid.at(grid_row).at(grid_col) == to_find[0] &&
          grid_row + to_find.length() <= grid.size()) {
        bool found{true};

        for (size_t i = 1; i < to_find.length(); ++i) {
          if (grid.at(grid_row + i).at(grid_col) != to_find[i]) {
            found = false;
            break;
          }
        }

        if (found) {
          row = gsl::narrow_cast<int>(grid_row);
          col = gsl::narrow_cast<int>(grid_col);
          return true;
        }
      }
    }
  }

  return false;
}

/**
 * Find a word in the word search that is written from bottom to top by
 * iterating though the grid. The implementation is the same as FindWordDown
 * but we check if the word fits and matches in the word search in from bottom
 * to top.
 */
bool FindWordUp(const WordSearch& grid, string_view to_find, int& row,
                int& col) {
  for (size_t grid_row = 0; grid_row < grid.size(); ++grid_row) {
    for (size_t grid_col = 0; grid_col < grid.at(grid_row).size(); ++grid_col) {
      if (grid.at(grid_row).at(grid_col) == to_find[0] &&
          grid_row >= to_find.length() - 1) {
        bool found{true};

        for (size_t i = 1; i < to_find.length(); ++i) {
          if (grid.at(grid_row - i).at(grid_col) != to_find[i]) {
            found = false;
            break;
          }
        }

        if (found) {
          row = gsl::narrow_cast<int>(grid_row);
          col = gsl::narrow_cast<int>(grid_col);
          return true;
        }
      }
    }
  }

  return false;
}

/**
 * Find a word in the word search that is diagonally written from right to left
 * and top to bottom by iterating though the grid. The implementation is the
 * same as FindWordRight but we check if the word fits and matches in the word
 * search from from right to left and top to bottom as the length of the
 * diagonal is the length of the string in both the row and col direction.
 */
bool FindWordDiagonal(const WordSearch& grid, string_view to_find, int& row,
                      int& col) {
  for (size_t grid_row = 0; grid_row < grid.size(); ++grid_row) {
    for (size_t grid_col = 0; grid_col < grid.at(grid_row).size(); ++grid_col) {
      if (grid.at(grid_row).at(grid_col) == to_find[0] &&
          grid_row + to_find.length() <= grid.size() &&
          grid_col + to_find.length() <= grid.at(grid_row).size()) {
        bool found{true};

        for (size_t i = 1; i < to_find.length(); ++i) {
          if (grid.at(grid_row + i).at(grid_col + i) != to_find[i]) {
            found = false;
            break;
          }
        }

        if (found) {
          row = gsl::narrow_cast<int>(grid_row);
          col = gsl::narrow_cast<int>(grid_col);
          return true;
        }
      }
    }
  }

  return false;
}
