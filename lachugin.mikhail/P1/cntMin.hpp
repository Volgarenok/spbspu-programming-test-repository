#ifndef LACHUGIN_CNT_MIN_HPP
#define LACHUGIN_CNT_MIN_HPP

#include "property.hpp"

namespace lachugin
{
  class CntMin: public SeqProperty
  {
  public:
    CntMin();

  private:
    void next(int value) override;
    size_t res() const override;

    size_t count;
    int min;
  };
}

#endif
