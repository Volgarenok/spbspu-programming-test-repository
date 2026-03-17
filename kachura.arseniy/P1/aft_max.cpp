#include "aft_max.hpp"
#include <stdexcept>

void kachura::AftMax::step(int * num)
{
  if(*num <= max_)
  {
    count_++;
  }
  else
  {
    max_ = *num;
    count_ = 0;
  }
}

int kachura::AftMax::get_count()
{
  if(lenght_ < 2)
  {
    throw std::runtime_error("Sequence is too short!");
    return 2;
  }
  return count_;
}
