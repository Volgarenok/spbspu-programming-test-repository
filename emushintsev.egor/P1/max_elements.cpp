#include "max_elements.hpp"

namespace emushintsev
{
    MaxElements::MaxElements() : max1(INT_MIN), max2(INT_MIN), hasMax1(false), hasMax2(false) {}

    void MaxElements::processNext(int val)
    {
        if (!hasMax1)
        {
            max1 = val;
            hasMax1 = true;
        }
        else if (val > max1)
        {
            max2 = max1;
            max1 = val;
            hasMax2 = true;
        }
        else if (val < max1)
        {
            if (!hasMax2 || val > max2)
            {
                max2 = val;
                hasMax2 = true;
            }
        }
    }
    int MaxElements::getMax1() const
    {
        return max1;
    }
    int MaxElements::getMax2() const
    {
        return max2;
    }
    bool MaxElements::hasTwo() const
    {
        return hasMax2;
    }
}
