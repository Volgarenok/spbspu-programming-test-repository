#include <iostream>

namespace novikov {

  class IncSeq {
  public:
    void operator()(int x)
    {
      if (!first_ && x > prev_) {
        ++count_;
      }
      ++total_;
      prev_ = x;
      first_ = false;
    }

    size_t operator()() const
    {
      return count_;
    }

    size_t total() const
    {
      return total_;
    }

  private:
    size_t count_ = 0;
    size_t total_ = 0;
    int prev_ = 0;
    bool first_ = true;
  };

  class EvnCnt {
  public:
    void operator()(int x)
    {
      if (x % 2 == 0) {
        ++cur_;
        if (cur_ > max_) {
          max_ = cur_;
        }
      } else {
        cur_ = 0;
      }
    }

    size_t operator()() const
    {
      return max_;
    }

  private:
    size_t max_ = 0;
    size_t cur_ = 0;
  };

}

int main()
{
  using namespace novikov;

  IncSeq inc;
  EvnCnt evn;

  int x = 0;
  bool has_zero = false;

  while (std::cin >> x) {
    if (x == 0) {
      has_zero = true;
      break;
    }
    inc(x);
    evn(x);
  }

  if (std::cin.fail() && !std::cin.eof()) {
    std::cerr << "Error: invalid input\n";
    return 1;
  }

  if (!has_zero) {
    std::cerr << "Error: no terminating zero\n";
    return 1;
  }

  const size_t total = inc.total();

  if (total < 2) {
    std::cerr << "Error: sequence too short for INC-SEQ\n";
    std::cout << evn() << '\n';
    return 2;
  }

  std::cout << inc() << '\n';
  std::cout << evn() << '\n';

  return 0;
}
