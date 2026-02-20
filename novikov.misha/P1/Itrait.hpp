#ifndef NOVIKOV_ITRAIT_HPP
#define NOVIKOV_ITRAIT_HPP

#include <cstddef>

namespace novikov
{

  class ITrait
  {
  public:
    virtual ~ITrait() = default;
    virtual size_t operator()() const = 0;
    virtual void operator()(int) = 0;
  };

}

#endif
