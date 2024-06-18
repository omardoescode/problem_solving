// This code is not valid yet as it got WA on kattis
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define fr(i, a, b, c)                                                         \
  for (int i = (a), _end = (b), _step = (c); i < _end; i += _step)

// Putting ratio as a value instead of a comparator by ratio
typedef tuple<double, int, int> dii; // (ratio r, num, den)
int main() {
  int n, b;
  while (scanf("%d %d", &n, &b), (n != -1 && b != -1)) {
    priority_queue<dii> pq;
    fr(i, 0, n, 1) {
      int a;
      scanf("%d", &a);

      pq.push({a / 1.0, a, 1}); // 1 box for city
    }

    // For the remaining boxes, assign another box to the greatest city in ratio
    // value and re-sort
    int remaining = b - n;
    while (remaining--, remaining != 0) {
      auto [r, num, den] = pq.top();
      pq.pop();
      pq.push({num / (den + 1), num, den + 1}); // reduce workload
    }

    printf("%d\n", (int)get<0>(pq.top()));
    fflush(stdout);
  }
  return 0;
}
