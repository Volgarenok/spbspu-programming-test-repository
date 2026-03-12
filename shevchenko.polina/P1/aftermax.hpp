#ifndef AFTERMAX_HPP
#define AFTERMAX_HPP

#include <cstddef>
#include <stdexcept>

namespace shevchenko
{
  struct AfterMax
  {
    AfterMax();
    void operator()(int a);
    size_t operator()() const;

  private:
    static const size_t max_size = 10000;
    int nums_[max_size];
    size_t size_;
    int max_;
    size_t lastMaxPos_;
    bool calculated_;

    void calculate();
};

}

#endif
