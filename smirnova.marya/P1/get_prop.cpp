#include "get_prop.hpp"
#include <string>

#include "ITrait.hpp"
#include "MaxIncreasing.hpp"
#include "PythagoreanTriples.hpp"

ITrait* get_prop(const std::string& name)
{
  if (name == "1")
    return new MaxIncreasing();
  if (name == "2")
    return new PythagoreanTriples();
  return nullptr;
}
