#include "grt_lss.hpp"

void kachura::GrtLss::step(int * const num)
{
  if (central_ < last_ && * num < central_ && central_ != 0 && last_ != 0)
  {
    count_++;
  }
  last_ = central_;
  central_ = * num;
  lenght_++;
}

int kachura::GrtLss::getCount()
{
  if (lenght_ < 3)
  {
    throw "Sequence is too short!";
  }
  return count_;
}
