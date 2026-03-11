#include "io.hpp"
#include <climits>
#include <algorithm>

namespace yarmolinskaya {

result_t compute(std::istream& in) {
  result_t res{};
  res.inputValid = true;
  res.subMaxValid = false;
  res.subMax = 0;
  res.eqlSeq = 0;

  int maxVal = INT_MIN;
  int secondMax = INT_MIN;
  bool hasSecond = false;

  int prev = 0;
  bool hasPrev = false;

  int currentRun = 0;
  int maxRun = 0;

  int value;
  bool zeroFound = false;

  while (true) {
    if (!(in >> value)) {
      res.inputValid = false;
      return res;
    }

    if (value == 0) {
      zeroFound = true;
      break;
    }

    if (value > maxVal) {
      secondMax = maxVal;
      maxVal = value;
      if (secondMax != INT_MIN) {
        hasSecond = true;
      }
    } 
    else if (value < maxVal) {
      secondMax = std::max(secondMax, value);
      hasSecond = true;
    }

    if (!hasPrev) {
      currentRun = 1;
      maxRun = 1;
      hasPrev = true;
    } 
    else if (value == prev) {
      currentRun++;
      maxRun = std::max(maxRun, currentRun);
    } 
    else {
      currentRun = 1;
    }

    prev = value;
  }

  if (!zeroFound) {
    res.inputValid = false;
    return res;
  }

  int extra;
  if (in >> extra) {
    res.inputValid = false;
    return res;
  }

  if (hasSecond) {
    res.subMaxValid = true;
    res.subMax = secondMax;
  }

  res.eqlSeq = maxRun;

  return res;
}

}
