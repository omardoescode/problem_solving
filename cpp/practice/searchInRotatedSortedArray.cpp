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

int searchCircularArray(int nums[], int target, int n) {
  int lo = 0, hi = n - 1;

  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (nums[mid] == target) {
      return mid;
    }

    // If the right half is sorted
    if (nums[mid] <= nums[hi]) {
      if (target > nums[mid] && target <= nums[hi]) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    // If the left half is sorted
    // Notice that one sub-array must be sorted
    else {
      if (target < nums[mid] && target >= nums[lo]) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
  }

  return -1; // Invalid Input or target not found
}
int main() {
  int nums[] = {9, 10, 2, 5, 6, 8};
  int target = 5;

  int index = searchCircularArray(nums, target, 6);
  printf(index != -1 ? "Element found at index %d\n"
                     : "Element not found  in the array\n",
         index);
}
