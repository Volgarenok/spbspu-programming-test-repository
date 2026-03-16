#include "seq.hpp"

#include <algorithm>
#include <climits>

int yarmolinskaya::updateSubMax(const int value, const int maxVal, int &secondMax, bool &hasSecond)
{
  if (value > maxVal) {
    if (maxVal != INT_MIN) {
      secondMax = maxVal;
      hasSecond = true;
    }
    return value;
  }
  if (value < maxVal) {
    secondMax = std::max(secondMax, value);
    hasSecond = true;
  }
  return maxVal;
}

void yarmolinskaya::updateEqlSeq(const int value, const int prev, int &currentRun, int &maxRun)
{
  if (value == prev) {
    ++currentRun;
    if (currentRun > maxRun) {
      maxRun = currentRun;
    }
  } else {
    currentRun = 1;
  }
}
