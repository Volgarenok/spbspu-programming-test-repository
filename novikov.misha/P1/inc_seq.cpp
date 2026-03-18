#include "inc_seq.hpp"
#include <limits>

novikov::IncSeq::IncSeq():
  count_(0),
  total_(0),
  prev_(std::numeric_limits< int >::max())
{}

void novikov::IncSeq::operator()(int x)
{
  if (x == 0) {
    if (total_ < 2) {
      throw SequenceTooShortError(total_);
    }
  } else {
    if (x > prev_) {
      ++count_;
    }
    ++total_;
    prev_ = x;
  }
}

size_t novikov::IncSeq::operator()() const
{
  return count_;
}
