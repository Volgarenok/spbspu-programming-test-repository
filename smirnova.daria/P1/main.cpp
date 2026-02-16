#include <iostream>

namespace smirnova {

class InputReader {
public:
  InputReader():
    error_(false)
  {}
  
  bool readNext(int &value) {
    if (error_) {
      return false;
    }
    
    if (!(std::cin >> value)) {
      if (std::cin.eof()) {
        error_ = true;
        return false;
      }
      error_ = true;
      return false;
    }
    
    return true;
  }
  
  bool hasError() const {
    return error_;
  }
  
private:
  bool error_;
};

}

int main() {
  smirnova::InputReader reader;
  int value;
  
  while (reader.readNext(value)) {
    if (value == 0) {
      break;
    }
  }
  
  if (reader.hasError()) {
    std::cerr << "Error: Invalid input sequence" << std::endl;
    return 1;
  }
  
  std::cout << "0" << std::endl;
  
  return 0;
}
