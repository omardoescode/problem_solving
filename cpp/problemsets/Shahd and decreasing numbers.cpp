#include <bits/stdc++.h>

using namespace std;



bool is_decreasing(int num) {
  int temp = (num | (num - 1)) + 1;
  if ((temp & (temp - 1)) == 0)
    return true;
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  int t;cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int count = 0;
    for (int i = l; i <= r; i++) {
      count += is_decreasing(i);
    }
    cout << count << endl;
  }



  return 0;
}
