#include "count.hpp"
#include <stdexcept>

namespace lachugin
{
  Count::Count():
    count_(0)
  {}

  void Count::next(int)
  {
    ++count_;
  }

  size_t Count::res() const
  {
    if (count_ < 2)
    {
      throw std::logic_error("insufficient sequence length");
    }
    return count_;
  }
}