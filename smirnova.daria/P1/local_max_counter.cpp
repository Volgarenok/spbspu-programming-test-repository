#include "local_max_counter.hpp"
#include <limits>

smirnova::LocalMaxCounter::LocalMaxCounter():
  prev_prev_(std::numeric_limits<int>::max()),
  prev_(std::numeric_limits<int>::max()),
  current_(std::numeric_limits<int>::max()),
  count_(0)
{}

void smirnova::LocalMaxCounter::addValue(int value)
{
  prev_prev_ = prev_;
  prev_ = current_;
  current_ = value;
  if (prev_ > prev_prev_ && prev_ > current_) {
    count_++;
  }
}

size_t smirnova::LocalMaxCounter::getCount() const
{
  return count_;
}
