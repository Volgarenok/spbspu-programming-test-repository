#include "prop_ptr.hpp"
#include "seq_properties.hpp"

#include <iostream>

int main()
{
  terentev::PropPtr p1(nullptr);
  terentev::PropPtr p2(nullptr);
  try {
    p1 = terentev::PropPtr(terentev::get_prop("gt-prev"));
    p2 = terentev::PropPtr(terentev::get_prop("max-cnt"));
  } catch (const std::invalid_argument& e) {
    std::cerr << "error: " << e.what() << "\n";
    return 3;
  } catch (const std::bad_alloc& e) {
    std::cerr << "error: " << e.what() << "\n";
    return 3;
  }

  int x = 0;
  if (!(std::cin >> x)) {
    std::cerr << "not int\n";
    return 1;
  }
  if (x == 0) {
    std::cerr << "Error: cannot compute (empty sequence).\n";
    return 2;
  }

  p1->operator()(x);
  p2->operator()(x);

  while (std::cin >> x && x != 0) {
    p1->operator()(x);
    p2->operator()(x);
  }
  if (!std::cin && !std::cin.eof()) {
    std::cerr << "not int\n";
    return 1;
  }

  std::cout << p1->operator()() << '\n';
  std::cout << p2->operator()() << '\n';
}
