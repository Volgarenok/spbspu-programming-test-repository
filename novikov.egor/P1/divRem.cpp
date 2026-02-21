#include "divRem.hpp"

novikov::div_rem::div_rem():
  is_first_try(true),
  late_num(0),
  res(0)
{}

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
