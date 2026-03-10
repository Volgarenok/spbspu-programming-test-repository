#include <iostream>
#include "cnt_max.hpp"
#include "aft_max.hpp"

void destroy(khvaevskiy::i_trait *traits[])
{
  delete traits[0];
  delete traits[1];
}

int main()
{
  using std::cin;
  using std::cout;
  using std::cerr;

  namespace khv = khvaevskiy;

  khv::i_trait *traits[2] = {nullptr, nullptr};

  try
  {
    traits[0] = new khv::cnt_max();
    traits[1] = new khv::aft_max();
  }
  catch (const std::bad_alloc &)
  {
    cerr << "Error: bad_alloc\n";
    destroy(traits);
    return 2;
  }

  long long num = 0;
  std::size_t total = 0;

  while (cin >> num)
  {
    if (num == 0)
      break;

    total++;
    traits[0]->operator()(num);
    traits[1]->operator()(num);
  }

  if (cin.fail() && !cin.eof())
  {
    cerr << "Error: invalid input\n";
    destroy(traits);
    return 1;
  }

  if (total == 0)
  {
    cerr << "Error: sequence is empty\n";
    destroy(traits);
    return 2;
  }

  static_cast<khv::aft_max *>(traits[1])->finalize();

  cout << traits[0]->operator()() << "\n";
  cout << traits[1]->operator()() << "\n";

  destroy(traits);
  return 0;
}
