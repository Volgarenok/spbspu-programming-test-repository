#ifndef KRIVOSHAPOV_ITRAIT_HPP
#define KRIVOSHAPOV_ITRAIT_HPP

#include <cstddef>

namespace krivoshapov
{
  struct ITrait
  {
    void operator()(int a)
    {
      upd(a);
    }

    size_t operator()() const
    {
      return result();
    }

    const char *trait() const
    {
      return name();
    }

    virtual ~ITrait() = default;

  private:
    virtual void upd(int a) = 0;
    virtual size_t result() const = 0;
    virtual const char *name() const = 0;
  };
}

#endif
