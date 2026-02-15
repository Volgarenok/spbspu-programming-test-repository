#include "aftMax.hpp"
#include <limits>

namespace lachugin
{
  AftMax::AftMax():
    count_(0),
    max_(std::numeric_limits<int>::min())
  {}

  void AftMax::next(int value)
  {
    if (value > max_)
    {
      max_ = value;
      count_ = 0;
    }
    else
    {
      ++count_;
    }
  }

  size_t AftMax::res() const
  {
    return count_;
  }
}