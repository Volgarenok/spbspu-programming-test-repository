#include "aft_max.hpp"

namespace lukashevich
{
  void AfterMaxCount::processNext(int val)
  {
    if (currPos == 0 || val > maxVal) {
      maxVal = val;
      maxPos = currPos;
    }
    currPos++;
  }

  int AfterMaxCount::getCountAftMax() const
  {
    if (!hasMax()) {
      return 2;
    }
    return currPos - maxPos - 1;
  }

  bool AfterMaxCount::hasMax() const
  {
    return maxPos >= 0;
  }
}