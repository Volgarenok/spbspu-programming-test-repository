#ifndef NUMERIC_SEQUENCE_HPP
#define NUMERIC_SEQUENCE_HPP

#include <cstddef>

namespace gordejchik
{
  class SeqProperty
  {
  public:
    virtual ~SeqProperty() = default;
    size_t operator()() const;
    void operator()(int number);

  private:
    virtual size_t result() const = 0;
    virtual void next(int number) = 0;
  };

  class EvenCount: public SeqProperty
  {
  public:
    EvenCount();

  private:
    size_t maxEvenCount_;
    size_t currentEvenCount_;

    size_t result() const override;
    void next(int number) override;
  };

  class LocalMax: public SeqProperty
  {
  public:
    LocalMax();

  private:
    size_t localMaxCount_;
    int previousNumber_;
    int currentNumber_;
    size_t totalNumbers_;

    size_t result() const override;
    void next(int number) override;
  };
}

#endif
