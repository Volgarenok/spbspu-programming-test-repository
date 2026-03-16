#include "aft_max.hpp"

#include <stdexcept>

void kachura::AftMax::upd(int a)
{
  if (a > max_)
  {
    max_ = a;
    count_ = 0;
  }
  else
  {
    count_++;
  }
  n_++;
}

size_t kachura::AftMax::result() const
{
  if (n_ == 0)
  {
    throw std::runtime_error("sequence is too short");
  }
  return count_;
}

const char* kachura::AftMax::name() const
{
  return "aft-max";
}
