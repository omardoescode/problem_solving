#include <bits/stdc++.h>
using namespace std;
typedef long long ll;      // comments that are mixed in with code
typedef pair<int, int> ii; // are aligned to the right like this
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000 // 1 billion, safer than 2B for Floyd Warshall’s
#define fr(i, a, b, c)                                                         \
  for (int i = (a), _end = (b), _step = (c); i < _end; i += _step)

double EPS = 1e-9;

int n, m, knights[20015], heads[20015];

int main() {
  while (scanf("%d %d", &n, &m), (n != 0 || m != 0)) {
    // if (n > m) {
    //   printf("Lootwater is doomed");
    //   continue;
    // }
    fr(i, 0, n, 1) { scanf("%d", &heads[i]); }
    fr(i, 0, m, 1) { scanf("%d", &knights[i]); }

    sort(heads, heads + n);
    sort(knights, knights + m);
    int gold = 0, k = 0, d = 0;
    while (k < m && d < n) {
      while (k < m && heads[d] > knights[k])
        k++;
      if (k == m)
        break;
      gold += knights[k];
      d++, k++;
    }

    if (d != n) {
      printf("Loowater is doomed!\n");
    } else {
      printf("%d\n", gold);
    }
  }
}
