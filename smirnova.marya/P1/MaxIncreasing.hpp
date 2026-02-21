#ifndef MAXINCREASING_HPP
#define MAXINCREASING_HPP

#include "ITrait.hpp"

class MaxIncreasing final : public ITrait {
public:
  MaxIncreasing();
protected:
  bool do_add(int value) override;
public:
  int value() const override;
  bool computable() const override;
private:
  int last, current, maximum;
  bool hasValue;
};

#endif
