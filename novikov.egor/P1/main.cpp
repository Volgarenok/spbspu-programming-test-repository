#include <iostream>
#include "divRem.hpp"
#include "cntMax.hpp"

// namespace novikov
// {
//   class ITrait
//   {
//   public:
//     virtual ~ITrait() = default;
//     virtual size_t operator()() const = 0;
//     virtual void operator()(int) = 0;
//   };

//   class div_rem: public ITrait
//   {
//   private:
//     bool is_first_try = true;
//     int late_num = 0;
//     size_t res = 0;

//   public:
//     size_t operator()() const override;
//     void operator()(int num) override;
//   };

//   class cnt_max: public ITrait
//   {
//   private:
//     size_t counter = 0;
//     int biggest = 0;
//     size_t res = 0;

//   public:
//     size_t operator()() const override;
//     void operator()(int num) override;
//   };
// }

int main()
{
  novikov::div_rem d;
  novikov::cnt_max c;
  novikov::ITrait *traits[2];
  traits[0] = &d;
  traits[1] = &c;
  int num = 1;
  std::cin >> num;
  size_t counter = 0;
  while (!std::cin.fail()) {
    if (num == 0) {
      break;
    }
    counter++;
    d(num);
    c(num);
    std::cin >> num;
    if (std::cin.fail()) {
      std::cerr << "Bad sequence\n";
      return 1;
    }
  }
  if (counter == 1) {
    std::cerr << "Can't calculate div_rem. Sequence too short\n";
    std::cout << "cnt_max: " << c() << "\n";
    return 2;
  } else if (counter == 0) {
    std::cerr << "Can't calculate traits. Sequence too short\n";
    return 2;
  } else {
    for (int i = 0; i < 2; ++i) {
      std::cout << (*traits[i])() << "\n";
    }
  }
}

// size_t novikov::div_rem::operator()() const
// {
//   return res;
// }

// void novikov::div_rem::operator()(int num)
// {
//   if (is_first_try) {
//     late_num = num;
//     is_first_try = false;
//   } else {
//     if (num % late_num == 0) {
//       res++;
//     }
//   }
//   late_num = num;
// }

// size_t novikov::cnt_max::operator()() const
// {
//   return res;
// };

// void novikov::cnt_max::operator()(int num)
// {
//   if (counter == 0) {
//     biggest = num;
//     counter++;
//   } else if (biggest < num) {
//     biggest = num;
//     res = 1;
//   } else if (biggest == num) {
//     res++;
//   }
// }
