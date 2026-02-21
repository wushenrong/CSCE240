/**
 * @file truefalsequestion.cc
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "assignment6/truefalsequestion.h"

#include <iostream>
#include <string_view>

#include "assignment6/question.h"

using std::string_view;

namespace csce240_program6 {

TrueFalseQuestion::TrueFalseQuestion(string_view question, bool answer)
    : Question{question}, answer_{answer} {}

void TrueFalseQuestion::Print(bool show_answer) const {
  std::cout << "Question: " << GetQuestion() << "\n";

  if (show_answer) {
    std::cout << "Correct Answer: " << std::boolalpha << answer_
              << std::noboolalpha;
  }
}

}  // namespace csce240_program6
