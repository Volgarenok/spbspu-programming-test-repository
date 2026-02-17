#ifndef SMIRNOVA_LOCAL_MAX_COUNTER_HPP
#define SMIRNOVA_LOCAL_MAX_COUNTER_HPP

namespace smirnova {

class LocalMaxCounter {
public:
  LocalMaxCounter();
  void addValue(int value);
  size_t getCount() const;
private:
  int prev_;
};

}

#endif
