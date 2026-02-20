#include <iostream>

namespace traits
{
  struct ITrait
  {
    virtual ~ITrait() = default;
    virtual void operator()(int a)
    {
      process(a);
    }
    virtual size_t operator()() const
    {
      return result();
    }
   private:
    virtual void process(int a) = 0;
    virtual size_t result() const = 0;
  };

  struct grtLss : public ITrait
  {
   private:
    void process(int a)
    {
      first_ = second_;
      second_ = third_;
      third_ = a;
      if (f_ < 2)
      {
        f_++;
      }
      else
      {
        if (first_ > second_ && second_ > third_)
        {
          count_++;
        }
      }
    }
    size_t result() const
    {
      if (f_ < 2)
      {
        throw std::logic_error("Error : sequence is too short");
      }
      return count_;
    }
    size_t count_ = 0;
    int first_ = 0, second_ = 0, third_ = 0, f_ = 0;
  };

  struct monDec : public ITrait
  {
   private:
    void process(int a)
    {
      prev_ = curr_;
      curr_ = a;
      if (f_ == 0)
      {
        tempCount_ = 1;
        f_ = 1;
      }
      else
      {
        f_ = 2;
        if (prev_ >= curr_)
        {
          tempCount_++;
        }
        else
        {
          tempCount_ = 1;
        }
        if (tempCount_ > mcount_)
        {
          mcount_ = tempCount_;
        }
      }
    }
    size_t result() const
    {
      if (f_ != 2)
      {
        throw std::logic_error("Error : sequence is too short");
      }
      return mcount_;
    }
    size_t tempCount_ = 0, mcount_ = 0;
    int curr_ = 0, prev_ = 0, f_ = 0;
  };

  void traitCreate(ITrait *p[2])
  {
    grtLss *g = nullptr;
    monDec *m = nullptr;
    try
    {
      g = new grtLss;
      m = new monDec;
    }
    catch(...)
    {
      delete g;
      delete m;
      throw;
    }
    p[0] = g;
    p[1] = m;
  }
}

int main()
{
  int el = 0;
  traits::ITrait *traitArray[2];
  traits::traitCreate(traitArray);
  while (std::cin >> el && el != 0)
  {
    traitArray[1]->operator()(el);
    traitArray[0]->operator()(el);
  }
  if (std::cin.fail())
  {
    std::cerr << "Input failed\n";
    return 1;
  }
  try
  {
    std::cout << traitArray[0]->operator()() << "\n";
    std::cout << traitArray[1]->operator()() << "\n";
    delete traitArray[0];
    delete traitArray[1];
    return 0;
  }
  catch (std::logic_error &error)
  {
    std::cout << error.what() << "\n";
    delete traitArray[0];
    delete traitArray[1];
    return 2;
  }
}
