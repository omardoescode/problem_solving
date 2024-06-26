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

int find(vector<int> &nums, int target, bool firstOcc) {
  int lo = 0, hi = nums.size() - 1;
  int result = -1;

  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (target == nums[mid]) {
      result = mid;
      firstOcc ? hi = mid - 1 : lo = mid + 1;
    } else if (target > nums[mid]) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  return result;
}
vector<int> searchRange(vector<int> &nums, int target) {
  int first = find(nums, target, 1);
  int last = find(nums, target, 0);
  return {first, last};
}
int main() {
  vector nums = {5, 7, 7, 8, 8, 10};
  int target = 8;
  auto result = searchRange(nums, target);

  printf("The first index is %d and the last index is %d\n", result[0],
         result[1]);
  printf("The number of occurrences is %d\n", result[1] - result[0] + 1);
}
