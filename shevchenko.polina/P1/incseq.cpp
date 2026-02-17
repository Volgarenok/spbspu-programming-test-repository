#include "incseq.hpp"

namespace shevchenko
{

IncSeq::IncSeq() : count_(0), prev_(0), first_(true) {}

void IncSeq::operator()(int a)
{
  if (!first_)
  {
    if (a > prev_) count_++;
  }
  else
  {
    first_ = false;
  }
  prev_ = a;
}

size_t IncSeq::operator()() const
{
  return count_;
}

}
