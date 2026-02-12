#include <iostream>
//CNT-MAX MON-DEC

struct maxCount {
  maxCount() : countMax_(0), hasElement_(false) {}
  void upd(int value) {
    if (!hasElement_) {
      hasElement_ = true;
      maxValue_ = value;
      countMax_ = 1;
    }
    else if (value > maxValue_) {
      maxValue_ = value;
      countMax_ = 1;
    }
    else if (value == maxValue_) {
      ++countMax_;
    }
  }
  size_t result() const {
    return countMax_;
  }
  bool hasElement() const {
    return hasElement_;
  }
private:
  int maxValue_;
  size_t countMax_;
  bool hasElement_;
};

int main()
{
  int a = 0;
  maxCount maxCounter;
  while (std::cin >> a) {
    if (a == 0) {
      break;
    }
    maxCounter.upd(a);
  }
  if (!std::cin.eof() && std::cin.fail()) {
    std::cerr << "Error input";
    return 1;
  }
  if (!maxCounter.hasElement()) {
    std::cerr << "Error too short input" << std::endl;
    return 2;
  }
  std::cout << maxCounter.result() << "\n";
}
