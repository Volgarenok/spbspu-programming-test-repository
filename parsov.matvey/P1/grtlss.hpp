#ifndef GRTLSS_HPP
#define GRTLSS_HPP

#include "iproperty.hpp"

namespace parsov {

  class GrtLss : public IProperty {
  public:
    GrtLss();
  private:
    size_t count_;
    int prev2_;
    int prev1_;
    size_t elements_seen_;
    size_t result() const override;
    void update(int value) override;
  };

}

#endif
