#include "grt_lss.hpp"


void kachura::GrtLss::upd(int a)
{
  if (central_ < last_ && central_ > a && last_ != 0 && central_ != 0)
  {
    ++count_;
  }
  last_ = central_;
  central_ = a;
}

size_t kachura::GrtLss::result() const
{
  return count_;
}

const char* kachura::GrtLss::name() const
{
  return "grt-lss";
}
