/**
 * @file StreamingTrack.cc
 * @author Samuel Wu
 *
 * @version 0.0.0
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "assignment5/StreamingTrack.h"

#include <cstddef>
#include <gsl-lite/gsl-lite.hpp>
#include <string>
#include <string_view>
#include <utility>

#include "assignment5/SongRecording.h"

using std::string;
using std::string_view;

namespace csce240_programming_assignment_5 {

StreamingTrack::StreamingTrack(string_view title, string_view artist,
                               int track_length, int num_of_artists,
                               string_view genre, int num_of_streams)
    : SongRecording{title, artist, track_length, num_of_artists},
      num_of_streams_{num_of_streams},
      num_of_genres_{0},
      genres_{nullptr} {
  AddGenre(genre);
}

StreamingTrack::StreamingTrack(const StreamingTrack& rhs)
    : SongRecording{rhs},
      num_of_streams_{rhs.num_of_streams_},
      num_of_genres_{0},
      genres_{nullptr} {
  for (int i = 0; i < rhs.num_of_genres_; ++i) {
    AddGenre(rhs.genres_[i]);
  }
}

StreamingTrack::StreamingTrack(const SongRecording& rhs, string_view genre,
                               int num_of_streams)
    : SongRecording{rhs},
      num_of_streams_{0},
      num_of_genres_{0},
      genres_{nullptr} {
  SetStreams(num_of_streams);
  AddGenre(genre);
}

StreamingTrack::StreamingTrack(StreamingTrack&& rhs) noexcept
    : SongRecording{std::move(rhs)},
      num_of_streams_{rhs.num_of_streams_},
      num_of_genres_{rhs.num_of_genres_},
      genres_{rhs.genres_} {
  rhs.num_of_genres_ = 0;
  rhs.genres_ = nullptr;
}

StreamingTrack::StreamingTrack(SongRecording&& rhs, string_view genre,
                               int num_of_streams) noexcept
    : SongRecording{std::move(rhs)},
      num_of_streams_{0},
      num_of_genres_{0},
      genres_{nullptr} {
  SetStreams(num_of_streams);
  AddGenre(genre);
}

StreamingTrack& StreamingTrack::operator=(const StreamingTrack& rhs) {
  // Make sure that the object does not overwrite itself when assignment itself.
  if (this == &rhs) {
    return *this;
  }

  // Call the base copy assignment operator for copying members from
  // SongRecording.
  SongRecording::operator=(rhs);

  // Copy the num of times that the track has been stream
  SetStreams(rhs.num_of_streams_);

  // Delete the current list of genres if we have any and manually copy the
  // genre over.
  delete[] genres_;
  genres_ = nullptr;
  num_of_genres_ = 0;

  for (int i = 0; i < rhs.num_of_genres_; ++i) {
    AddGenre(rhs.genres_[i]);
  }

  return *this;
}

StreamingTrack& StreamingTrack::operator=(StreamingTrack&& rhs) noexcept {
  // Make sure that the object does not overwrite itself when assignment itself.
  if (this == &rhs) {
    return *this;
  }

  // Call the base copy assignment operator for copying members from
  // SongRecording.
  SongRecording::operator=(std::move(rhs));

  // Get the num of times that the track has been stream
  SetStreams(rhs.num_of_streams_);

  // Delete the current list of genres if we have any and manually move the
  // genre over.
  delete[] genres_;
  num_of_genres_ = rhs.num_of_genres_;
  genres_ = rhs.genres_;

  rhs.num_of_streams_ = 0;
  rhs.num_of_genres_ = 0;
  rhs.genres_ = nullptr;

  return *this;
}

string StreamingTrack::GetGenre(int n) const {
  if (n > 0 && n <= num_of_genres_) {
    return genres_[n - 1];
  }

  return "out of bounds";
}

void StreamingTrack::SetStreams(int n) {
  if (n >= 0) {
    num_of_streams_ = n;
  }
}

void StreamingTrack::AddStreams(int n) {
  if (n >= 0) {
    num_of_streams_ += n;
  }
}

void StreamingTrack::AddGenre(string_view genre) {
  if (IsGenre(genre)) {
    return;
  }

  // If the steaming track already has genres, create a new list of genres, copy
  // the old list and append our new genre to the list, then replace the old
  // list with our newlist. Otherwise if the track has no genre, create and add
  // the genre to the new list.
  if (genres_ != nullptr) {
    gsl_lite::owner<string*> temp = genres_;
    genres_ = new string[static_cast<size_t>(num_of_genres_ + 1)];

    for (int i = 0; i < num_of_genres_; ++i) {
      genres_[i] = temp[i];
    }

    delete[] temp;
    temp = nullptr;
  } else {
    genres_ = new string[static_cast<size_t>(num_of_genres_ + 1)];
  }

  genres_[num_of_genres_] = genre;
  ++num_of_genres_;
}

void StreamingTrack::RemoveGenre(string_view genre) {
  if (!IsGenre(genre)) {
    return;
  }

  // If the steaming track has multiple genres then save the current list of
  // genres, create a new list of genres and copy over the old genres without
  // the genre that we want to remove. Otherwise if the track only has one
  // genre, delete the list and make sure that the list is pointing to nothing
  // and there are no genres assigned to the track.
  if (num_of_genres_ > 1) {
    gsl_lite::owner<string*> temp = genres_;
    genres_ = new string[static_cast<size_t>(num_of_genres_ - 1)];

    for (int i = 0, j = 0; i < num_of_genres_ && j < num_of_genres_ - 1; ++i) {
      if (temp[i] == genre) {
        continue;
      }

      genres_[j] = temp[i];

      ++j;
    }

    delete[] temp;
    temp = nullptr;

    --num_of_genres_;
  } else {
    delete[] genres_;
    genres_ = nullptr;
    num_of_genres_ = 0;
  }
}

bool StreamingTrack::IsGenre(string_view genre) const {
  for (int i = 0; i < num_of_genres_; ++i) {
    if (genres_[i] == genre) {
      return true;
    }
  }

  return false;
}

}  // namespace csce240_programming_assignment_5
