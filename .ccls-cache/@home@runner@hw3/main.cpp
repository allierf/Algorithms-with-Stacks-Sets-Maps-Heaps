#include <iostream>
#include <queue>
#include <stack>
#include <string>

#include "HW3.h"
#include "util.h"

int main() {
  // Q3
  std::cout << "Q3" << std::endl;
  std::cout << countLegoHouses("abb", "babab") << std::endl;    // 1
  std::cout << countLegoHouses("abb", "bababcdb") << std::endl; // 2
  try {
    std::cout << countLegoHouses("", "a") << std::endl; // should throw
    std::cout << "countLegoHouses appears incorrect for the empty case."
              << std::endl;
  } catch (const std::invalid_argument &ia) {
    std::cout << "countLegoHouses appears correct for the empty case."
              << std::endl;
  }

  // Q4
  std::cout << "Q4" << std::endl;
  std::vector<std::string> anagroup1 =
      findLargestAnagroup({"act", "tac", "yam", "cat", "may", "hello"});
  std::cout << containerToString(anagroup1)
            << std::endl; // {"act", "tac", "cat"}
  std::vector<std::string> anagroup2 =
      findLargestAnagroup({"bear", "hello", "bare"});
  std::cout << containerToString(anagroup2) << std::endl; // {"bear", "bare"}

  // Q5
  std::cout << "Q5" << std::endl;
  std::vector<double> q5Output =
      mergeSortedLists({{1.1, 2.4}, {4.5}, {-3.4, 8.9}});
  std::cout << containerToString(q5Output)
            << std::endl; // {-3.4, 1.1, 2.4, 4.5, 8.9}
}