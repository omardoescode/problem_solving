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
int findMinimum(vector<int> &nums, int target) {
  int lo = 0, hi = nums.size() - 1;
  int result = -1;

  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (target == nums[mid]) {
      result = mid;
      hi = mid - 1;
    } else if (target > nums[mid]) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  return result;
}
int findMaximum(vector<int> &nums, int target) {
  int lo = 0, hi = nums.size() - 1;
  int result = -1;

  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (target == nums[mid]) {
      result = mid;
      lo = mid + 1;
    } else if (target > nums[mid]) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  return result;
}
vector<int> searchRange(vector<int> &nums, int target) {
  int first = findMinimum(nums, target);
  int last = findMaximum(nums, target);
  return {first, last};
}
int main() {
  vector nums = {5, 7, 7, 8, 8, 10};
  int target = 8;
  auto result = searchRange(nums, target);

  printf("The first index is %d and the last index is %d\n", result[0],
         result[1]);
}
