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

#include <gsl/gsl>
#include <string>
#include <string_view>

#include "assignment5/SongRecording.h"

namespace csce240_programming_assignment_5 {

class StreamingTrack : public SongRecording {
 private:
  int num_of_streams_;
  int num_of_genres_;
  gsl::owner<std::string*> genres_;

 public:
  explicit StreamingTrack(std::string_view title = "untitled",
                          std::string_view artist = "unknown",
                          int track_length = 0, int num_of_artists = 1,
                          std::string_view genre = "pop",
                          int num_of_streams = 0);
  StreamingTrack(const StreamingTrack&);

  explicit StreamingTrack(const SongRecording&, std::string_view genre = "pop",
                          int num_of_streams = 0);

  ~StreamingTrack() override { delete[] genres_; }

  StreamingTrack& operator=(const StreamingTrack&);

  void SetStreams(int n);

  int GetStreams() const { return num_of_streams_; }
  int GetNumGenres() const { return num_of_genres_; }
  std::string GetGenre(int n = 1) const;

  void AddStreams(int n);
  void AddGenre(std::string_view genre);

  void RemoveGenre(std::string_view genre);

  bool IsGenre(std::string_view genre) const;
};

}  // namespace csce240_programming_assignment_5

#endif  // ASSIGNMENT5_STREAMINGTRACK_H_
