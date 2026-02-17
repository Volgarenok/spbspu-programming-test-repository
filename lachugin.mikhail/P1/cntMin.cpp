#include "cntMin.hpp"
#include <limits>

namespace lachugin
{
  CntMin::CntMin():
    count(0),
    min(std::numeric_limits<int>::max()),
    size_()
  {}

  void CntMin::next(int value)
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

  size_t CntMin::res() const
  {
    return count;
  }
}
