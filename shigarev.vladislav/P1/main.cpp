#include <cerrno>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>

namespace shigarev {

    bool readToken(char * buf)
    {
        return std::scanf("%299s", buf) == 1;
    }

    bool parseInteger(const char * buf, int & val)
    {
        char * end = nullptr;
        errno = 0;
        const long parsed = std::strtol(buf, &end, 10);
        if (end == buf || *end != '\0' || errno == ERANGE) {
            return false;
        }
        val = static_cast< int >(parsed);
        return true;
    }

    int sign(const int val)
    {
        return (val > 0) - (val < 0);
    }

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
        void process
