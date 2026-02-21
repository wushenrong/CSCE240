/**
 * @file shortanswerquestion.cc
 * @author Samuel Wu (twopizza9621536@gmail.com)
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "assignment6/shortanswerquestion.h"

#include <iostream>
#include <string_view>

#include "assignment6/question.h"

using std::string_view;

namespace csce240_program6 {

ShortAnswerQuestion::ShortAnswerQuestion(string_view question,
                                         string_view answer)
    : Question{question}, answer_{answer} {}

void ShortAnswerQuestion::Print(bool show_answer) const {
  std::cout << "Question: " << GetQuestion() << "\n";

  if (show_answer) {
    std::cout << "Correct Answer: " << answer_;
  }
}

}  // namespace csce240_program6
