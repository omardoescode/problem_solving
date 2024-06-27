#include <iostream>
#include <vector>
using namespace std;
bool search(vector<int> &nums, int target) {
  int lo = 0, hi = nums.size() - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (target == nums[mid])
      return true;

    if (nums[mid] == nums[lo] && nums[mid] == nums[hi]) {
      lo++;
      hi--;
    }

    else if (nums[mid] <= nums[hi]) {
      if (target > nums[mid] && target <= nums[hi]) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    } else {
      if (target >= nums[lo] && target < nums[mid]) {
        hi = mid - 1;
      } else
        lo = mid + 1;
    }
  }
  return false;
}

int main() {}
