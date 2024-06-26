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

// We modify binary Search to continue searching when finding the target on the
// left subarray while keeping the target index found If it finds a new target
// occurrence at the left sub-array, update the result variable and keep looking
// until lo <= hi the initial value has to be -1 in case target is not found
int findFirstOccurrence(int nums[], int target, int n) {
  int lo = 0, hi = n - 1;
  int result = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (target == nums[mid]) {
      result = mid;
      hi = mid - 1;
    }

    if (target > nums[mid]) {
      lo = mid + 1;
    } else if (target < nums[mid]) {
      hi = mid - 1;
    }
  }
  return result; // Unsorted or target not found
}

int findLastOccurrence(int nums[], int target, int n) {
  int lo = 0, hi = n - 1;
  int result = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (target == nums[mid]) {
      result = mid;
      lo = mid + 1;
    }

    if (target > nums[mid]) {
      lo = mid + 1;
    } else if (target < nums[mid]) {
      hi = mid - 1;
    }
  }
  return result; // Unsorted or target not found
}
int main() {
  int nums[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
  int target = 5;
  printf("The first occurrence of target is at index %d\n",
         findFirstOccurrence(nums, target, 10));
  printf("The last occurrence of target is at index %d\n",
         findLastOccurrence(nums, target, 10));
}
