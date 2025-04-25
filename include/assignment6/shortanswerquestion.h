/*
 * Copyright 2025 Samuel Wu
 */

#ifndef ASSIGNMENT6_SHORTANSWERQUESTION_H_
#define ASSIGNMENT6_SHORTANSWERQUESTION_H_

#include <string>
#include <string_view>

#include "assignment6/question.h"

namespace csce240_program6 {

class ShortAnswerQuestion : public Question {
 public:
  explicit ShortAnswerQuestion(std::string_view = "?", std::string_view = "");

  void SetAnswer(std::string_view answer) { answer_ = answer; }

  std::string GetAnswer() const { return answer_; }

  void Print(bool show_answer) const override;

 private:
  std::string answer_;
};

}  // namespace csce240_program6

#endif  // ASSIGNMENT6_SHORTANSWERQUESTION_H_
