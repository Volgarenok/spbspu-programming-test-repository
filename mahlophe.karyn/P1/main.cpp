#include <iostream>
#include <cstdlib>

namespace mahlophe {

void run() {
    int prev, curr;
    
    // Read first number
    if (!(std::cin >> prev)) {
        std::cerr << "Error: Invalid input" << std::endl;
        std::exit(1);
    }
    if (prev == 0) {
        std::cerr << "Error: Sequence too short" << std::endl;
        std::exit(2);
    }

    // Read second number
    if (!(std::cin >> curr)) {
        std::cerr << "Error: Invalid input" << std::endl;
        std::exit(1);
    }
    if (curr == 0) {
        std::cerr << "Error: Sequence too short" << std::endl;
        std::exit(2);
    }

    // Check if second is greater than first
    int count = (curr > prev) ? 1 : 0;
    int next_val;

    // Read the rest of the sequence
    while (std::cin >> next_val) {
        if (next_val == 0) {
            break; // End of sequence
        }
       
