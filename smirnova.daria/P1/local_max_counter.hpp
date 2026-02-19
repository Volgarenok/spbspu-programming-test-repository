#ifndef SMIRNOVA_LOCAL_MAX_COUNTER_HPP
#define SMIRNOVA_LOCAL_MAX_COUNTER_HPP

#include <cstddef>

namespace smirnova
{

class LocalMaxCounter
{
public:
  LocalMaxCounter();
  void addValue(int value);
  size_t getCount() const;

private:
  int prev_prev_;
  int prev_;
  int current_;
  size_t count_;
};

}

#endif
