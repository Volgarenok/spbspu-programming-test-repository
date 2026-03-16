#include <iostream>
#include <climits>
#include <algorithm>

namespace yarmolinskaya
{
  struct Result
  {
    bool inputValid_ = true;
    bool subMaxValid_ = false;
    int subMax_ = 0;
    int eqlSeq_ = 0;
  };

  void updateSubMax(int value, int &maxVal, int &secondMax, bool &hasSecond)
  {
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
  }

  void updateEqualSeq(int value, int prev, bool hasPrev,
                      int &currentRun, int &maxRun)
  {
    if (!hasPrev) {
      currentRun = 1;
      maxRun = 1;
    }
    else if (value == prev) {
      ++currentRun;
      maxRun = std::max(maxRun, currentRun);
    }
    else {
      currentRun = 1;
    }
  }

  Result process(std::istream &in)
  {
    Result res;

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
        res.inputValid_ = false;
        return res;
      }

      if (value == 0) {
        zeroFound = true;
        break;
      }

      updateSubMax(value, maxVal, secondMax, hasSecond);
      updateEqualSeq(value, prev, hasPrev, currentRun, maxRun);

      prev = value;
      hasPrev = true;
    }

    if (!zeroFound) {
      res.inputValid_ = false;
      return res;
    }

    int extra;
    if (in >> extra) {
      res.inputValid_ = false;
      return res;
    }

    if (hasSecond) {
      res.subMaxValid_ = true;
      res.subMax_ = secondMax;
    }

    res.eqlSeq_ = maxRun;
    return res;
  }
}

int main(int argc, char * /* argv */[])
{
  if (argc != 1) {
    std::cerr << "Error: program does not accept command line arguments\n";
    return 1;
  }

  const yarmolinskaya::Result res = yarmolinskaya::process(std::cin);

  if (!res.inputValid_) {
    std::cerr << "Error: input cannot be identified as a valid integer sequence\n";
    return 2;
  }

  int exitCode = 0;

  if (res.subMaxValid_) {
    std::cout << "SUB-MAX: " << res.subMax_ << "\n";
  }
  else {
    std::cerr << "Error: SUB-MAX requires at least 2 distinct elements\n";
    exitCode = 2;
  }

  std::cout << "EQL-SEQ: " << res.eqlSeq_ << "\n";

  return exitCode;
}
