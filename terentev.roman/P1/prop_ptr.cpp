#include "prop_ptr.hpp "

terentev::PropPtr::PropPtr(ISeqProperty* ptr) : p(ptr)
{
}

terentev::PropPtr::~PropPtr()
{
  delete p;
}

terentev::PropPtr::PropPtr(PropPtr&& other) noexcept : p(other.p)
{
  other.p = nullptr;
}

terentev::PropPtr& terentev::PropPtr::operator=(PropPtr&& other) noexcept
{
  if (this != &other) {
    delete p;
    p = other.p;
    other.p = nullptr;
  }
  return *this;
}

terentev::ISeqProperty* terentev::PropPtr::operator->() const
{
  return p;
}
