# include "grt_lss.hpp"

void kachura::GrtLss::step(int * num)
{
  if(central_ < last_ && *num > central_ && central_ != 0 && last_ != 0)
  {
    count_++;
  }
  last_ = central_;
  central_ = *num;
}

int kachura::GrtLss::get_count()
{
  return count_;
}