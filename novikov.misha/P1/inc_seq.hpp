#ifndef INC_SEQ_HPP
#define INC_SEQ_HPP

#include "Itrait.hpp"
#include <stdexcept>

namespace novikov
{

  class SequenceTooShortError: public std::runtime_error
  {
  public:
    explicit SequenceTooShortError(size_t total):
      std::runtime_error("Sequence too short"),
      total_(total)
    {}

    size_t get_total() const
    {
      return total_;
    }

  private:
    size_t total_;
  };

  class IncSeq: public ITrait
  {
  public:
    IncSeq();
    virtual ~IncSeq() override = default;
    virtual void operator()(int x) override;
    virtual size_t operator()() const override;

  private:
    size_t count_;
    size_t total_;
    int prev_;
  };

}

#endif
