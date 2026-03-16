#ifndef PYTH_HPP
#define PYTH_HPP
#include <cstddef>

namespace emushintsev
{
  class PythCount
  {
    private:
    int a;
    int b;
    int c;
    size_t count;
    size_t numReceived;
    bool isPyth(int x, int y, int z) const;

    public:
    PythCount();
    void processNext(int val);
    size_t getCount() const;
  };
}
#endif
