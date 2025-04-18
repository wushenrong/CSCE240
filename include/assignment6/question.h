/*
 * Copyright 2025 Samuel Wu
 */

#ifndef ASSIGNMENT6_QUESTION_H_
#define ASSIGNMENT6_QUESTION_H_

#include <string>
#include <string_view>

class Question {
 public:
  explicit Question(std::string_view question = "?") : question_{question} {}
  virtual ~Question() = default;

  void SetQuestion(std::string_view question) { question_ = question; }

  [[nodiscard]]
  std::string GetQuestion() const {
    return question_;
  }

  virtual void Print(bool show_answer) const = 0;

 private:
  std::string question_;
};

#endif  // ASSIGNMENT6_QUESTION_H_
