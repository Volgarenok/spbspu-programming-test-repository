#ifndef KACHURA_GRT_LSS_HPP
#define KACHURA_GRT_LSS_HPP

#include <limits>

#include "itrait.hpp"

namespace kachura {
  struct GrtLss: ITrait {
    GrtLss():
      count_(0),
      last_(0),
      central_(0)
    {}

  private:
    size_t count_;
    int last_;
    int central_;

    void upd(int a) override;
    size_t result() const override;
    const char* name() const override;
  };
}

#endif
