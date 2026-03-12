#include "aft_max.hpp"

namespace sadovnik
{

  AftMaxCount::AftMaxCount()
    : max(0)
    , found(false)
    , after(0)
  {
  }

  void AftMaxCount::operator()(int x)
  {
    if (!found)
    {
      max = x;
      found = true;
      after = 0;
    }
    else if (x > max)
    {
      max = x;
      after = 0;
    }
    else
    {
      ++after;
    }
  }

  size_t AftMaxCount::operator()() const
  {
    return after;
  }

}
