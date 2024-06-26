
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define F first
#define B first
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = (a), _end = (b); i < _end; i++)
#define SQ(a) ((a) * (a))
#define DEBUG(output) cout << output << endl

int search(vector<int> &nums, int target) {
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[low] <= nums[mid]) {
      if (target >= nums[low] && target <= nums[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    } else {
      if (target >= nums[mid] && target <= nums[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }
  return -1;
}

int main() {
  vector nums = {9, 10, 2, 5, 6, 8};
  int target = 5;

  int index = search(nums, target);
  printf(index != -1 ? "Element found at index %d\n"
                     : "Element not found  in the array\n",
         index);
}
