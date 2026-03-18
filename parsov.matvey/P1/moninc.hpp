#ifndef MONINC_HPP
#define MONINC_HPP

#include "iproperty.hpp"

namespace parsov {

  class MonInc : public IProperty {
  public:
    MonInc();
  private:
    size_t max_length_;
    size_t current_length_;
    int prev_val_;
    bool is_first_;
    size_t result() const override;
    void update(int value) override;
  };

}

#endif
