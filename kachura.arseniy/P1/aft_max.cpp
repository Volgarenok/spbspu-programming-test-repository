#include "aft_max.hpp"

void kachura::AftMax::step(int * num)
{
  if(*num <= max_)
  {
    count_ += 1;
  }
  else
  {
    max_ = *num;
    count_ = 0;
  }
}

int kachura::AftMax::get_count()
{
  return count_;
}
