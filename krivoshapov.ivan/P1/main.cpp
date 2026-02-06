#include <iostream>

namespace krivoshapov
{
  void run()
  {
    int prev = 0;
    int curr = 0;
    int incSeqCount = 0;
    int divRemCount = 0;
    int itemCount = 0;
    bool isFirst = true;

    while (std::cin)
    {
      std::cin >> curr;
      if (!std::cin)
      {
        if (std::cin.eof())
        {
          break;
        }
        std::cerr << "Error: invalid input\n";
        std::exit(1);
      }

      if (curr == 0)
      {
        break;
      }

      if (isFirst)
      {
        isFirst = false;
      }
      else
      {
        if (curr > prev)
        {
          ++incSeqCount;
        }
        if (prev != 0 && curr % prev == 0)
        {
          ++divRemCount;
        }
      }

      prev = curr;
      ++itemCount;
    }

    if (itemCount < 2)
    {
      std::cerr << "Error: sequence too short\n";
      std::exit(2);
    }

    std::cout << incSeqCount << '\n';
    std::cout << divRemCount << '\n';
  }
}

int main()
{
  krivoshapov::run();
  return 0;
}
