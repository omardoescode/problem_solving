#include <bits/stdc++.h>

using namespace std;

int find_largest_divisor(int i) {
  if (i % 2 == 0) return i / 2;
  for (int k = 3; k < i; k += 2) {
    if (i % k == 0) return k;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  map<int,int> vals;
  vals[1] = 1;
  int max_val_in_vals = 1;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    iota(arr, arr + n, 1);

    for (int i = max_val_in_vals + 1; i <= n; i++) {
      vals[i] = find_largest_divisor(i);
    }

    int result = 0, ans;
    for (int i = 1; i <= n; i++) {
      if (vals[i] > result)
        result = vals[i], ans = i;
      else if (vals[i] == result)
        ans = max(i, ans);
    }

    cout << ans << endl;
  }

  return 0;
}
