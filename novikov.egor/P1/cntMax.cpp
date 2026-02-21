#include "cntMax.hpp"

novikov::cnt_max::cnt_max():
  counter(0),
  biggest(0),
  res(0)
{}

size_t novikov::cnt_max::operator()() const
{
  return res;
}

void novikov::cnt_max::operator()(int num)
{
  if (counter == 0) {
    biggest = num;
    counter++;
  } else if (biggest < num) {
    biggest = num;
    res = 1;
  } else if (biggest == num) {
    res++;
  }
}
