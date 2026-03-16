#include <iostream>
#include "Itrait.hpp"
#include "inc_seq.hpp"
#include "evn_cnt.hpp"

int main()
{
  using namespace novikov;

  const size_t funcs_count = 2;
  ITrait * funcs[funcs_count];

  try {
    funcs[0] = new IncSeq();
    funcs[1] = new EvnCnt();
  } catch (const std::bad_alloc &) {
    std::cerr << "Error: memory allocation failed\n";
    return 1;
  }

  int x = 0;
  try {
    while (std::cin >> x) {
      for (size_t i = 0; i < funcs_count; ++i) {
        (*funcs[i])(x);
      }
      if (x == 0) {
        break;
      }
    }
  } catch (const SequenceTooShortError & e) {
    if (e.get_total() == 0) {
      std::cout << "0\n0\n";
    } else {
      std::cerr << "Error: sequence too short for INC-SEQ\n";
      std::cout << "0\n" << (*funcs[1])() << '\n';
    }
    for (size_t i = 0; i < funcs_count; ++i) {
      delete funcs[i];
    }
    return (e.get_total() == 0) ? 0 : 2;
  }

  if (std::cin.fail() && !std::cin.eof()) {
    std::cerr << "Error: invalid input\n";
    for (size_t i = 0; i < funcs_count; ++i) {
      delete funcs[i];
    }
    return 1;
  }

  for (size_t i = 0; i < funcs_count; ++i) {
    std::cout << (*funcs[i])() << '\n';
  }

  for (size_t i = 0; i < funcs_count; ++i) {
    delete funcs[i];
  }

  return 0;
}
