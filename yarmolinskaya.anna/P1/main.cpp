#include "sequence.hpp"

#include <climits>
#include <iostream>

int main()
{
  int a = 0;
  int b = 0;

  if (!(std::cin >> a)) {
    std::cerr << "Error: input cannot be identified as a valid integer sequence\n";
    return 1;
  }

  if (a == 0) {
    std::cerr << "Error: SUB-MAX requires at least 2 distinct elements\n";
    std::cout << 0 << "\n";
    return 2;
  }

  if (!(std::cin >> b)) {
    std::cerr << "Error: input cannot be identified as a valid integer sequence\n";
    return 1;
  }

  if (b == 0) {
    std::cerr << "Error: SUB-MAX requires at least 2 distinct elements\n";
    std::cout << 1 << "\n";
    return 2;
  }

  int maxVal = INT_MIN;
  int secondMax = INT_MIN;
  bool hasSecond = false;
  int currentRun = 1;
  int maxRun = 1;

  maxVal = yarmolinskaya::updateSubMax(a, maxVal, secondMax, hasSecond);
  maxVal = yarmolinskaya::updateSubMax(b, maxVal, secondMax, hasSecond);
  yarmolinskaya::updateEqlSeq(b, a, currentRun, maxRun);
  a = b;

  while (std::cin >> b) {
    if (b == 0) {
      break;
    }
    maxVal = yarmolinskaya::updateSubMax(b, maxVal, secondMax, hasSecond);
    yarmolinskaya::updateEqlSeq(b, a, currentRun, maxRun);
    a = b;
  }

  if (std::cin.fail()) {
    std::cerr << "Error: input cannot be identified as a valid integer sequence\n";
    return 1;
  }

  int exitCode = 0;

  if (hasSecond) {
    std::cout << secondMax << "\n";
  } else {
    std::cerr << "Error: SUB-MAX requires at least 2 distinct elements\n";
    exitCode = 2;
  }

  std::cout << maxRun << "\n";

  return exitCode;
}
