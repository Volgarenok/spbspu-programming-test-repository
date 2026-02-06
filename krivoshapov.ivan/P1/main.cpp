#include <iostream>

namespace krivoshapov {
  int calculate_inc_seq() {
    int count = 0;
    int prev;
    int curr;
    
    if (!(std::cin >> prev) || prev == 0) {
      return 0;
    }
    
    while (std::cin >> curr && curr != 0) {
      if (curr > prev) {
        count++;
      }
      prev = curr;
    }
    
    return count;
  }
}

int main() {
  int result = krivoshapov::calculate_inc_seq();
  
  if (!std::cin) {
    std::cerr << "Error: invalid input sequence\n";
    return 1;
  }
  
  std::cout << result << "\n";
  return 0;
}