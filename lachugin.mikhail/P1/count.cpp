#include "count.hpp"
#include <stdexcept>

namespace lachugin
{
  Count::Count():
    count(0)
  {}

  void Count::next(int)
  {
    ++count;
  }

  size_t Count::res() const
  {
    if (count < 2)
    {
      throw std::logic_error("insufficient sequence length");
    }
    return count;
  }
}