#include "inc_seq.h"
#include "div_rem.h"

int main()
{
  int error = 0;
  int a = 0;

  ITrait *traits[2] = {new IncSeq, new DivRem};
  ITrait &inc_seq = *(traits[0]);
  ITrait &div_rem = *(traits[1]);

  while (std::cin >> a)
  {
    if (a == 0)
    {
      break;
    }
    inc_seq(a);
    div_rem(a);
  }

  if (!std::cin.eof() && std::cin.fail())
  {
    std::cerr << "Bad input\n";
    delete traits[0];
    delete traits[1];
    return 1;
  }

  using std::cout;

  try
  {
    size_t inc_result = inc_seq();
    size_t div_result = div_rem();
    cout << inc_seq.trait() << ": " << inc_result << "\n";
    cout << div_rem.trait() << ": " << div_result << "\n";
  }
  catch (const char *msg)
  {
    std::cerr << div_rem.trait() << ": " << msg << "\n";
    cout << inc_seq.trait() << ": " << inc_seq() << "\n";
    error = 2;
  }

  delete traits[0];
  delete traits[1];
  return error;
}
