#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define F first
#define B second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = (a), _end = (b); i < _end; i++)
#define SQ(a) ((a) * (a))
#define DEBUG(output) cout << output << endl

bool isSquare(ll sum) {
  ll lo = 0, hi = INT_MAX;
  while (lo <= hi) {
    ll mid = lo + (hi - lo) / 2;

    if (mid * mid == sum)
      return true;

    if (mid * mid < sum)
      lo = mid + 1;
    else
      hi = mid - 1;
  }

  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll sum = 0;
    while (n--) {
      ll temp;
      cin >> temp;
      sum += temp;
    }

    cout << (isSquare(sum) ? "YES" : "NO") << endl;

  }
}
