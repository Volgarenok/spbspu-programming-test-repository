#ifndef TERENTEV_SEQ_PROPERTIES_HPP
#define TERENTEV_SEQ_PROPERTIES_HPP

#include <cstddef>
#include <string>

namespace terentev {

  struct ISeqProperty {
    std::size_t operator()() const
    {
      return result();
    }
    void operator()(int x)
    {
      next(x);
    }
    virtual ~ISeqProperty() = default;
  private:
    virtual std::size_t result() const = 0;
    virtual void next(int x) = 0;
  };

  struct CountGreaterThanPrev final: ISeqProperty {
  private:
    std::size_t c = 0;
    int prev = 0;

    std::size_t result() const override;
    void next(int x) override;
  };

  struct CountMaxOccurrences final: ISeqProperty {
  private:
    int max = 0;
    std::size_t cnt = 0;

    std::size_t result() const override;
    void next(int x) override;
  };

  ISeqProperty* get_prop(const std::string& name);

}

#endif
