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

namespace csce240_programming_assignment_5 {

class SongRecording {
 private:
  std::string title_;
  int track_length_;
  int num_of_artists_;
  gsl::owner<std::string*> artists_;

 public:
  SongRecording(std::string_view = "untitled",
                std::string_view artist = "unknown", int track_length = 0,
                int num_of_artists = 1);
  SongRecording(const SongRecording&);

  virtual ~SongRecording() { delete[] artists_; }

  SongRecording& operator=(const SongRecording&);

  void SetTitle(std::string_view title);
  void SetNumArtists(int num_of_artists);
  void SetTrackLength(int track_length);
  void SetArtist(std::string_view artist, int n = 1);

  std::string GetTitle() const { return title_; }
  int GetNumArtists() const { return num_of_artists_; }
  int GetTrackLength() const { return track_length_; }
  std::string GetArtist(int n = 1) const;
};

}  // namespace csce240_programming_assignment_5

#endif  // ASSIGNMENT5_SONGRECORDING_H_
