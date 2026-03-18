#include "DivRem.hpp"

#include <stdexcept>

void shigarev::DivRem::process(int val)
{
  if (prev_ != 0) {
    hasMinLen_ = true;
    if (val % prev_ == 0) {
      count_++;
    }
  }
  prev_ = val;
}

std::size_t shigarev::DivRem::count() const
{
  if (!hasMinLen_) {
    throw std::logic_error("sequence too short for DIV-REM");
  }
  return count_;
}
