#include "aftMax.hpp"
#include <limits>
#include <stdexcept>


  lachugin::AftMax::AftMax():
    size_(),
    count(0),
    max(std::numeric_limits< int >::min())
  {}

  void lachugin::AftMax::next(int value)
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

  size_t lachugin::AftMax::res() const
  {
    if (size_ < 2)
    {
      throw std::logic_error("Error numbs");
    }
    return count;
  }
