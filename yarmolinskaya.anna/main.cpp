#include "io.hpp"
#include <iostream>

int main() {
  using namespace yarmolinskaya;

  const result_t res = compute(std::cin);

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
