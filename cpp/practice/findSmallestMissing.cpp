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

int findSmallestMissing(int nums[], int n) {
  int lo = 0, hi = n - 1;
  int result = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (nums[mid] != mid) {
      result = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  return result;
}

// Recurseve Solution
int findSmallestMissingRec(int nums[], int lo, int hi) {
  if (lo > hi)
    return lo;
  int mid = (lo + hi) / 2;

  if (mid == nums[mid])
    return findSmallestMissingRec(nums, mid + 1, hi);
  return findSmallestMissingRec(nums, lo, mid - 1);
}

int main() {
  int nums[] = {1, 2, 3, 4, 6, 9, 11, 15};
  printf("The smallest missing element is %d\n",
         findSmallestMissingRec(nums, 0, 8));
  return 0;
}
