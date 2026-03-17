#include "grt_lss.hpp"

void kachura::GrtLss::step(int * num)
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

int kachura::GrtLss::get_count()
{
  return count_;
}