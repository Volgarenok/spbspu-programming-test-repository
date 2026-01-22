#include "io.hpp"
#include <iostream>
#include <stdexcept>

#include "ITrait.hpp"

int input(ITrait** traits, int traitCount)
{
    int x;
    int totalAdded = 0;

    while (std::cin >> x)
    {
        if (x == 0) {
            while (std::cin.peek() == ' ' || std::cin.peek() == '\t')
              std::cin.get();
            int next = std::cin.peek();
            if (next == '\n') {
                if (totalAdded == 0) {
                  std::cerr << "Error: сannot identify       sequence\n";
                  return 2;
                }
                return 0;
            }
        }
        for (int i = 0; i < traitCount; ++i)
          traits[i]->add(x);
        totalAdded++;
    }

		if (std::cin.fail()) {
      std::cerr << "Error: failed to read data\n";
      return 1;
    }

    return 0;
}

void output(ITrait** traits, int traitCount)
{
    bool errorOccurred = false;
    for (int i = 0; i < traitCount; ++i)
    {
        if (traits[i] && traits[i]->computable()) {
            std::cout << i + 1 << " characteristic: " << traits[i]->value() << "\n";
        } else {
            std::cout << i + 1 << " characteristic: not enough data\n";
            errorOccurred = true;
        }
    }
}
