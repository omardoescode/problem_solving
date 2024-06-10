#include <bits/stdc++.h>

using namespace std;

int n, arr[100000];

bool can(int k) {
  if (arr[0] > k)
    return false; // First jump
  if (arr[0] == k)
    k--;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i + 1] - arr[i] > k)
      return false;
    if (arr[i + 1] - arr[i] == k)
      k--;
  }
  return true;
}

int main() {
  int TC, counter = 1;
  scanf("%d", &TC);
  int lo, hi;
  while (TC--) {
    lo = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
      if (i != 0)
        hi = max(hi, arr[i] - arr[i - 1]);
      else
        hi = arr[i];
    }

    while (lo < hi) {
      int mid = (lo + hi) / 2;
      can(mid) ? hi = mid : lo = mid + 1;
      // if mid_value works, we want to search in a range where mid is there as
      // well, but if mid doesn't work, we no longer want it in that range
    }

    printf("Case %d: %d\n", counter++, hi);
    fflush(stdout);
  }
}
