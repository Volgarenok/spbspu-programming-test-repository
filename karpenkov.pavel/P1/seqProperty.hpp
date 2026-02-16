#ifndef KARPENKOV_SEQ_PROPERTY_HPP
#define KARPENKOV_SEQ_PROPERTY_HPP
#include <iostream>
namespace karpenkov {
  struct ISeqProperty {
    virtual ~ISeqProperty() = default;
    size_t operator()() const {
      return res();
    }
    void operator()(int num) {
      process(num);
    }

    private:
      virtual size_t res() const = 0;
      virtual void process(int num) = 0;
  };
}
#endif
