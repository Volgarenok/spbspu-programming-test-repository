#include <iostream>

namespace nabieva
{
  struct maxCount {
    maxCount():
      hasElements_(false) {}
    void upd(int value)
    {
      if (!hasElements_) {
        hasElements_ = true;
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
    size_t result() const
    {
      return countMax_;
    }
    bool hasElements() const
    {
      return hasElements_;
    }
  private:
    int maxValue_;
    size_t countMax_;
    bool hasElements_;
  };
  struct maxDecreasingSequence {
    maxDecreasingSequence():
      maxLength_(0),
      hasElements_(false) {}
    void upd(int value)
    {
      if (!hasElements_) {
        hasElements_ = true;
        prevValue_ = value;
        currLength_ = 1;
      }
      else if (value <= prevValue_) {
        currLength_++;
      }
      else {
        currLength_ = 1;
      }
      prevValue_ = value;
      if (maxLength_ < currLength_) {
        maxLength_ = currLength_;
      }
    }
    size_t result() const
    {
      return maxLength_;
    }
  private:
    size_t currLength_;
    size_t maxLength_;
    int prevValue_;
    bool hasElements_;
  };
}
int main()
{
  using namespace nabieva;
  maxCount maxCounter;
  maxDecreasingSequence decLength;
  int a = 0;
  while (std::cin >> a) {
    if (a == 0) {
      break;
    }
    maxCounter.upd(a);
    decLength.upd(a);
  }
  if (!std::cin.eof() && std::cin.fail()) {
    std::cerr << "Error input";
    return 1;
  }
  if (!maxCounter.hasElements()) {
    std::cerr << "Error too short input" << std::endl;
    return 2;
  }
  std::cout << maxCounter.result() << "\n";
  std::cout << decLength.result() << "\n";
}
