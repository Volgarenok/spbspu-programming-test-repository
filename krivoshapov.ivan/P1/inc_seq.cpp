#include <limits>

#include "inc_seq.hpp"

krivoshapov::IncSeq::IncSeq():
  count_(0),
  prev_(std::numeric_limits< int >::max())
{}

size_t krivoshapov::IncSeq::operator()() const
{
  return count_;
}

void krivoshapov::IncSeq::operator()(int a)
{
  if (a > prev_)
  {
    ++count_;
  }
  prev_ = a;
}
