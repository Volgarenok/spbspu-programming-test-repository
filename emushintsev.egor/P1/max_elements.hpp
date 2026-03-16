#ifndef MAX_ELEMENTS_HPP
#define MAX_ELEMENTS_HPP
#include <climits>

namespace emushintsev
{
    class MaxElements
    {
    private:
        int max1;
        int max2;
        bool hasMax1;
        bool hasMax2;

    public:
        MaxElements();
        void processNext(int val);
        int getMax1() const;
        int getMax2() const;
        bool hasTwo() const;
    };
}
#endif
