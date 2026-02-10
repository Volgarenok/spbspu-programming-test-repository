#include "LocMin.hpp"

namespace khalikov
{
  LocMin::LocMin()
  {
    k_ = 0;
    prev_ = 0;
    next_ = 0;
    act_ = 0;
    firstadd_ = true;
  }

  void LocMin::operator()(int a)
  {
    if (firstadd_)
    {
      prev_ = a;
      act_ = a;
      next_ = a;
      firstadd_ = false;
    }
    else
    {
      prev_ = act_;
      act_ = next_;
      next_ = a;
      if ((act_ < next_) && (act_ < prev_))
      {
        k_++;
      }
    }
  }

  int LocMin::operator()()
  {
    return k_;
  }
}
