#include <iostream>
#include <cstddef>

namespace parsov {

  void MonInc(int value, size_t &max_len, size_t &cur_len, int &prev, bool &is_fst)
  {
    if (is_fst) {
      cur_len = 1;
      max_len = 1;
      prev = value;
      is_fst = false;
    } else {
      if (value >= prev) {
        cur_len++;
      } else {
        cur_len = 1;
      }
      if (cur_len > max_len) {
        max_len = cur_len;
      }
      prev = value;
    }
  }

  void GrtLss(int value, size_t &count, int &p2, int &p1, size_t &seen)
  {
    seen++;
    if (seen >= 3) {
      if (p2 > p1 && p1 > value) {
        count++;
      }
    }
    p2 = p1;
    p1 = value;
  }

}

int main()
{
  int err = 0;
  int value = 0;

  size_t max_length = 0;
  size_t current_length = 0;
  int prev_val = 0;
  bool is_first = true;

  size_t count = 0;
  int prev2 = 0;
  int prev1 = 0;
  size_t elements_seen = 0;

  while (std::cin >> value && value != 0) {
    parsov::MonInc(value, max_length, current_length, prev_val, is_first);
    parsov::GrtLss(value, count, prev2, prev1, elements_seen);
  }

  if (!std::cin.eof() && std::cin.fail()) {
    std::cerr << "Bad input\n";
    return 1;
  }

  bool can_calc_m = true;
  bool can_calc_g = true;

  if (can_calc_m) {
    std::cout << max_length << "\n";
  } else {
    std::cerr << "Error\n";
    if (err == 0) {
      err = 2;
    }
  }

  if (can_calc_g) {
    std::cout << count << "\n";
  } else {
    std::cerr << "Error\n";
    if (err == 0) {
      err = 2;
    }
  }

  return err;
}
