#include <cstddef>
#include <exception>
#include <iostream>
#include "numeric_sequence.hpp"

int main()
{
  gordejchik::EvenCount evenCount;
  gordejchik::LocalMax localMax;
  gordejchik::SeqProperty* properties[] = {&evenCount, &localMax};
  const size_t propertyCount = sizeof(properties) / sizeof(properties[0]);

  int currentNumber = 0;
  while (std::cin >> currentNumber && currentNumber != 0)
  {
    for (size_t i = 0; i < propertyCount; ++i)
    {
      gordejchik::SeqProperty& property = *(properties[i]);
      property(currentNumber);
    }
  }

  if (std::cin.fail())
  {
    if (std::cin.eof())
    {
      std::cerr << "Error: sequence doesn't end with a zero\n";
    }
    else
    {
      std::cerr << "Error: sequence contains non-numeric characters\n";
    }
    return 1;
  }

  int returnCode = 0;
  for (size_t i = 0; i < propertyCount; ++i)
  {
    const gordejchik::SeqProperty& property = *(properties[i]);
    try
    {
      const size_t value = property();
      std::cout << value << '\n';
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      returnCode = 2;
    }
  }

  return returnCode;
}
