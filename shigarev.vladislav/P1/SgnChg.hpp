#ifndef SHIGAREV_SGN_CHG_HPP
#define SHIGAREV_SGN_CHG_HPP

#include <cstddef>

namespace shigarev {

  class SgnChg {
  public:
    void process(int val);
    std::size_t count() const;

  private:
    int prevSign_ = 0;
    std::size_t count_ = 0;
  };

}

#endif
