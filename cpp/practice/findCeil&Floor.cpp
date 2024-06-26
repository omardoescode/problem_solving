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

int ciel(int nums[], int size, int target) {
  int lo = 0, hi = size - 1;

  int ciel = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (nums[mid] == target) {
      return nums[mid];
    } else if (nums[mid] > target) {
      ciel = nums[mid];
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  return ciel;
}

int floor(int nums[], int size, int target) {
  int lo = 0, hi = size - 1;
  int floor = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (nums[mid] == target)
      return nums[mid];
    else if (nums[mid] < target) {
      floor = nums[mid];
      lo = mid + 1;
    } else
      hi = mid - 1;
  }

  return floor;
}

int main() {
  int nums[] = {1, 4, 6, 8, 9};
  printf("ciel of 2 is %d\n", ciel(nums, 5, 2));
  printf("floor of 2 is %d\n", floor(nums, 5, 2));
}
