#ifndef TERENTEV_PROP_PTR_HPP
#define TERENTEV_PROP_PTR_HPP

#include "seq_properties.hpp"

namespace terentev {

  struct PropPtr {
  public:
    explicit PropPtr(ISeqProperty* ptr);
    ~PropPtr();

    PropPtr(const PropPtr&) = delete;
    PropPtr& operator=(const PropPtr&) = delete;

    PropPtr(PropPtr&& other) noexcept;
    PropPtr& operator=(PropPtr&& other) noexcept;

    ISeqProperty* operator->() const;

  private:
    ISeqProperty* p = nullptr;
  };

}

#endif
