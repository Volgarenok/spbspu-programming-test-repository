#include <cerrno>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>

namespace shigarev {
    class SgnChg {
    public:
        void process(const int val)
        {
            const int cur = sign(val);
            if (prevSign_ != 0 && cur != 0 && cur != prevSign_) {
                count_++;
            }
            if (cur != 0) {
                prevSign_ = cur;
            }
        }

        size_t count() const
        {
            return count_;
        }

    private:
        int prevSign_ = 0;
        size_t count_ = 0;
    };

    class DivRem {
    public:
        void process(const int val)
        {
            if (hasPrev_ && prev_ != 0 && val % prev_ == 0) {
                count_++;
            }
            prev_ = val;
            hasPrev_ = true;
            seqLen_++;
        }

        bool canCompute() const
        {
            return seqLen_ >= 2;
        }

        size_t count() const
        {
            return count_;
        }

    private:
        int prev_ = 0;
        bool hasPrev_ = false;
        size_t count_ = 0;
        size_t seqLen_ = 0;
    };

}

int main()
{
    shigarev::SgnChg sgnChg;
    shigarev::DivRem divRem;

    if (!shigarev::processInput(sgnChg, divRem)) {
        return 1;
    }

    return shigarev::printResults(sgnChg, divRem);
}
