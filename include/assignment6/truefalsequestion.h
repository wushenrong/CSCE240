/**
 * @file truefalsequestion.h
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
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
 private:
  bool answer_;

 public:
  explicit TrueFalseQuestion(std::string_view = "?", bool = true);

  void SetAnswer(bool a) { answer_ = a; }
  bool GetAnswer() const { return answer_; }

  void Print(bool show_answer) const override;
};

}  // namespace csce240_program6

#endif  // ASSIGNMENT6_TRUEFALSEQUESTION_H_
