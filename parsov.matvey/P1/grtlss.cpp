#include "grtlss.hpp"

parsov::GrtLss::GrtLss():
  count_(0),
  prev2_(0),
  prev1_(0),
  elements_seen_(0)
{}

size_t parsov::GrtLss::result() const
{
  return count_;
}

void parsov::GrtLss::update(int value)
{
  elements_seen_++;
  if (elements_seen_ >= 3) {
    if (prev2_ > prev1_ && prev1_ > value) {
      count_++;
    }
  }
  prev2_ = prev1_;
  prev1_ = value;
}
