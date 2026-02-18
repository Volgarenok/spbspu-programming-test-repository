#include <cerrno>
#include <cstdio>
#include <cstdlib>

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

}

int main()
{
    return 0;
}
