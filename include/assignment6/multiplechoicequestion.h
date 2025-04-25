/*
 * Copyright 2025 Samuel Wu
 */

#ifndef ASSIGNMENT6_MULTIPLECHOICEQUESTION_H_
#define ASSIGNMENT6_MULTIPLECHOICEQUESTION_H_

#include <gsl/gsl>
#include <string>
#include <string_view>

#include "assignment6/question.h"

namespace csce240_program6 {

/*
 * A class that represents a question that is answered by selecting mutiple
 * choices.
 */
class MultipleChoiceQuestion : public Question {
 public:
  explicit MultipleChoiceQuestion(std::string_view = "?", int = 0,
                                  const std::string* = nullptr,
                                  const bool* = nullptr);
  MultipleChoiceQuestion(const MultipleChoiceQuestion&);

  MultipleChoiceQuestion& operator=(const MultipleChoiceQuestion&);

  ~MultipleChoiceQuestion() override {
    delete[] answer_choices_;
    delete[] is_answer_choice_correct_;
  }

  void SetAnswerChoices(int, const std::string*, const bool*);

  int GetNumOfAnswerChoices() const { return num_of_answer_choices_; }

  void Print(bool show_answers) const override;

 private:
  int num_of_answer_choices_;
  gsl::owner<std::string*> answer_choices_;
  gsl::owner<bool*> is_answer_choice_correct_;
};

}  // namespace csce240_program6

#endif  // ASSIGNMENT6_MULTIPLECHOICEQUESTION_H_
