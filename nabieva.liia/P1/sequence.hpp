#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
#include <cstddef>

namespace nabieva
{
  struct MaxCount {
    MaxCount();
    void upd(int value);
    size_t result() const;
  private:
    int maxValue_;
    size_t countMax_;
  };

  struct MaxDecreasingSequence {
    MaxDecreasingSequence();
    void upd(int value);
    size_t result() const;
  private:
    size_t currLength_;
    size_t maxLength_;
    int prevValue_;
  };
}

#endif