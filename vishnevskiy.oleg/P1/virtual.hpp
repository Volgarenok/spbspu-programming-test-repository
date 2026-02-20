#ifndef VIRTUAL_HPP
#define VIRTUAL_HPP
#include <cstddef>

namespace traits
{
  struct ITrait
  {
    virtual ~ITrait() = default;
    virtual void operator()(int a);
    virtual size_t operator()() const;
   private:
    virtual void process(int a) = 0;
    virtual size_t result() const = 0;
  };
}

#endif
