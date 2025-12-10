/**
 * @file multiplechoicequestion.cc
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "assignment6/multiplechoicequestion.h"

#include <cstddef>
#include <print>
#include <string>
#include <string_view>
#include <utility>

#include "assignment6/question.h"

using std::size_t;
using std::string;
using std::string_view;

namespace csce240_program6 {

MultipleChoiceQuestion::MultipleChoiceQuestion(string_view question, int n,
                                               const string* acs,
                                               const bool* iacc)
    : Question{question},
      num_of_choices_{0},
      answer_choices_{nullptr},
      is_choice_correct_{nullptr} {
  SetAnswerChoices(n, acs, iacc);
}

MultipleChoiceQuestion::MultipleChoiceQuestion(
    const MultipleChoiceQuestion& rhs)
    : Question{rhs},
      num_of_choices_{0},
      answer_choices_{nullptr},
      is_choice_correct_{nullptr} {
  SetAnswerChoices(rhs.num_of_choices_, rhs.answer_choices_,
                   rhs.is_choice_correct_);
}

MultipleChoiceQuestion::MultipleChoiceQuestion(MultipleChoiceQuestion&& rhs)
    : Question{std::move(rhs)},
      num_of_choices_{rhs.num_of_choices_},
      answer_choices_{rhs.answer_choices_},
      is_choice_correct_{rhs.is_choice_correct_} {
  rhs.num_of_choices_ = 0;
  rhs.answer_choices_ = nullptr;
  rhs.is_choice_correct_ = nullptr;
}

/**
 * Assign multiple question to another by copying over the question and answers.
 * Also making sure that the object do not assign itself to itself.
 */
MultipleChoiceQuestion& MultipleChoiceQuestion::operator=(
    const MultipleChoiceQuestion& rhs) {
  if (this == &rhs) {
    return *this;
  }

  Question::operator=(rhs);

  SetAnswerChoices(rhs.num_of_choices_, rhs.answer_choices_,
                   rhs.is_choice_correct_);

  return *this;
}

/**
 * Assign multiple question to another by moving over the question and answers.
 * Also making sure that the object do not assign itself to itself.
 */
MultipleChoiceQuestion& MultipleChoiceQuestion::operator=(
    MultipleChoiceQuestion&& rhs) {
  if (this == &rhs) {
    return *this;
  }

  Question::operator=(rhs);

  num_of_choices_ = rhs.num_of_choices_;

  delete[] answer_choices_;
  delete[] is_choice_correct_;

  answer_choices_ = rhs.answer_choices_;
  is_choice_correct_ = rhs.is_choice_correct_;

  rhs.num_of_choices_ = 0;
  rhs.answer_choices_ = nullptr;
  rhs.is_choice_correct_ = nullptr;

  return *this;
}

/**
 * Sets up answer choices by deleting the pervious choices and the answers.
 * Next if the number of answer is zero, then make sure there are no answers for
 * the question. Otherwise create and copy over the new answer choices. If no
 * answers are given, then set all answer to an empty string and mark them all
 * to be correct.
 */
void MultipleChoiceQuestion::SetAnswerChoices(int n, const string* acs,
                                              const bool* iacc) {
  if (n < 0) {
    return;
  }

  delete[] answer_choices_;
  delete[] is_choice_correct_;

  if (n == 0) {
    num_of_choices_ = 0;
    answer_choices_ = nullptr;
    is_choice_correct_ = nullptr;
    return;
  }

  num_of_choices_ = n;
  answer_choices_ = new string[static_cast<size_t>(num_of_choices_)];
  is_choice_correct_ = new bool[static_cast<size_t>(num_of_choices_)];

  for (int i = 0; i < num_of_choices_; ++i) {
    if (acs != nullptr) {
      answer_choices_[i] = acs[i];
    } else {
      answer_choices_[i] = "";
    }

    if (iacc != nullptr) {
      is_choice_correct_[i] = iacc[i];
    } else {
      is_choice_correct_[i] = true;
    }
  }
}

void MultipleChoiceQuestion::Print(bool show_answers) const {
  std::println("Question: {}", GetQuestion());
  std::println("Answer Choices:");

  for (int i = 0; i < num_of_choices_; ++i) {
    std::print("{}", answer_choices_[i]);

    if (show_answers) {
      std::print("{}", is_choice_correct_[i] ? " - correct" : " - incorrect");
    }

    std::println();
  }
}

}  // namespace csce240_program6
