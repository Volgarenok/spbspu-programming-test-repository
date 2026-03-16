#include "qrt_lss.hpp"

void kachura::QrtLss::upd(int a)
{
  if (central_ < prev_ && central_ > a)
  {
    ++count_;
  }
  prev_ = central_;
  central_ = a;
  n_++;
}

size_t kachura::QrtLss::result() const
{
  if (n_ < 3)
  {
    throw std::runtime_error("sequence is too short");
  }
  return count_;
}

const char* kachura::QrtLss::name() const
{
  return "inc-seq";
}