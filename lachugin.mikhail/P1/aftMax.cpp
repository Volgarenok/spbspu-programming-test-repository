#include "aftMax.hpp"
#include <limits>
#include <stdexcept>

namespace lachugin
{
  AftMax::AftMax():
    size_(),
    count(0),
    max(std::numeric_limits< int >::min())
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
    if (size_ < 2)
    {
      throw std::logic_error("Error numbs");
    }
    return count;
  }
}
