#include <bits/stdc++.h>

using namespace std;

int main() {
  int a[3], b[3];

  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  sort(b, b + 3);

  int result = 0;
  do {
    int trial = 1;
    for (int i = 0; i < 3; i++)
      trial *= a[i] / b[i];
    result = max(trial, result);
  } while (next_permutation(b, b + 3));

  cout << result << endl;
}
