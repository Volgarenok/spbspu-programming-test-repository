#include "grt_lss.hpp"

#include <stdexcept>

void kachura::GrtLss::upd(int a)
{
  if (central_ < last_ && central_ > a)
  {
    ++count_;
  }
  last_ = central_;
  central_ = a;
  n_++;
}

size_t kachura::GrtLss::result() const
{
  if (n_ < 3)
  {
    throw std::runtime_error("sequence is too short");
  }
  return count_;
}

const char* kachura::GrtLss::name() const
{
  return "grt-lss";
}
