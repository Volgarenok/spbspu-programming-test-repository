#ifndef KARPENKOV_AFT_MAX_HPP
#define KARPENKOV_AFT_MAX_HPP
#include "seqProperty.hpp"
#include <iostream>
namespace karpenkov {
  class AftMax final : public ISeqProperty {
    size_t afterMax;
    int maxNumber;
    size_t count;
    void process(int num) override;
    size_t res() const override;
  };
}
#endif
