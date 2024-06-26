#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define inf 1000000000
#define f first
#define b first
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = (a), _end = (b); i < _end; i++)
#define sq(a) ((a) * (a))
#define debug(output) cout << output << endl

int findMissingTerm(int nums[], int n) {
  int lo = 0, hi = n - 1, diff = (nums[n - 1] - nums[0]) / n;

  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (mid - 1 >= 0 && nums[mid] - nums[mid - 1] != diff)
      return nums[mid] - diff;
    if (mid + 1 < n && nums[mid + 1] - nums[mid] != diff)
      return nums[mid] + diff;

    if (nums[mid] - nums[0] != diff * (mid - 0))
      hi = mid - 1;
    else 
      lo = mid + 1;
  }

  return -1; // Invalid Input
}

int main() {
    int nums[] = { 5, 7, 9, 11, 15 };
    int n = sizeof(nums) / sizeof(nums[0]);
 
    printf("The missing term is %d\n", findMissingTerm(nums, n));
 
    return 0;
}
