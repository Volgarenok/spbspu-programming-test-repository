#include <iostream>
#include <limits>

namespace yalovsky
{

  struct ISeqProperty
  {
    size_t operator()() const
    {
      return getResult();
    }

    void operator()(int i)
    {
      processNext(i);
    }

    virtual ~ISeqProperty() = default;

  private:
    virtual size_t getResult() const = 0;
    virtual void processNext(int i) = 0;
  };

}

int main()
{
  return 0;
}

