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
#include <utility>

using std::size_t;
using std::string;
using std::string_view;

namespace csce240_programming_assignment_5 {

SongRecording::SongRecording(string_view title, string_view artist,
                             int track_length, int num_of_artists)
    : title_{title},
      track_length_{track_length},
      num_of_artists_{num_of_artists},
      artists_{new string[static_cast<size_t>(num_of_artists_)]} {
  SetArtist(!artist.empty() ? artist : "unknown");
}

SongRecording::SongRecording(const SongRecording& rhs)
    : title_{rhs.title_},
      track_length_{rhs.track_length_},
      num_of_artists_{rhs.num_of_artists_},
      artists_{new string[static_cast<size_t>(rhs.num_of_artists_)]} {
  for (int i = 0; i < num_of_artists_; ++i) {
    artists_[i] = rhs.artists_[i];
  }
}

SongRecording::SongRecording(SongRecording&& rhs) noexcept
    : title_{std::move(rhs.title_)},
      track_length_{rhs.track_length_},
      num_of_artists_{rhs.num_of_artists_},
      artists_{rhs.artists_} {
  rhs.title_ = "";
  rhs.track_length_ = 0;
  rhs.num_of_artists_ = 0;
  rhs.artists_ = nullptr;
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

  num_of_artists_ = rhs.num_of_artists_;
  artists_ = new string[static_cast<size_t>(rhs.num_of_artists_)];

  for (int i = 0; i < rhs.num_of_artists_; ++i) {
    artists_[i] = rhs.artists_[i];
  }

  return *this;
}

auto SongRecording::operator=(SongRecording&& rhs) noexcept -> SongRecording& {
  // Make sure that the object does not overwrite itself when assignment itself.
  if (this == &rhs) {
    return *this;
  }

  // Copy over the title and track length.
  SetTitle(rhs.title_);
  SetTrackLength(rhs.track_length_);

  // If we already have a list of artist, then delete it and move the pointer
  // from the object that was assigned from
  delete[] artists_;

  num_of_artists_ = rhs.num_of_artists_;
  artists_ = rhs.artists_;

  rhs.title_ = "";
  rhs.track_length_ = 0;
  rhs.num_of_artists_ = 0;
  rhs.artists_ = nullptr;

  return *this;
}

auto SongRecording::GetArtist(int n) const -> string {
  if (n > 0 && n <= num_of_artists_) {
    return artists_[n - 1];
  }

  return "out of bounds";
}

void SongRecording::SetTitle(string_view title) {
  if (!title.empty()) {
    title_ = title;
  }
}

void SongRecording::SetTrackLength(int track_length) {
  if (track_length >= 0) {
    track_length_ = track_length;
  }
}

void SongRecording::SetNumArtists(int num_of_artists) {
  if (num_of_artists < 1) {
    return;
  }

  // If the number of artists do not match, create a new list of artists and
  // copy over the old artists if the new list fits. Else do nothing.
  if (num_of_artists != num_of_artists_) {
    gsl::owner<string*> temp = artists_;
    artists_ = new string[static_cast<size_t>(num_of_artists)];

    for (int i = 0; i < num_of_artists; ++i) {
      artists_[i] = temp[i];
    }

    delete[] temp;
    temp = nullptr;
  }

  num_of_artists_ = num_of_artists;
}

void SongRecording::SetArtist(string_view artist, int n) {
  if (n > 0 && n <= num_of_artists_ && !artist.empty()) {
    artists_[n - 1] = artist;
  }
}

}  // namespace csce240_programming_assignment_5
