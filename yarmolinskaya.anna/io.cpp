#include "io.hpp"
#include <cctype>
#include <climits>

namespace yarmolinskaya {

result_t compute(std::istream& in) {
  result_t res{};
  res.inputValid = true;
  res.subMaxValid = false;
  res.subMax = 0;
  res.eqlSeq = 0;

  int max = INT_MIN;
  int secondMax = INT_MIN;

  int prev = 0;
  bool hasPrev = false;
  std::size_t currentRun = 1;
  std::size_t maxRun = 0;

  int val = 0;
  bool zeroFound = false;

  while (in >> val) {
    if (val == 0) {
      zeroFound = true;
      break;
    }

    int next = in.peek();
    if (next != EOF && !std::isspace(static_cast<unsigned char>(next))) {
      res.inputValid = false;
      return res;
    }

    if (val > max) {
      secondMax = max;
      max = val;
    } else if (val > secondMax && val != max) {
      secondMax = val;
    }

    if (!hasPrev) {
      hasPrev = true;
      currentRun = 1;
      maxRun = 1;
    } else if (val == prev) {
      ++currentRun;
      if (currentRun > maxRun) {
        maxRun = currentRun;
      }
    } else {
      currentRun = 1;
    }

    prev = val;
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

  if (!in.eof()) {
    res.inputValid = false;
    return res;
  }

  if (secondMax != INT_MIN) {
    res.subMaxValid = true;
    res.subMax = secondMax;
  }

  res.eqlSeq = static_cast<int>(maxRun);
  return res;
}

}
