#include <iostream>

namespace musorin {
  struct cnt_max {
    void mx(int a) {
      max_ = a;
    }
    void upd(int a) {
      if (a > max_) {
        max_ = a;
        km_ = 1;
      }
      else if (a == max_) {
        ++km_;
      }
    }
    size_t result() const {
      return km_;
    }
  private:
    int max_ = 0;
    size_t km_ = 1;
  };
  struct sub_max {
    void mx(int a) {
      max_ = a;
    }
    void upd(int a) {
      if (a >= max_) {
        smax_ = max_;
        max_ = a;
      }
    }
    int result() const {
      return smax_;
    }
  private:
    int max_ = 0;
    int smax_ = 0;
  };
}
int main() {
  using namespace musorin;
  int a;
  cnt_max w;
  sub_max e;

  std::cin >> a;
  if (a == 0) {
    std::cerr << "Error: sequence is too small\n";
    return 2;
  }
  w.mx(a);
  e.mx(a);
  while (std::cin >> a) {
    if (a == 0) {
      break;
    }
    w.upd(a);
    e.upd(a);

  }
  if (std::cin.fail() && !std::cin.eof()) {
    std::cerr << "Error: invalid input\n";
    return 1;
  }

  if (e.result() == 0) {
    std::cerr << "Error: sequence is too small(sub_max)" << "\n";
    std::cout << "number of local max: " << w.result() << "\n";
    return 2;
  }
  using std::cout;
  cout << "number of local max: " << w.result() << "\n";
  cout << "second max (max if you remove max): " << e.result() << "\n";
  return 0;
}
