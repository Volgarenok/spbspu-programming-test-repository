#include "processor.h"
#include <iostream>

bool khvaevskiy::read_sequence(
  long long &cnt_max,
  long long &aft_max,
  bool &has_data)
{
  has_data = false;
  cnt_max = 0;
  aft_max = 0;

  long long value = 0;
  long long max_val = 0;
  long long max_index = -1;
  long long count_max = 0;
  long long index = 0;

  while (std::cin >> value)
  {
    if (value == 0)
      break;

    if (!has_data)
    {
      max_val = value;
      max_index = index;
      count_max = 1;
      has_data = true;
    }
    else if (value > max_val)
    {
      max_val = value;
      max_index = index;
      count_max = 1;
    }
    else if (value == max_val)
    {
      count_max++;
    }

    index++;
  }

  if (std::cin.fail() && !std::cin.eof())
    return false;

  if (!has_data)
    return true;

  cnt_max = count_max;

  if (max_index < index - 1)
    aft_max = index - max_index - 1;
  else
    aft_max = 0;

  return true;
}
