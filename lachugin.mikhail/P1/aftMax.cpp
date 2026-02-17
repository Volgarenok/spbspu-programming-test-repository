#include "aftMax.hpp"
#include <limits>

namespace lachugin
{
  AftMax::AftMax():
    count(0),
    max(std::numeric_limits<int>::min()),
    size_()
  {}

  void AftMax::next(int value)
  {
    size_++;
    if (value > max)
    {
      max = value;
      count = 0;
    }
    else
    {
      ++count;
    }
  }

  size_t AftMax::res() const
  {
    return count;
  }
}
