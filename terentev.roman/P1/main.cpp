#include <iostream>

struct ISeqProperty {
  size_t operator()() const { return result(); }
  void operator()(int x) { next(x); }
  virtual ~ISeqProperty() = default;
private:
  virtual size_t result() const = 0;
  virtual void next(int x) = 0;
};

struct CountGreaterThanPrev : ISeqProperty {
  size_t c = 0;
  bool hasPrev = false;
  int prev = 0;
private:
  size_t result() const override { return c; }
  void next(int x) override {
    if (!hasPrev) {
      prev = x;
      hasPrev = true;
      return;
    }
    if (x > prev) {
      ++c;
    }
    prev = x;
  }
};

struct CountMaxOccurrences : ISeqProperty {
  int max = 0;
  size_t cnt = 0;
  bool hasAny = false;
private:
  size_t result() const override { return cnt; }
  void next(int x) override {
    if (!hasAny) {
      max = x;
      cnt = 1;
      hasAny = true;
      return;
    }
    if (x > max) {
      max = x;
      cnt = 1;
    }
    else if (x == max) {
      ++cnt;
    }
  }
};

ISeqProperty* get_prop(const std::string& name) {
  if (name == "gt-prev") {
    return new CountGreaterThanPrev();
  }
  if (name == "max-cnt") {
    return new CountMaxOccurrences();
  }
  throw std::invalid_argument("unknown property: " + name);
}

int main() {
  ISeqProperty* p1 = nullptr;
  ISeqProperty* p2 = nullptr;
  try {
    p1 = get_prop("gt-prev");
    p2 = get_prop("max-cnt");
    int x;
    if (!(std::cin >> x)) {
      std::cerr << "not int\n";
      delete p1;
      delete p2;
      return 1;
    }
    if (x == 0) {
      std::cerr << "Error: cannot compute (empty sequence).\n";
      delete p1;
      delete p2;
      return 2;
    }
    (*p1)(x);
    (*p2)(x);
    while (true) {
      if (!(std::cin >> x)) {
        std::cerr << "not int\n";
        delete p1;
        delete p2;
        return 1;
      }
      if (x == 0) {
        break;
      }
      (*p1)(x);
      (*p2)(x);
    }
    std::cout << (*p1)() << '\n';
    std::cout << (*p2)() << '\n';
    delete p1;
    delete p2;
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << "error: " << e.what() << "\n";
    delete p1;
    delete p2;
    return 3;
  }
}
