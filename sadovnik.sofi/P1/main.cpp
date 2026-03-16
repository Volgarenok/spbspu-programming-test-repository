#include <iostream>
#include <stdexcept>
#include "sub_max.hpp"
#include "aft_max.hpp"

int main()
{
  using std::cin;
  using std::cout;
  using std::cerr;

  int err = 0;
  int x;

  sadovnik::SubMaxCount sub;
  sadovnik::AftMaxCount aft;

  while (cin >> x) {
    if (x == 0) break;
    sub(x);
    aft(x);
  }

  if (cin.fail() && !cin.eof()) {
    cerr << "bad input\n";
    return 1;
  }
  if (cin.eof()) {
    cerr << "no zero\n";
    return 1;
  }

  try {
    cout << sub() << '\n';
  } catch (const std::exception&) {
    cerr << "not enough numbers\n";
    err = 2;
  }

  cout << aft() << '\n';

  return err;
}

