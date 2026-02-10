#include "Size.hpp"
#include <stdexcept>

namespace khalikov
{
  Size::Size()
  {
    k_ = 0;
  }
  void Size::operator()(int)
    {
      k_++;
    }
  int Size::operator()()
  {
    if (k_ < 3)
    {
      throw std::runtime_error("Not enough numbers!");
    }
    else
    {
      return k_;
    }
  }
}
