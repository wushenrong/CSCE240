/*
 * Copyright 2025 Samuel Wu
 */

#include "assignment6/shortanswerquestion.h"

#include <iostream>
#include <string_view>

#include "assignment6/question.h"

using std::cout;
using std::string_view;

namespace csce240_program6 {

/*
 * A class that represents a question that is answered through a short
 * sentence or paragraph.
 */
ShortAnswerQuestion::ShortAnswerQuestion(string_view question,
                                         string_view answer)
    : Question{question}, answer_{answer} {}

void ShortAnswerQuestion::Print(bool show_answer) const {
  cout << "Question: " << GetQuestion() << '\n';

  if (show_answer) {
    cout << "Correct Answer: " << answer_ << '\n';
  }
}

}  // namespace csce240_program6
