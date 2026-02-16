#include <iostream>
#include <cstring>
#include <string>

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

class SignChangeCounter {
public:
  SignChangeCounter():
    prev_value_(0),
    count_(0),
    has_prev_(false)
  {}

  void addValue(int value) {
    if (has_prev_) {
      bool prev_positive = prev_value_ > 0;
      bool curr_positive = value > 0;

      if (prev_positive != curr_positive) {
        count_++;
      }
    }

    prev_value_ = value;
    has_prev_ = true;
  }

  int getCount() const {
    return count_;
  }

private:
  int prev_value_;
  int count_;
  bool has_prev_;
};

}

void solveS7() {
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
    exit(1);
  }

  if (!hasElements) {
    std::cerr << "Error: Empty sequence" << std::endl;
    exit(2);
  }

  std::cout << counter.getCount() << std::endl;
}

void solveS9() {
  smirnova::InputReader reader;
  smirnova::SignChangeCounter counter;

  int value;

  while (reader.readNext(value)) {
    if (value == 0) {
      break;
    }
    counter.addValue(value);
  }

  if (reader.hasError()) {
    std::cerr << "Error: Invalid input sequence" << std::endl;
    exit(1);
  }

  std::cout << counter.getCount() << std::endl;
}

int main(int argc, char *argv[]) {
  std::string mode;
  
  if (argc == 2) {
    mode = argv[1];
  } else {
    int mode_int;
    if (std::cin >> mode_int) {
      mode = (mode_int == 7) ? "s7" : "s9";
    } else {
      std::cerr << "Usage: " << argv[0] << " <s7|s9>" << std::endl;
      return 1;
    }
  }

  if (mode == "s7") {
    solveS7();
  } else if (mode == "s9") {
    solveS9();
  } else {
    std::cerr << "Error: Unknown task '" << mode << "'" << std::endl;
    std::cerr << "Available tasks: s7, s9" << std::endl;
    return 1;
  }

  return 0;
}
