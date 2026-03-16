#include <iostream>
#include <algorithm>
#include <climits>
#include <istream>

namespace yarmolinskaya {
  struct result_t {
    bool inputValid;
    bool subMaxValid;
    int subMax;
    int eqlSeq;
  };

  result_t compute(std::istream & in)
  {
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
    int value = 0;
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
      } else if (value < maxVal) {
        secondMax = std::max(secondMax, value);
        hasSecond = true;
      }
      if (!hasPrev) {
        currentRun = 1;
        maxRun = 1;
        hasPrev = true;
      } else if (value == prev) {
        currentRun++;
        maxRun = std::max(maxRun, currentRun);
      } else {
        currentRun = 1;
      }
      prev = value;
    }

    if (!zeroFound) {
      res.inputValid = false;
      return res;
    }

    int extra = 0;
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

int main()
{
  const yarmolinskaya::result_t res = yarmolinskaya::compute(std::cin);
  if (!res.inputValid) {
    std::cerr << "Error: input cannot be identified as a valid integer sequence\n";
    return 1;
  }

  int exitCode = 0;
  if (res.subMaxValid) {
    std::cout << "SUB-MAX: " << res.subMax << "\n";
  } else {
    std::cerr << "Error: SUB-MAX requires at least 2 distinct elements\n";
    exitCode = 2;
  }

  std::cout << "EQL-SEQ: " << res.eqlSeq << "\n";
  return exitCode;
}
