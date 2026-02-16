#ifndef MATVEEV_PROPERTIES_HPP
#define MATVEEV_PROPERTIES_HPP

#include <cstddef>
#include <stdexcept>
namespace matveev
{
  struct ISeqProperty
  {
    void operator()(int value)
    {
      next(value);
    }
    size_t operator()() const
    {
      return result();
    }
    virtual ~ISeqProperty() = default;
  private:
    virtual void next(int value) = 0;
    virtual size_t result() const = 0;
  };

  struct CntMaxProperty : public ISeqProperty
  {
  private:
    void next(int value) override
    {
      if (count == 0)
      {
        max = value;
        count = 1;
      }
      else if (value > max)
      {
        max = value;
        count = 1;
      }
      else if (value == max)
      {
        ++count;
      }
    }

    size_t result() const override
    {
      return count;
    }
    int max = 0;
    size_t count = 0;
  };

  struct DivRemProperty : public ISeqProperty
  {
  private:
    void next(int value) override
    {
      if (total > 0 && previous != 0 && value % previous == 0)
      {
        ++count;
      }

      previous = value;
      ++total;
    }

    size_t result() const override
    {
      if (total < 2)
      {
        throw std::logic_error("Error numbers");
      }
      return count;
    }
    int previous = 0;
    size_t count = 0;
    size_t total = 0;
  };
}
#endif
