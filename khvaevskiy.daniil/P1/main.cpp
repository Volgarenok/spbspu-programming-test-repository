#include <iostream>
#include "processor.h"

int main()
{
  using std::cin;
  using std::cout;
  using std::cerr;

  namespace khv = khvaevskiy;

  long long cnt_max = 0;
  long long aft_max = 0;
  bool has_data = false;

  const bool ok = khv::read_sequence(cnt_max, aft_max, has_data);

  if (!ok)
  {
    cerr << "Error: input is not a valid sequence\n";
    return 1;
  }

  if (!has_data)
  {
    cerr << "Error: sequence is empty\n";
    return 2;
  }

  cout << cnt_max << "\n";
  cout << aft_max << "\n";

  return 0;
}
