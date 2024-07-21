#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    l--, r--;

    int arr[n];
    for (auto &c : arr)
      scanf("%d", &c);

    int max_length = 0, min_operations = INT_MAX;
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j + 1 < n && arr[j] > arr[j + 1]) {
        j++;
      }

      int length = j - i + 1, operations = abs(j - r) + abs(i - l);

      if (length > max_length)
        max_length = length, min_operations = operations;
      else if (length == max_length)
        min_operations = min(operations, min_operations);

      i = j;
    }

    printf("%d %d", max_length, min_operations);
  }
}
