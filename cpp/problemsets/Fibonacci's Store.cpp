#include <bits/stdc++.h>

using namespace std;



int main() {
  long long fib[1005];
  fib[1] = 1, fib[2] = 1;
  int max_val_in_fib = 2;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    for (int i = max_val_in_fib + 1; i <= n + 2; i++) {
      (fib[i] = fib[i - 1] + fib[i - 2]);
    }
    max_val_in_fib = n;

    int count = 0;
    for (int i = 1; i <= n + 2; i++) {
      count+= fib[n] % fib[i] == 0;
    }

    cout <<count << endl;
  }
  return 0;
}
