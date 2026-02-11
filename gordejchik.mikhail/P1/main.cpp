#include <iostream>

namespace gordejchik
{
  struct ErrorStatus
  {
    bool foundError;
    bool foundZero;
  };

  bool readInteger(int& output)
  {
    std::cin >> output;
    return !std::cin.fail();
  }

  void printError(const char* message, ErrorStatus& error)
  {
    std::cerr << message << '\n';
    error.foundError = true;
  }
}

int main()
{
  gordejchik::ErrorStatus error{};
  error.foundError = false;
  error.foundZero = false;

  return 0;
}
