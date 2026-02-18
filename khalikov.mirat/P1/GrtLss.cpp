#include "GrtLss.hpp"
#include <limits>
#include <stdexcept>

namespace khalikov
{
  GrtLss::GrtLss()
  {
    c_ = 0;
    k_ = 0;
    prev_ = std::numeric_limits<int>::max();;
    next_ = std::numeric_limits<int>::min();;
    act_ = 0;
  }

  void GrtLss::operator()(int a)
  {
    prev_ = act_;
    act_ = next_;
    next_ = a;
    c_++;
    if ((act_ > next_) && (act_ < prev_))
    {
      k_++;
    }
  }

  int GrtLss::operator()()
  {
    if (c_ < 3)
    {
      throw std::runtime_error("Not enough numbers!");
    }
    else
    {
      return k_;
    }
  }
}
