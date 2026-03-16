#ifndef ALISOV_ITRAIT_HPP
#define ALISOV_ITRAIT_HPP

namespace alisov
{
  struct ITrait
  {
    virtual void operator()(int a) = 0;
    virtual int operator()() const = 0;
    virtual ~ITrait() = default;
  };
}

#endif
