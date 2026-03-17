#include <iostream>
#include "Itrait.hpp"
#include "inc_seq.hpp"
#include "evn_cnt.hpp"

void destroy(novikov::ITrait* traits[])
{
  delete traits[0];
  delete traits[1];
}

int main()
{
  const size_t funcs_count = 2;
  novikov::ITrait* funcs[funcs_count] = {nullptr, nullptr};

  try {
    funcs[0] = new novikov::IncSeq();
    funcs[1] = new novikov::EvnCnt();
  } catch (const std::bad_alloc&) {
    std::cerr << "Error: memory allocation failed\n";
    destroy(funcs);
    return 1;
  }

  int x = 0;
  size_t numbers_read = 0;

  try {
    while (std::cin >> x) {
      ++numbers_read;
      for (size_t i = 0; i < funcs_count; ++i) {
        (*funcs[i])(x);
      }
      if (x == 0) {
        break;
      }
    }
  } catch (const novikov::SequenceTooShortError& e) {
    if (e.get_total() == 0) {
      std::cout << "0\n0\n";
    } else {
      std::cerr << "Error: sequence too short for INC-SEQ\n";
      std::cout << "0\n" << (*funcs[1])() << '\n';
    }
    destroy(funcs);
    return (e.get_total() == 0) ? 0 : 2;
  }

  if (std::cin.fail() && !std::cin.eof()) {
    std::cerr << "Error: invalid input\n";
    destroy(funcs);
    return 1;
  }

  if (numbers_read == 0) {
    std::cout << "0\n0\n";
    destroy(funcs);
    return 0;
  }

  for (size_t i = 0; i < funcs_count; ++i) {
    std::cout << (*funcs[i])() << '\n';
  }

  destroy(funcs);
  return 0;
}
