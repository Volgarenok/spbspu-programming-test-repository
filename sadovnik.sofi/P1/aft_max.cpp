#include "aft_max.h"

namespace sadovnik
{

AftMaxCount::AftMaxCount()
  : max_(0)
  , found_(false)
  , after_(0)
{
}

void AftMaxCount::operator()(int x)
{
  if (!found_)
  {
    max_ = x;
    found_ = true;
    after_ = 0;
  }
  else if (x > max_)
  {
    max_ = x;
    after_ = 0;
  }
  else
  {
    ++after_;
  }
}

size_t AftMaxCount::operator()() const
{
  return after_;
}

}
