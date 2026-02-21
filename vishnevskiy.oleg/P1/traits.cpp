#include "traits.hpp"
#include <stdexcept>

namespace traits
{
  void grtLss::process(int a)
  {
    first_ = second_;
    second_ = third_;
    third_ = a;
    if (f_ < 2)
    {
      f_++;
    }
    else
    {
      if (first_ > second_ && second_ > third_)
      {
        count_++;
      }
    }
  }
  size_t grtLss::result() const
  {
    if (f_ < 2)
    {
      throw std::logic_error("Error : sequence is too short");
    }
    return count_;
  }

  void monDec::process(int a)
  {
    prev_ = curr_;
    curr_ = a;
    if (f_ == 0)
    {
      tempCount_ = 1;
      f_ = 1;
    }
    else
    {
      f_ = 2;
      if (prev_ >= curr_)
      {
        tempCount_++;
      }
      else
      {
        tempCount_ = 1;
      }
      if (tempCount_ > mcount_)
      {
        mcount_ = tempCount_;
      }
    }
  }
  size_t monDec::result() const
  {
    if (f_ != 2)
    {
      throw std::logic_error("Error : sequence is too short");
    }
    return mcount_;
  }

  void traitCreate(ITrait *p[2])
  {
    grtLss *g = nullptr;
    monDec *m = nullptr;
    try
    {
      g = new grtLss;
      m = new monDec;
    }
    catch(...)
    {
      delete g;
      delete m;
      throw;
    }
    p[0] = g;
    p[1] = m;
  }
}
