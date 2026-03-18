#include "aft_max.hpp"

lukashevich::AfterMaxCount::AfterMaxCount():
  maxVal_(INT_MIN),
  maxPos_(-1),
  currPos_(0)
{}

void lukashevich::AfterMaxCount::processNext(int val)
{
  if (currPos_ == 0 || val > maxVal_) {
    maxVal_ = val;
    maxPos_ = currPos_;
  }
  currPos_++;
}

int lukashevich::AfterMaxCount::getCountAftMax() const
{
  if (!hasMax()) {
    return 2;
  }
  return currPos_ - maxPos_ - 1;
}

bool lukashevich::AfterMaxCount::hasMax() const
{
  return maxPos_ >= 0;
}
