#include <ios>
#include <iostream>
#include <vector>

bool check(std::vector<int> &nums) {
  int numberOfDescend = 0;
  for (int i = 0; i < nums.size() - 1; i++) {
    if (nums[i + 1] < nums[i])
      numberOfDescend++;
  }

  if (nums.back() > nums[0])
    numberOfDescend++;
  return numberOfDescend <= 1;
}

int main() {
  std::vector vals = {3, 4, 5, 1, 2};
  std::cout << std::boolalpha << check(vals); // true
  return 0;
}
