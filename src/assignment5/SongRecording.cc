/**
 * @file SongRecording.cc
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "assignment5/SongRecording.h"

#include <cstddef>
#include <gsl/gsl>
#include <string>
#include <string_view>

using std::string;
using std::string_view;

namespace csce240_programming_assignment_5 {

SongRecording::SongRecording(string_view title, string_view artist,
                             int track_length, int num_of_artists)
    : title_{"untitled"},
      track_length_{0},
      num_of_artists_{1},
      artists_{nullptr} {
  SetTitle(title);
  SetNumArtists(num_of_artists);
  SetTrackLength(track_length);

  if (artists_ == nullptr) {
    artists_ = new string[static_cast<size_t>(num_of_artists_)];
  }

  SetArtist(!artist.empty() ? artist : "unknown");
}

SongRecording::SongRecording(const SongRecording& rhs)
    : title_{rhs.title_},
      track_length_{rhs.track_length_},
      num_of_artists_{rhs.num_of_artists_},
      artists_{nullptr} {
  SetNumArtists(num_of_artists_);

  for (int i = 0; i < num_of_artists_; ++i) {
    artists_[i] = rhs.artists_[i];
  }
}

auto SongRecording::operator=(const SongRecording& rhs) -> SongRecording& {
  // Make sure that the object does not overwrite itself when assignment itself.
  if (this == &rhs) {
    return *this;
  }

  // Copy over the title and track length.
  SetTitle(rhs.title_);
  SetTrackLength(rhs.track_length_);

  // If we already have a list of artist, then delete it and create a new one so
  // we can manually copy the list of artist from the object that was assigned
  // from.
  delete[] artists_;
  artists_ = nullptr;

  SetNumArtists(rhs.num_of_artists_);

  for (int i = 0; i < rhs.num_of_artists_; ++i) {
    artists_[i] = rhs.artists_[i];
  }

  return *this;
}

void SongRecording::SetTitle(string_view title) {
  if (!title.empty()) {
    title_ = title;
  }
}

void SongRecording::SetNumArtists(int num_of_artists) {
  if (num_of_artists < 1) {
    return;
  }

  // If we do not have a list of artists then create one. Otherwise if the
  // number of artists do not match, create a new list of artists and copy over
  // the old artists if the new list fits. Else do nothing.
  if (artists_ == nullptr) {
    artists_ = new string[static_cast<size_t>(num_of_artists)];
  } else if (num_of_artists != num_of_artists_) {
    gsl::owner<string*> temp = artists_;
    artists_ = new string[static_cast<size_t>(num_of_artists)];

    for (int i = 0; i < num_of_artists && i < num_of_artists_; ++i) {
      artists_[i] = temp[i];
    }

    delete[] temp;
    temp = nullptr;
  }

  num_of_artists_ = num_of_artists;
}

void SongRecording::SetTrackLength(int track_length) {
  if (track_length >= 0) {
    track_length_ = track_length;
  }
}

void SongRecording::SetArtist(string_view artist, int n) {
  if (n > 0 && n <= num_of_artists_ && !artist.empty()) {
    artists_[n - 1] = artist;
  }
}

auto SongRecording::GetArtist(int n) const -> string {
  if (n > 0 && n <= num_of_artists_) {
    return artists_[n - 1];
  }

  return "out of bounds";
}

}  // namespace csce240_programming_assignment_5
