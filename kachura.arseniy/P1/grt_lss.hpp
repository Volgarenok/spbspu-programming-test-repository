#ifndef KACHURA_GRT_LSS_HPP
#define KACHURA_GRT_LSS_HPP

#include <limits>

#include "itrait.hpp"

namespace kachura {
  struct GrtLss: ITrait {
    GrtLss():
      count_(0),
      last_(std::numeric_limits< int >::max()),
      central_(std::numeric_limits< int >::max())
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
