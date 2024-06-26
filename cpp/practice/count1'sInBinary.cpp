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

int findPeak(int nums[], int n) {
  int lo = 0, hi = n - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (mid == 0 && mid + 1 < n && nums[mid] > nums[mid + 1])
      return mid;
    if (mid == n - 1 && mid - 1 >= 0 && nums[mid] > nums[mid - 1])
      return mid;
    if (mid - 1 >= 0 && mid + 1 < n && nums[mid] > nums[mid + 1] &&
        nums[mid] > nums[mid - 1])
      return mid;

    if (mid + 1 < n && nums[mid + 1] > nums[mid])
      lo = mid + 1;
    else
      hi = mid - 1;
  }

  return -1; // no peak element
}

int main() {}
