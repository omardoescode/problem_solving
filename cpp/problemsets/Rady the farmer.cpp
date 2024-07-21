#include <bits/stdc++.h>

using namespace std;
#define int long long

int backtrack(int count, int y, int z, int rsf) {
  if (count >= z) {
    return rsf;
  }
  return backtrack(max(count * 3 + y, (count + y) * 3), y, z, rsf + 1);
}


signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y, z, result;
  cin >> x >> y >> z;
  cout << backtrack(x, y, z, 0) << endl;
  return 0;
}
