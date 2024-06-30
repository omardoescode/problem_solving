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

struct pos {
  int x, y;

  bool is_valid(int n) { return x > 0 && x <= n && y > 0 && y <= n; }
  bool operator==(pos &other) { return x == other.x && other.y == y; }
};
// if both are odd or both are even
bool possible(pos &f, pos &t) { return (f.x + f.y) % 2 == (t.x + t.y) % 2; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int TC;
  cin >> TC;
  while (TC--) {
    int t, n;
    cin >> t >> n;

    while (t--) {
      pos f, t;
      cin >> f.x >> f.y >> t.x >> t.y;

      if (!possible(f, t))
        cout << "no move" << endl;
      else if (f == t)
        cout << 0 << endl;
      else if (abs(f.y - t.y) == abs(f.x - t.x))
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }

  return 0;
}
