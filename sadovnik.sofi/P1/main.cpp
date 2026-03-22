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

<<<<<<< HEAD
  int x;

  while (std::cin >> x)
  {
    if (x == 0)
    {
      break;
    }
=======
  while (cin >> x) {
    if (x == 0) break;
>>>>>>> parent of 3ef5ed9 (CG 7, 8, 3; changes as per comments)
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

<<<<<<< HEAD
  int err = 0;

  try
  {
    std::cout << sub() << '\n';
  }
  catch (const std::exception&)
  {
    std::cerr << "not enough numbers\n";
=======
  try {
    cout << sub() << '\n';
  } catch (const std::exception&) {
    cerr << "not enough numbers\n";
>>>>>>> parent of 3ef5ed9 (CG 7, 8, 3; changes as per comments)
    err = 2;
  }

  cout << aft() << '\n';

  return err;
}
