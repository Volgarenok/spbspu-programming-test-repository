#include "div_rem.hpp"

krivoshapov::DivRem::DivRem():
  count_(0),
  prev_(0),
  is_first_(true)
{}

size_t krivoshapov::DivRem::operator()() const
{
  return count_;
}

void krivoshapov::DivRem::operator()(int a)
{
  if (is_first_)
  {
    is_first_ = false;
  }
  else if (a % prev_ == 0)
  {
    ++count_;
  }
  prev_ = a;
}
