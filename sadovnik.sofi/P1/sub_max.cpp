#include "sub_max.h"

namespace sadovnik
{

SubMaxCount::SubMaxCount()
  : cnt_(0)
  , max1_(0)
  , max2_(0)
  , has_max2_(false)
{
}

void SubMaxCount::operator()(int x)
{
  if (cnt_ == 0)
  {
    max1_ = x;
  }
  else if (x > max1_)
  {
    max2_ = max1_;
    max1_ = x;
    has_max2_ = true;
  }
  else if (!has_max2_)
  {
    max2_ = x;
    has_max2_ = true;
  }
  else if (x > max2_)
  {
    max2_ = x;
  }
  ++cnt_;
}

size_t SubMaxCount::operator()() const
{
  return static_cast<size_t>(max2_);
}

bool SubMaxCount::valid() const
{
  return cnt_ >= 2;
}

}
