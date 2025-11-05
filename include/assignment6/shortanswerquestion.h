/**
 * @file shortanswerquestion.h
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ASSIGNMENT6_SHORTANSWERQUESTION_H_
#define ASSIGNMENT6_SHORTANSWERQUESTION_H_

#include <string>
#include <string_view>

#include "assignment6/question.h"

namespace csce240_program6 {

/**
 * A class that represents a question that is answered through a short
 * sentence or paragraph.
 */
class ShortAnswerQuestion : public Question {
 private:
  std::string answer_;

 public:
  explicit ShortAnswerQuestion(std::string_view = "?", std::string_view = "");

  void SetAnswer(std::string_view answer) { answer_ = answer; }

  std::string GetAnswer() const { return answer_; }

  void Print(bool show_answer) const override;
};

}  // namespace csce240_program6

#endif  // ASSIGNMENT6_SHORTANSWERQUESTION_H_
