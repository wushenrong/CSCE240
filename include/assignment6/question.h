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

#include "program6classes_export.h"

class Question {
 private:
  std::string question_;

 public:
  PROGRAM6CLASSES_EXPORT
  explicit Question(std::string_view question = "?") : question_{question} {}
  PROGRAM6CLASSES_EXPORT
  virtual ~Question() = default;

 protected:
  PROGRAM6CLASSES_EXPORT
  Question(const Question&) = default;
  PROGRAM6CLASSES_EXPORT
  Question(Question&&) = default;

  PROGRAM6CLASSES_EXPORT
  Question& operator=(const Question&) = default;
  PROGRAM6CLASSES_EXPORT
  Question& operator=(Question&&) = default;

 public:
  [[nodiscard]]
  PROGRAM6CLASSES_EXPORT const std::string& GetQuestion() const {
    return question_;
  }

  PROGRAM6CLASSES_EXPORT
  void SetQuestion(std::string_view question) { question_ = question; }

  PROGRAM6CLASSES_EXPORT
  virtual void Print(bool show_answer) const = 0;
};

#endif  // ASSIGNMENT6_QUESTION_H_
