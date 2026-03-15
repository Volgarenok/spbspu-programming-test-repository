#include "div_rem.hpp"

#include <stdexcept>

void krivoshapov::DivRem::upd(int a)
{
  if (a % prev_ == 0)
  {
    ++count_;
  }
  prev_ = a;
  ++n_;
}

size_t krivoshapov::DivRem::result() const
{
  if (n_ < 2)
  {
    throw std::runtime_error("sequence is too short");
  }
  return count_;
}

const char* krivoshapov::DivRem::name() const
{
  return "div-rem";
}
