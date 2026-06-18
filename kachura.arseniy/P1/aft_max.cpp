#include "aft_max.hpp"

void kachura::AftMax::step(int * const num)
{
  if (* num <= max_)
  {
    count_++;
  }
  else
  {
    max_ = * num;
    count_ = 0;
  }
  lenght_++;
}

int kachura::AftMax::getCount() const
{
  if (lenght_ < 2)
  {
    //Всё равно для grt_lss будет мало
    throw "Sequence is too short!\nGrt_Lss: Sequence is too short!";
  }
  return count_;
}
