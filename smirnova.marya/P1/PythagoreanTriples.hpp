#ifndef PYTHAGOREANTRIPLES_HPP
#define PYTHAGOREANTRIPLES_HPP

#include "ITrait.hpp"

class PythagoreanTriples final : public ITrait {
public:
    PythagoreanTriples();
protected:
    bool do_add(int value) override;
public:
    int value() const override;
    bool computable() const override;
private:
  int a = 0, b = 0, count = 0, size = 0;
  bool pyCheck(int x, int y, int z) const;
};

#endif
