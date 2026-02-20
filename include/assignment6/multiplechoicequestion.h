/**
 * @file multiplechoicequestion.h
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ASSIGNMENT6_MULTIPLECHOICEQUESTION_H_
#define ASSIGNMENT6_MULTIPLECHOICEQUESTION_H_

#include <gsl/gsl>
#include <string>
#include <string_view>

#include "assignment6/question.h"
#include "program6classes_export.h"

namespace csce240_program6 {

/*
 * A class that represents a question that is answered by selecting mutiple
 * choices.
 */
class MultipleChoiceQuestion : public Question {
 private:
  int num_of_choices_;
  gsl::owner<std::string*> answer_choices_;
  gsl::owner<bool*> is_choice_correct_;

 public:
  PROGRAM6CLASSES_EXPORT
  explicit MultipleChoiceQuestion(std::string_view = "?", int = 0,
                                  const std::string* = nullptr,
                                  const bool* = nullptr);
  PROGRAM6CLASSES_EXPORT
  MultipleChoiceQuestion(const MultipleChoiceQuestion&);
  PROGRAM6CLASSES_EXPORT
  MultipleChoiceQuestion(MultipleChoiceQuestion&&) noexcept;

  PROGRAM6CLASSES_EXPORT
  MultipleChoiceQuestion& operator=(const MultipleChoiceQuestion&);
  PROGRAM6CLASSES_EXPORT
  MultipleChoiceQuestion& operator=(MultipleChoiceQuestion&&) noexcept;

  PROGRAM6CLASSES_EXPORT
  ~MultipleChoiceQuestion() override {
    delete[] answer_choices_;
    delete[] is_choice_correct_;
  }

  [[nodiscard]]
  PROGRAM6CLASSES_EXPORT int GetNumOfAnswerChoices() const {
    return num_of_choices_;
  }

  PROGRAM6CLASSES_EXPORT
  void SetAnswerChoices(int, const std::string*, const bool*);

  PROGRAM6CLASSES_EXPORT
  void Print(bool show_answers) const override;
};

}  // namespace csce240_program6

#endif  // ASSIGNMENT6_MULTIPLECHOICEQUESTION_H_
