#ifndef LACHUGIN_AFT_MAX_HPP
#define LACHUGIN_AFT_MAX_HPP
#include "property.hpp"

namespace lachugin
{
  class AftMax final: public SeqProperty
  {
  public:
    AftMax();

  private:
    void next(int value) override;
    size_t res() const override;

    size_t size_;
    size_t count;
    int max;
  };
}

#endif
