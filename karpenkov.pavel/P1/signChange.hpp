#ifndef KARPENKOV_SIGN_CHANGE_HPP
#define KARPENKOV_SIGN_CHANGE_HPP
#include "seqProperty.hpp"
#include <iostream>

namespace karpenkov {
  class SignChange : public ISeqProperty {
  public:
    SignChange();
  private:
    size_t count;
    int currentSign, previousSign;
    bool isFirstNum;
    void process(int num) override;
    size_t res() const override;
  };
}
#endif
