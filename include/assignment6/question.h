/**
 * @file question.h
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ASSIGNMENT6_QUESTION_H_
#define ASSIGNMENT6_QUESTION_H_

#include <string>
#include <string_view>

class Question {
 private:
  std::string question_;

 public:
  explicit Question(std::string_view question = "?") : question_{question} {}
  virtual ~Question() = default;

  void SetQuestion(std::string_view question) { question_ = question; }

  std::string GetQuestion() const { return question_; }

  virtual void Print(bool show_answer) const = 0;
};

#endif  // ASSIGNMENT6_QUESTION_H_
