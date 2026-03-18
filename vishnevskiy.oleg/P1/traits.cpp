#include "traits.hpp"
#include <stdexcept>
#include <iostream>
#include <limits>

namespace traits
{
  grtLss::grtLss():
    count_(0),
    first_(std::numeric_limits<int>::min()),
    second_(std::numeric_limits<int>::min()),
    third_(std::numeric_limits<int>::min())
  {}

  void grtLss::process(int a)
  {
    first_ = second_;
    second_ = third_;
    third_ = a;
    if (first_ > second_ && second_ > third_)
    {
      count_++;
    }
  }
  size_t grtLss::result() const
  {
    if (count_ == 0)
    {
      throw std::logic_error("Error : sequence is too short");
    }
    return count_;
  }

  monDec::monDec():
    tempCount_(1),
    mcount_(0),
    curr_(std::numeric_limits<int>::min()),
    prev_(std::numeric_limits<int>::min())
  {}

  void monDec::process(int a)
  {
    prev_ = curr_;
    curr_ = a;
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
  size_t monDec::result() const
  {
    if (mcount_ == 0)
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
    catch(const std::bad_alloc &e)
    {
      std::cerr << e.what() << "\n";
      delete g;
      delete m;
      throw;
    }
    p[0] = g;
    p[1] = m;
  }
}
