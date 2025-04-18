/*
 * Copyright 2025 Samuel Wu
 */

#ifndef ASSIGNMENT6_TRUEFALSEQUESTION_H_
#define ASSIGNMENT6_TRUEFALSEQUESTION_H_

#include <string>
#include <string_view>

#include "assignment6/question.h"

namespace csce240_program6 {

/*
 * A class that represents a question that is answered by using true or false.
 */
class TrueFalseQuestion : public Question {
 public:
  explicit TrueFalseQuestion(std::string_view = "?", bool = true);

  void SetAnswer(bool a) { answer_ = a; }
  bool GetAnswer() const { return answer_; }

  void Print(bool show_answer) const override;

 private:
  bool answer_;
};

}  // namespace csce240_program6

#endif  // ASSIGNMENT6_TRUEFALSEQUESTION_H_
