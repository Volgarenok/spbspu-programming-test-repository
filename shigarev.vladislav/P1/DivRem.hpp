#ifndef SHIGAREV_DIV_REM_HPP
#define SHIGAREV_DIV_REM_HPP

#include <cstddef>

namespace shigarev {

  class DivRem {
  public:
    void process(int val);
    std::size_t count() const;

  private:
    int prev_ = 0;
    bool hasMinLen_ = false;
    std::size_t count_ = 0;
  };

}

#endif
