#include <iostream>

namespace nabieva {
  struct MaxCount {
    MaxCount():
      maxValue_(0),
      countMax_(0) {}
    void upd(int value)
    {
      if (countMax_ == 0) {
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
      if (countMax_ == 0) {
        throw std::logic_error("Error too short input\n");
      }
      return countMax_;
    }
  private:
    int maxValue_;
    size_t countMax_;
  };

  struct MaxDecreasingSequence {
    MaxDecreasingSequence():
      currLength_(0),
      maxLength_(0),
      prevValue_(0) {}
    void upd(int value)
    {
      if (currLength_ == 0) {
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
  };
}

int main()
{
  using namespace nabieva;
  MaxCount maxCounter;
  MaxDecreasingSequence decLength;
  int a = 0;
  while (std::cin >> a && a != 0) {
    maxCounter.upd(a);
    decLength.upd(a);
  }
  if (!std::cin.eof() && std::cin.fail()) {
    std::cerr << "Error input";
    return 1;
  }
  try {
    std::cout << maxCounter.result() << "\n";
    std::cout << decLength.result() << "\n";
  } catch (const std::logic_error& e) {
    std::cerr << e.what();
    return 2;
  }
}
