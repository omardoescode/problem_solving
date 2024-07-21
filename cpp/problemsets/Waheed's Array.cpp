#include <bits/stdc++.h>

using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (auto &c : arr)
      scanf("%d", &c);

    int count = 0;
    for (int i = 0; i < n / 2; i++) {
      if (arr[i] == arr[n - i - 1])
        continue;

      if (arr[i] % arr[n - i - 1] == 0 || arr[n - i - 1] % arr[i] == 0)
        count++;
      else
        count += 2;
    }

    printf("%d", count);
  }
}
