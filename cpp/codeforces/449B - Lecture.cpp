#include <bits/stdc++.h>
#include <cctype>
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

  int n, m;
  cin >> n >> m;

  map<string, string> langs;
  REP(i, 0, m) {
    string val1, val2;
    cin >> val1 >> val2;

    langs[val1] = val2;
  }

  REP(i, 0, n) {
    string val1;
    cin >> val1;

    cout << min(val1, langs[val1], [&](auto &val1, auto &val2) {
      return val1.size() < val2.size();
    });
    if (i != n - 1)
      cout << " ";
  }

  return 0;
}

