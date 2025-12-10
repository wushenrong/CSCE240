/**
 * @file StreamingTrack.h
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ASSIGNMENT5_STREAMINGTRACK_H_
#define ASSIGNMENT5_STREAMINGTRACK_H_

#include "assignment5/SongRecording.h"
#include "program5classes_export.h"

namespace csce240_programming_assignment_5 {

class StreamingTrack : public SongRecording {
 private:
  int num_of_streams_;
  int num_of_genres_;
  gsl::owner<std::string*> genres_;

 public:
  PROGRAM5CLASSES_EXPORT
  explicit StreamingTrack(std::string_view title = "untitled",
                          std::string_view artist = "unknown",
                          int track_length = 0, int num_of_artists = 1,
                          std::string_view genre = "pop",
                          int num_of_streams = 0);
  PROGRAM5CLASSES_EXPORT
  StreamingTrack(const StreamingTrack&) PROGRAM5CLASSES_EXPORT;
  StreamingTrack(StreamingTrack&&);

  PROGRAM5CLASSES_EXPORT
  explicit StreamingTrack(const SongRecording&, std::string_view genre = "pop",
                          int num_of_streams = 0);
  PROGRAM5CLASSES_EXPORT
  explicit StreamingTrack(SongRecording&&, std::string_view genre = "pop",
                          int num_of_streams = 0);

  PROGRAM5CLASSES_EXPORT
  ~StreamingTrack() override { delete[] genres_; }

  PROGRAM5CLASSES_EXPORT
  StreamingTrack& operator=(const StreamingTrack&);
  PROGRAM5CLASSES_EXPORT
  StreamingTrack& operator=(StreamingTrack&&);

  [[nodiscard]]
  PROGRAM5CLASSES_EXPORT int GetStreams() const {
    return num_of_streams_;
  }
  [[nodiscard]]
  PROGRAM5CLASSES_EXPORT int GetNumGenres() const {
    return num_of_genres_;
  }
  [[nodiscard]]
  PROGRAM5CLASSES_EXPORT std::string GetGenre(int n = 1) const;

  PROGRAM5CLASSES_EXPORT
  void SetStreams(int n);

  PROGRAM5CLASSES_EXPORT
  void AddStreams(int n);
  PROGRAM5CLASSES_EXPORT
  void AddGenre(std::string_view genre);

  PROGRAM5CLASSES_EXPORT
  void RemoveGenre(std::string_view genre);

  [[nodiscard]]
  PROGRAM5CLASSES_EXPORT bool IsGenre(std::string_view genre) const;
};

}  // namespace csce240_programming_assignment_5

#endif  // ASSIGNMENT5_STREAMINGTRACK_H_
