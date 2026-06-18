#include <iostream>

int main() {
    int previous;
    if (!(std::cin >> previous) || previous == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int current;
    int max_count = 1;
    int current_count = 1;

    while (std::cin >> current && current != 0) {
        if (current == previous) {
            current_count++;
        } else {
            current_count = 1;
        }

        if (current_count > max_count) {
            max_count = current_count;
        }
        
        previous = current;
    }

    std::cout << max_count << std::endl;
    return 0;
}
