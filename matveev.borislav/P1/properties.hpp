#ifndef MATVEEV_PROPERTIES_HPP
#define MATVEEV_PROPERTIES_HPP
#include <cstddef>

namespace matveev
{
  struct ISeqProperty
  {
    void operator()(int value);
    size_t operator()() const;
    virtual ~ISeqProperty() = default;
  private:
    virtual void next(int value) = 0;
    virtual size_t result() const = 0;
  };

  struct CntMaxProperty final: public ISeqProperty
  {
    CntMaxProperty();
  private:
    void next(int value) override;
    size_t result() const override;
    int max;
    size_t count;
  };

  struct DivRemProperty final: public ISeqProperty
  {
    DivRemProperty();
  private:
    void next(int value) override;
    size_t result() const override;

    int previous;
    size_t count;
    size_t total;
  };
}

#endif
