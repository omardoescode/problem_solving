#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define SQ(a) ((a) * (a))
#define DEBUG(output) cout << output << endl

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, b;
  while (cin >> n >> b, !(n == -1 && b == -1)) {
    priority_queue<tuple<double, int, int>> pq;
    REP(i, 0, n) {
      ll a;
      cin >> a;
      pq.push({a, a, 1});
    }

    int remaining = b - n;
    while (remaining > 0) {
      auto [ratio, num, den] = pq.top();
      pq.pop();
      pq.push({num / (den + 1), num, den + 1});
      remaining--;
    }

    auto [final_ratio, final_num, final_den] = pq.top();
    cout << (final_num + final_den - 1) / final_den << endl;
  }

  return 0;
}
