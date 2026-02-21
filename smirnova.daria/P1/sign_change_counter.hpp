#ifndef SMIRNOVA_SIGN_CHANGE_COUNTER_HPP
#define SMIRNOVA_SIGN_CHANGE_COUNTER_HPP

#include <cstddef>

namespace smirnova {
  class SignChangeCounter
  {
  public:
    SignChangeCounter();
    void addValue(int value);
    size_t getCount() const;

  private:
    int prev_value_;
    size_t count_;
    bool has_prev_;
  };
}

#endif
