#include "cntMin.hpp"
#include <limits>
#include <stdexcept>

  lachugin::CntMin::CntMin():
    size_(),
    count(0),
    min(std::numeric_limits< int >::max())
  {}

  void lachugin::CntMin::next(int value)
  {
    size_++;
    if (value < min)
    {
      min = value;
      count = 1;
    }
    else if (value == min)
    {
      ++count;
    }
  }

  size_t lachugin::CntMin::res() const
  {
    if (size_ < 2)
    {
      throw std::logic_error("Error numbs");
    }
    return count;
  }
}
