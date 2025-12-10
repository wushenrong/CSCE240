/**
 * @file test_assignment4.cc
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-12
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <catch2/catch_test_macros.hpp>

#include "assignment4/weight.h"
#include "assignment4/weightrange.h"

TEST_CASE("Tests Constant Weight", "[weights]") {
  const Weight weight1{100, "grams"};

  const WeightRange range1{Weight{1, "pounds"}, Weight{2, "ounces"}};

  CHECK(range1.InRange(weight1));
}
