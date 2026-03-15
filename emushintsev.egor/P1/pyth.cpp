#include "pyth.hpp"

namespace emushintsev {
    PythCount::PythCount():
    a(0), b(0), c(0), count(0), numReceived(0) {}

    void PythCount::processNext(int val) {
        a = b;
        b = c;
        c = val;
        numReceived++;
        if(numReceived >= 3) {
            if(isPyth(a, b, c)) {
                count++;
            }
        }
    }

    bool PythCount::isPyth(int x, int y, int z) const {
        return (x * x + y * y == z * z);
    }

    size_t PythCount::getCount() const {
        return count;
    }
}
