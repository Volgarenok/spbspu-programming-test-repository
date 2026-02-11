#include <iostream>
#include <limits>

namespace yalovsky
{

  int run()
  {
    bool has_any = false;
    bool has_max1 = false;
    bool has_max2 = false;
    bool has_seq = false;
    bool has_error_characteristic = false;

    int max1 = 0;
    int max2 = 0;
    int current_value = 0;
    int current_len = 0;
    int best_len = 0;

    while (true)
    {
      long long tmp = 0;

      if (!(std::cin >> tmp))
      {
        std::cerr << "Input error: not an integer sequence\n";
        return 1;
      }

      if (tmp < std::numeric_limits< int >::min()
        || tmp > std::numeric_limits< int >::max())
      {
        std::cerr << "Input error: value out of int range\n";
        return 1;
      }

      int x = static_cast< int >(tmp);

      if (x == 0)
      {
        break;
      }

      has_any = true;

      if (!has_max1)
      {
        max1 = x;
        has_max1 = true;
      }
      else if (x > max1)
      {
        if (!has_max2)
        {
          has_max2 = true;
          max2 = max1;
        }
        else
        {
          max2 = max1;
        }
        max1 = x;
      }
      else if (x < max1)
      {
        if (!has_max2)
        {
          max2 = x;
          has_max2 = true;
        }
        else if (x > max2)
        {
          max2 = x;
        }
      }
    }
    if (!has_any || !has_max2)
    {
      std::cerr << "Sequence is too short for SUB-MAX\n";
      return 2;
    }

    std::cout << max2 << '\n';
    return 0;
  }
}

int main()
{
  return yalovsky::run();
}
