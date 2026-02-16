#ifndef KARPENKOV_AFT_MAX_HPP
#define KARPENKOV_AFT_MAX_HPP
#include "seqProperty.hpp"
#include <iostream>
namespace karpenkov {
  class AftMax : public ISeqProperty {
  public:
    AftMax();

  private:
    size_t afterMax;
    int maxNumber;
    void process(int num) override;
    size_t res() const override;
  };
}
#endif
