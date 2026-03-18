#include <cerrno>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>

namespace shigarev {

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
