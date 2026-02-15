#ifndef LACHUGIN_COUNT_HPP
#define LACHUGIN_COUNT_HPP
#include "property.hpp"

namespace lachugin
{
  struct Count: SeqProperty
  {
    Count();
  private:
    void next(int value) override;
    size_t res() const override;
    size_t count;
  };
}

#endif
