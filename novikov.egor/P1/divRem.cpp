#include "divRem.hpp"

size_t novikov::div_rem::operator()() const
{
  return res;
}

void novikov::div_rem::operator()(int num)
{
  if (is_first_try) {
    late_num = num;
    is_first_try = false;
  } else {
    if (num % late_num == 0) {
      res++;
    }
  }
  late_num = num;
}
