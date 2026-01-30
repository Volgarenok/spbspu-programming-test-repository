#include <iostream>

int main() {
    int prev, curr;
    if (!(std::cin >> prev) || prev == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int max_len = 1;
    int curr_len = 1;

    while (std::cin >> curr && curr != 0) {
        if (curr >= prev) {
            curr_len++;
        } else {
            curr_len = 1;
        }

        if (curr_len > max_len) {
            max_len = curr_len;
        }
        prev = curr;
    }

    std::cout << max_len << std::endl;
    return 0;
}