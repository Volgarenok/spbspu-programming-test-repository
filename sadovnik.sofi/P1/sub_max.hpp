#ifndef SUB_MAX_HPP
#define SUB_MAX_HPP

#include <cstddef>
#include <limits>

namespace sadovnik
{
  class SubMaxCount 
  {
  public:
    SubMaxCount();
    void operator()(int x);
    int operator()() const;

  private:
    size_t cnt_;
    int max1_;
    int max2_;
    bool valid() const;
  };
}

#endif
