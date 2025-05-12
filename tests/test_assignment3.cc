/**
 * @file test_assignment3.cc
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <catch2/catch_test_macros.hpp>

#include "assignment3/word_search_functions.h"

const WordSearch expected_wordsearch{{
    {'d', 'a', 'e', 'n', 'g', 'r', 'e', 'v', 'e', 's'},
    {'n', 'w', 'j', 'f', 'q', 'o', 'q', 'n', 'f', 'k'},
    {'a', 'e', 'e', 'n', 's', 'v', 'l', 's', 'n', 'w'},
    {'j', 's', 'o', 'g', 'n', 'q', 'p', 's', 'm', 'g'},
    {'q', 'o', 'r', 'j', 'e', 'r', 'h', 'd', 'j', 'f'},
    {'s', 'm', 'e', 'e', 'j', 'f', 'i', 'r', 'n', 'w'},
    {'p', 'e', 'r', 'v', 't', 'i', 'f', 'e', 's', 'k'},
    {'m', 's', 'k', 'n', 'e', 'j', 't', 'v', 'd', 'n'},
    {'l', 'e', 'd', 'p', 'w', 'r', 'k', 'e', 't', 'i'},
    {'s', 'k', 'n', 'i', 'c', 'e', 't', 'n', 'e', 's'},
}};

TEST_CASE("Test reading a word seach file", "[wordsearch]") {
  WordSearch wordsearch{};

  ReadWordSearch("example_wordsearch.txt", wordsearch);
  CHECK(wordsearch == expected_wordsearch);
}

TEST_CASE("Testing searching functions", "[wordsearch]") {
  int row{};
  int col{};

  SECTION("Finding a word from left to right") {
    CHECK(FindWordRight(expected_wordsearch, "nice", row, col));
    CHECK(row == 9);
    CHECK(col == 2);
  }

  SECTION("Finding a word from right to left") {
    CHECK(FindWordLeft(expected_wordsearch, "sever", row, col));
    CHECK(row == 0);
    CHECK(col == 9);
  }

  SECTION("Finding a word from top to bottom") {
    CHECK(FindWordDown(expected_wordsearch, "awesome", row, col));
    CHECK(row == 0);
    CHECK(col == 1);
  }

  SECTION("Finding a word from bottom to top") {
    CHECK(FindWordUp(expected_wordsearch, "never", row, col));
    CHECK(row == 9);
    CHECK(col == 7);
  }

  SECTION("Finding a word diagonally from left to right, bottom to top") {
    CHECK(FindWordDiagonal(expected_wordsearch, "joever", row, col));
    CHECK(row == 3);
    CHECK(col == 0);
  }
}
