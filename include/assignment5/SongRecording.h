/**
 * @file SongRecording.h
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ASSIGNMENT5_SONGRECORDING_H_
#define ASSIGNMENT5_SONGRECORDING_H_

#include <gsl/gsl>
#include <string>
#include <string_view>

#include "program5classes_export.h"

namespace csce240_programming_assignment_5 {

class SongRecording {
 private:
  std::string title_{"untitled"};
  int track_length_{0};
  int num_of_artists_{1};
  gsl::owner<std::string*> artists_;

 public:
  PROGRAM5CLASSES_EXPORT
  SongRecording(std::string_view = "untitled",
                std::string_view artist = "unknown", int track_length = 0,
                int num_of_artists = 1);
  PROGRAM5CLASSES_EXPORT
  SongRecording(const SongRecording&);
  PROGRAM5CLASSES_EXPORT
  SongRecording(SongRecording&&) noexcept;

  PROGRAM5CLASSES_EXPORT
  virtual ~SongRecording() { delete[] artists_; }

  PROGRAM5CLASSES_EXPORT
  auto operator=(const SongRecording&) -> SongRecording&;
  PROGRAM5CLASSES_EXPORT
  auto operator=(SongRecording&&) noexcept -> SongRecording&;

  [[nodiscard]]
  PROGRAM5CLASSES_EXPORT auto GetTitle() const -> const std::string& {
    return title_;
  }
  [[nodiscard]]
  PROGRAM5CLASSES_EXPORT auto GetTrackLength() const -> int {
    return track_length_;
  }
  [[nodiscard]]
  PROGRAM5CLASSES_EXPORT auto GetNumArtists() const -> int {
    return num_of_artists_;
  }
  [[nodiscard]]
  PROGRAM5CLASSES_EXPORT auto GetArtist(int n = 1) const -> std::string;

  PROGRAM5CLASSES_EXPORT
  void SetTitle(std::string_view title);
  PROGRAM5CLASSES_EXPORT
  void SetTrackLength(int track_length);
  PROGRAM5CLASSES_EXPORT
  void SetNumArtists(int num_of_artists);
  PROGRAM5CLASSES_EXPORT
  void SetArtist(std::string_view artist, int n = 1);
};

}  // namespace csce240_programming_assignment_5

#endif  // ASSIGNMENT5_SONGRECORDING_H_
