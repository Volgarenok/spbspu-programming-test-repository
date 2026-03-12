#include <iostream>
#include "sub_max.hpp"
#include "aft_max.hpp"

int main()
{
  using std::cin;
  using std::cout;
  using std::cerr;

  int err = 0;
  int x;
  bool zero = false;

  sadovnik::SubMaxCount sub;
  sadovnik::AftMaxCount aft;

  while (cin >> x)
  {
    if (x == 0)
    {
      zero = true;
      break;
    }
    sub(x);
    aft(x);
  }

  if (cin.fail() && !cin.eof())
  {
    cerr << "Bad input\n";
    return 1;
  }
  if (!zero)
  {
    cerr << "No zero\n";
    return 1;
  }

  if (sub.valid())
  {
    cout << sub() << '\n';
  }
  else
  {
    cerr << "Not enough numbers\n";
    err = 2;
  }

  cout << aft() << '\n';

  return err;
}
