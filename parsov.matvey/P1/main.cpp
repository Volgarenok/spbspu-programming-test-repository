#include <iostream>

namespace parsov {

  class IProperty {
  public:
    virtual ~IProperty() = default;
    size_t operator()() const;
    void operator()(int value);
  private:
    virtual size_t result() const = 0;
    virtual void update(int value) = 0;
  };

  size_t IProperty::operator()() const
  {
    return result();
  }

  void IProperty::operator()(int value)
  {
    update(value);
  }

  class MonInc : public IProperty {
  public:
    MonInc();
  private:
    size_t max_length_;
    size_t current_length_;
    int prev_val_;
    bool is_first_;
    size_t result() const override;
    void update(int value) override;
  };

  MonInc::MonInc():
    max_length_(0),
    current_length_(0),
    prev_val_(0),
    is_first_(true)
  {}

  size_t MonInc::result() const
  {
    return max_length_;
  }

  void MonInc::update(int value)
  {
    if (is_first_) {
      current_length_ = 1;
      max_length_ = 1;
      prev_val_ = value;
      is_first_ = false;
    } else {
      if (value >= prev_val_) {
        current_length_++;
      } else {
        current_length_ = 1;
      }
      if (current_length_ > max_length_) {
        max_length_ = current_length_;
      }
      prev_val_ = value;
    }
  }

  class GrtLss : public IProperty {
  public:
    GrtLss();
  private:
    size_t count_;
    int prev2_;
    int prev1_;
    size_t elements_seen_;
    size_t result() const override;
    void update(int value) override;
  };

  GrtLss::GrtLss():
    count_(0),
    prev2_(0),
    prev1_(0),
    elements_seen_(0)
  {}

  size_t GrtLss::result() const
  {
    return count_;
  }

  void GrtLss::update(int value)
  {
    elements_seen_++;
    if (elements_seen_ >= 3) {
      if (prev2_ > prev1_ && prev1_ > value) {
        count_++;
      }
    }
    prev2_ = prev1_;
    prev1_ = value;
  }

}

int main()
{
  int err = 0;
  int value = 0;
  parsov::MonInc mon_inc;
  parsov::GrtLss grt_lss;

  while (std::cin >> value && value != 0) {
    mon_inc(value);
    grt_lss(value);
  }

  if (!std::cin.eof() && std::cin.fail()) {
    std::cerr << "Bad input\n";
    return 1;
  }

  try {
    std::cout << mon_inc() << "\n";
  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    if (err == 0) {
      err = 2;
    }
  }

  try {
    std::cout << grt_lss() << "\n";
  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    if (err == 0) {
      err = 2;
    }
  }

  return err;
}
