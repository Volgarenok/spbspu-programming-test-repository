#include <iostream>

namespace terentev {

  struct ISeqProperty {
    size_t operator()() const
    {
      return result();
    }
    void operator()(int x)
    {
      next(x);
    }
    virtual ~ISeqProperty() = default;
  private:
    virtual size_t result() const = 0;
    virtual void next(int x) = 0;
  };

  struct CountGreaterThanPrev final: ISeqProperty {
  private:
    size_t c = 0;
    int prev = 0;

    size_t result() const override
    {
      return c;
    }
    void next(int x) override
    {
      if (prev == 0) {
        prev = x;
        return;
      }
      if (x > prev) {
        ++c;
      }
      prev = x;
    }
  };

  struct CountMaxOccurrences final: ISeqProperty {
  private:
    int max = 0;
    size_t cnt = 0;

    size_t result() const override
    {
      return cnt;
    }
    void next(int x) override
    {
      if (cnt == 0) {
        max = x;
        cnt = 1;
        return;
      }
      if (x > max) {
        max = x;
        cnt = 1;
      } else {
        if (x == max) {
          ++cnt;
        }
      }
    }
  };

  ISeqProperty* get_prop(const std::string& name)
  {
    if (name == "gt-prev") {
      return new CountGreaterThanPrev();
    }
    if (name == "max-cnt") {
      return new CountMaxOccurrences();
    }
    throw std::invalid_argument("unknown property: " + name);
  }

  struct PropPtr {
    ISeqProperty* p = nullptr;

    explicit PropPtr(ISeqProperty* ptr) : p(ptr)
    {
    }
    ~PropPtr()
    {
      delete p;
    }

    PropPtr(const PropPtr&) = delete;
    PropPtr& operator=(const PropPtr&) = delete;

    PropPtr(PropPtr&& other) noexcept : p(other.p)
    {
      other.p = nullptr;
    }
    PropPtr& operator=(PropPtr&& other) noexcept
    {
      if (this != &other) {
        delete p;
        p = other.p;
        other.p = nullptr;
      }
      return *this;
    }

    ISeqProperty* operator->() const
    {
      return p;
    }
  };

}

int main()
{
  terentev::PropPtr p1(nullptr);
  terentev::PropPtr p2(nullptr);
  try {
    p1 = terentev::PropPtr(terentev::get_prop("gt-prev"));
    p2 = terentev::PropPtr(terentev::get_prop("max-cnt"));
  } catch (const std::invalid_argument& e) {
    std::cerr << "error: " << e.what() << "\n";
    return 3;
  } catch (const std::bad_alloc& e) {
    std::cerr << "error: " << e.what() << "\n";
    return 3;
  }

  int x = 0;
  if (!(std::cin >> x)) {
    std::cerr << "not int\n";
    return 1;
  }
  if (x == 0) {
    std::cerr << "Error: cannot compute (empty sequence).\n";
    return 2;
  }

  p1->operator()(x);
  p2->operator()(x);

  while (std::cin >> x && x != 0) {
    p1->operator()(x);
    p2->operator()(x);
  }
  if (!std::cin && !std::cin.eof()) {
    std::cerr << "not int\n";
    return 1;
  }
  std::cout << p1->operator()() << '\n';
  std::cout << p2->operator()() << '\n';
  return 0;
}
