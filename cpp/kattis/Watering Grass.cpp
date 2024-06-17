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

struct interval {
  int x, r;
  double leftpoint, rightpoint;

  bool operator<(const interval &other) {
    if (fabs(leftpoint - other.leftpoint) > EPS) {
      return leftpoint < other.leftpoint;
    }
    return rightpoint > other.rightpoint;
  }
};

int n;
double l, w;
int main() {
  interval ints[10000];
  while (scanf("%d %lf %lf", &n, &l, &w) != EOF) {
    fr(i, 0, n, 1) {
      scanf("%d %d", &ints[i].x, &ints[i].r);
      // Will need to unselect the ones with a diameter < w
      if (2 * ints[i].r < w) {
        ints[i].leftpoint = ints[i].rightpoint = ints[i].x;
      } else {
        int r = ints[i].r, x = ints[i].x;
        double dx = sqrt(r * r - (w * w / 4.0));
        ints[i].leftpoint = x - dx;
        ints[i].rightpoint = x + dx;
      }
    }
    sort(ints, ints + n);

    bool possible = true;
    int count = 0;
    double covered = 0;
    for (int i = 0; i < n && possible; i++) {
      if (covered > l + EPS)
        break; // We are done
      if (ints[i].rightpoint < covered + EPS)
        continue; // covered already
      if (ints[i].leftpoint < covered + EPS) {
        // Check the right ones for the highest coverage to choose
        double max_rightpoint = -1;
        int max_id = -1;
        for (int j = i; j < n && ints[j].leftpoint < covered + EPS; j++) {
          if (ints[j].rightpoint > max_rightpoint) {
            max_rightpoint = ints[j].rightpoint;
            max_id = j;
          }
        }
        count++, covered = max_rightpoint, i = max_id;
      } else {
        possible = false;
      }
    }

    if (!possible || covered < l - EPS)
      printf("-1\n");
    else
      printf("%d\n", count);
  }
}
