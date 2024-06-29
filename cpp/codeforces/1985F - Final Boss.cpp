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

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll h, n;
    scanf("%llu %llu", &h, &n);

    vii attacks(n, MP(0,0));
    REP(i, 0, n) {
      scanf("%d", &attacks[i].first);
      h-=attacks[i].first;
    }
    REP(i, 0, n) {
      scanf("%d", &attacks[i].second);
    }

    if (h <=0 ) {printf("1\n"); continue;}

    ll lo = 0, hi = h * 2 * 1e5, res, mid;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;

      long long dmg = 0;
      for (auto& [attack, cooldown_const]: attacks)
        dmg += mid / cooldown_const * attack;

      if (dmg >= h) {
        res = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    printf("%llu\n", res + 1);
  }
}
