#include <iostream>
#include "DivRem.hpp"

namespace alisov
{
  DivRem::DivRem():
    count_(0),
    total_(0),
    prev_(0)
  {}

  void DivRem::operator()(int a)
  {
    total_++;

    if (prev_ != 0 && a % prev_ == 0)
    {
      count_++;
    }

    prev_ = a;
  }

  int DivRem::operator()() const
  {
    if (total_ < 2)
    {
      throw std::exception();
    }

    return count_;
  }
}