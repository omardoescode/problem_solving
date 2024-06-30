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

bool valid(int a, int b, int c) { return c * c == a * a + b * b; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int TC;
  cin >> TC;
  while (TC--) {
    int a, b, c;
    cin >> a >> b >> c;
    bool solution = false;
    for (int x = -100; x <= 100 && !solution; x++) {
      if (x * x > c)
        continue;
      for (int y = -100; y <= 100 && !solution; y++) {
        if (x * x + y * y > c || x == y)
          continue;
        for (int z = -100; z <= 100 && !solution; z++) {
          if (x == z || y == z)
            continue;
          if (x * x + y * y + z * z == c && x + y + z == a && x * y * z == b) {
            cout << x << " " << y << " " << z << endl;
            solution = true;
          }
        }
      }
    }

    if (!solution) {
      cout << "No solution." << endl;
    }
  }

  return 0;
}

