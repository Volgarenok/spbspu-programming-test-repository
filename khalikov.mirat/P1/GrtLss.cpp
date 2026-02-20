#include "GrtLss.hpp"
#include <limits>
#include <stdexcept>

namespace khalikov
{
  GrtLss::GrtLss()
  {
    count_ = 0;
    res_ = 0;
    prev_ = std::numeric_limits< int >::min();
    next_ = std::numeric_limits< int >::min();
    act_ = std::numeric_limits< int >::min();
  }

  void GrtLss::operator()(int a)
  {
    prev_ = act_;
    act_ = next_;
    next_ = a;
    count_++;
    if ((act_ > next_) && (act_ < prev_))
    {
      res_++;
    }
  }

  int GrtLss::operator()()
  {
    if (count_ < 3)
    {
      throw std::runtime_error("Not enough numbers!");
    }
    return res_;
  }
}
