#pragma once

#include <sstream>
#include <string>

// Header implementation because of template
// Container can be things like std::vector, std::list
template <typename Container>
std::string containerToString(Container& container, std::string sep = ", ") {
  std::ostringstream out;
  out << "{";
  bool first = true;
  for (auto elem : container) {
    if (first) {
      out << elem;
      first = false;
    } else {
      out << sep << elem;
    }
  }
  out << "}";
  return out.str();
}