#include "EvenCount.hpp"

namespace alisov
{
  EvenCount::EvenCount():
    current_(0),
    max_(0)
  {}

  void EvenCount::operator()(int a)
  {
    if (a % 2 == 0)
    {
      current_++;
      if (current_ > max_)
      {
        max_ = current_;
      }
    }
    else
    {
      current_ = 0;
    }
  }

  int EvenCount::operator()() const
  {
    return max_;
  }
}
