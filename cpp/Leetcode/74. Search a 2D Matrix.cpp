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

bool searchMatrix(vector<vector<int>> &matrix, int target) {
  // Find the maximum number that is less than target
  int loC = 0, hiC = matrix.size() - 1;
  int lookInto = matrix.size();
  while (loC <= hiC) {
    int mid = loC + (hiC - loC) / 2;

    if (matrix[mid][0] == target)
      return true;
    else if (matrix[mid][0] < target) {
      lookInto = mid;
      loC = mid + 1;
    } else
      hiC = mid - 1;
  }

  if (lookInto == matrix.size())
    return false;

  // Binary Search in that array
  auto &mtx = matrix[lookInto];
  int lo = 0, hi = mtx.size() - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;

    if (mtx[mid] == target)
      return true;
    else if (mtx[mid] < target)
      lo = mid + 1;
    else
      hi = mid - 1;
  }

  return false;
}
int main() {}
