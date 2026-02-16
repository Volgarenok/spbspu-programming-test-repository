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

class LocalMaxCounter {
public:
  LocalMaxCounter():
    prev_prev_(0),
    prev_(0),
    current_(0),
    count_(0),
    length_(0)
  {}
  
  void addValue(int value) {
    if (length_ >= 2) {
      prev_prev_ = prev_;
      prev_ = current_;
      current_ = value;
      
      if (prev_ > prev_prev_ && prev_ > current_) {
        count_++;
      }
    } else if (length_ == 1) {
      prev_ = current_;
      current_ = value;
    } else {
      current_ = value;
    }
    
    length_++;
  }
  
  int getCount() const {
    return count_;
  }
  
private:
  int prev_prev_;
  int prev_;
  int current_;
  int count_;
  int length_;
};

}

int main() {
  smirnova::InputReader reader;
  smirnova::LocalMaxCounter counter;
  
  int value;
  bool hasElements = false;
  
  while (reader.readNext(value)) {
    if (value == 0) {
      break;
    }
    hasElements = true;
    counter.addValue(value);
  }
  
  if (reader.hasError()) {
    std::cerr << "Error: Invalid input sequence" << std::endl;
    return 1;
  }
  
  if (!hasElements) {
    std::cerr << "Error: Empty sequence" << std::endl;
    return 2;
  }
  
  std::cout << counter.getCount() << std::endl;
  
  return 0;
}
