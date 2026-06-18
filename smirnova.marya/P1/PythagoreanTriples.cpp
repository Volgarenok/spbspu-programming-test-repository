#include "PythagoreanTriples.hpp"
#include <climits>

PythagoreanTriples::PythagoreanTriples() : a(0), b(0), count(0), size(0) {}

bool PythagoreanTriples::do_add(int value)
{
  if (size == 0) {
    a = value;
    size = 1;
    return false;
  }
  if (size == 1) {
    b = value;
    size = 2;
    return false;
  }
  if (pyCheck(a, b, value))
    ++count;
  a = b;
  b = value;
  size = 3;
  return true;
}
int PythagoreanTriples::value() const
{
  return count;
}
bool PythagoreanTriples::computable() const
{
  return size >= 3;
}

bool PythagoreanTriples::pyCheck(int x, int y, int z) const
{
  if (x <= 0 || y <= 0 || z <= 0)
    return false;

  if (x > INT_MAX / x || y > INT_MAX / y || z > INT_MAX / z)
    return false;

  return x*x + y*y == z*z || x*x + z*z == y*y || y*y + z*z == x*x;
}
