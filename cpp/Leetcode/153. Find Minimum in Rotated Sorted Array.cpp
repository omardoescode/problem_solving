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

// The rotation count is the number of elements before the minimum element,
// called the pivot. That count is the same index. We are doing binary search to
int findMin(vector<int> &nums) {
  int n = nums.size();
  int low = 0, high = n - 1;

  while (low <= high) {
    // The sub-array is already sorted, Just return the low element
    if (nums[low] <= nums[high]) {
      return nums[low];
    }

    int mid = (low + high) / 2;

    // Find the next and prev in a circular manner
    int next = (mid + 1) % n;
    int prev =
        (mid - 1 + n) % n; // add n which helps with the negative sign issue

    // already the minimum, return the pivot
    if (nums[mid] <= nums[next] && nums[mid] <= nums[prev])
      return nums[mid];

    // If the middle element is less than the high element
    // then the sub-array is on the left side
    else if (nums[mid] <= nums[high])
      high = mid - 1;

    // If the middle element is less than the low element
    // then the sub-array is on the right side
    else if (nums[mid] >= nums[low])
      low = mid + 1;
  }

  // If the sub-array is not sorted, return -1
  return -1;
}

int main() {
  vector vals = {8, 9, 10, 2, 5, 6};
  printf("The minimum element in the array is %d\n", findMin(vals));
}
