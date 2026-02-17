#include "sign_change_counter.hpp"

smirnova::SignChangeCounter::SignChangeCounter():
  prev_value_(0),
  count_(0),
  has_prev_(false)
{}

void smirnova::SignChangeCounter::addValue(int value)
{
  if (has_prev_ && ((prev_value_ > 0) != (value > 0))) {
    count_++;
  }
  prev_value_ = value;
  has_prev_ = true;
}

size_t smirnova::SignChangeCounter::getCount() const
{
  return count_;
}
