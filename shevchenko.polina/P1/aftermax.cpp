#include "aftermax.hpp"
#include <climits>

namespace shevchenko
{
  AfterMax::AfterMax(): size_(0), max_(INT_MIN), lastMaxPos_(0), calculated_(false) {}

  void AfterMax::operator()(int a)
  {
    if (size_ < max_size)
    {
      nums_[size_++] = a;

      if (size_ == 1 || a > max_)
      {
        max_ = a;
        lastMaxPos_ = size_ - 1;
      }
      else if (a == max_)
      {
        lastMaxPos_ = size_ - 1;
      }
    }
  }

  void AfterMax::calculate()
  {
    if (calculated_) return;
    if (size_ == 0)
    {
      throw std::logic_error("empty sequence");
    }

    max_ = nums_[0];
    for (size_t i = 1; i < size_; i++)
    {
      if (nums_[i] > max_)
      {
        max_ = nums_[i];
      }
    }

    lastMaxPos_ = 0;
    for (size_t i = size_ - 1; i > 0; i--)
    {
      if (nums_[i] == max_)
      {
        lastMaxPos_ = i;
        break;
      }
    }

    calculated_ = true;
  }

  size_t AfterMax::operator()() const
  {
    return size_ - lastMaxPos_ - 1;
  }

}
