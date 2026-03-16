#ifndef KACHURA_AFT_MAX_HPP
#define KACHURA_AFT_MAX_HPP

#include <limits>

#include "itrait.hpp"

namespace kachura {
  struct AftMax: ITrait {
    AftMax():
      count_(0),
      max_(std::numeric_limits< int >::max()),
      n_(0)
    {}

  private:
    size_t count_;
    int max_;
    size_t n_;

    void upd(int a) override;
    size_t result() const override;
    const char* name() const override;
  };
}

#endif