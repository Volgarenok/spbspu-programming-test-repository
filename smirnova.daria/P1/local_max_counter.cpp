#include "local_max_counter.hpp"
#include <limits>
#include <stdexcept>

smirnova::LocalMaxCounter::LocalMaxCounter():
  prev_prev_(std::numeric_limits< int >::max()),
  prev_(std::numeric_limits< int >::max()),
  current_(std::numeric_limits< int >::max()),
  count_(0),
  length_(0)
{}

void smirnova::LocalMaxCounter::addValue(int value)
{
  prev_prev_ = prev_;
  prev_ = current_;
  current_ = value;
  length_++;
  if (prev_ > prev_prev_ && prev_ > current_) {
    count_++;
  }
}

size_t smirnova::LocalMaxCounter::getCount() const
{
  if (length_ < 3) {
    throw std::logic_error("Sequence too short to calculate local maxima");
  }
  return count_;
}
