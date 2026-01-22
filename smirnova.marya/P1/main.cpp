#include <iostream>
#include <string>
#include <exception>

#include "ITrait.hpp"
#include "get_prop.hpp"
#include "io.hpp"

int main()
{
  const int traitCount = 2;
  ITrait **traits = nullptr;

  try
  {
    traits = new ITrait *[traitCount];
    for (int i = 0; i < traitCount; ++i)
      traits[i] = nullptr;

    for (int i = 0; i < traitCount; ++i)
    {
      traits[i] = get_prop(std::to_string(i + 1));
      if (!traits[i])
      {
        std::cerr << "Error: failed to create array\n";
        return 2;
      }
    }
    input(traits, traitCount);
    output(traits, traitCount);

    for (int i = 0; i < traitCount; ++i)
      delete traits[i];
    delete[] traits;
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    if (traits)
    {
      for (int i = 0; i < traitCount; ++i)
        delete traits[i];
      delete[] traits;
    }
    return 1;
  }
  catch (const std::exception &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    if (traits)
    {
      for (int i = 0; i < traitCount; ++i)
        delete traits[i];
      delete[] traits;
    }
    return 2;
  }

  return 0;
}
