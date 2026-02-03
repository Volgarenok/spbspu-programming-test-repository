#include <iostream>
namespace novikov
{
bool tryReadInteger(int& output){
    std::cin >> output;
    return !std::cin.fail();
}
void printError(const char* message){
    std::cerr << message << "\n";
}
}
int main()
{
    using namespace novikov;

    const char* const errorInvalidInput = "Ошибка: Входные данные содержат нечисловые значения";
    const char* const errorNoZero = "Ошибка: Не было введено число 0 для завершения";
    std::size_t totalNumbers = 0;
    bool foundZero = false;
    int currentNumber = 0;

    while (true) {
      if (!tryReadInteger(currentNumber)) {
        std::cerr << errorInvalidInput << '\n';
        return 1;
      }

      if (currentNumber == 0) {
        foundZero = true;
        break;
      }

      ++totalNumbers;
    }

    if (!foundZero) {
      std::cerr << errorNoZero << '\n';
      return 1;
    }

    return 0;

}
