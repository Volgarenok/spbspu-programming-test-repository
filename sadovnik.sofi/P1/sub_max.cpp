#include "sub_max.hpp"

namespace sadovnik
{

  SubMaxCount::SubMaxCount()
    : cnt(0)
    , max1(0)
    , max2(0)
    , has_max2(false)
  {
  }

  void SubMaxCount::operator()(int x)
  {
    if (cnt == 0)
    {
      max1 = x;
    }
    else if (x > max1)
    {
      max2 = max1;
      max1 = x;
      has_max2 = true;
    }
    else if (!has_max2)
    {
      max2 = x;
      has_max2 = true;
    }
    else if (x > max2)
    {
      max2 = x;
    }
    ++cnt;
  }

  size_t SubMaxCount::operator()() const
  {
    return static_cast<size_t>(max2);
  }

  bool SubMaxCount::valid() const
  {
    return cnt >= 2;
  }

}
