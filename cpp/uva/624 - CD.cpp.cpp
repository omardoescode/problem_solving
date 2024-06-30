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

void backtrack(int arr[], int d, int max_minutes, int i, int rsf, int &result,
               vector<int> &vals, vector<int> &curr) {
  if (i == d) {
    if (rsf <= max_minutes && rsf > result) {
      result = rsf;
      vals = curr; // Update vals with the current best combination
    }
    return;
  }

  // Include arr[i] in the current combination
  curr.push_back(arr[i]);
  backtrack(arr, d, max_minutes, i + 1, rsf + arr[i], result, vals, curr);
  curr.pop_back();

  // Exclude arr[i] from the current combination
  backtrack(arr, d, max_minutes, i + 1, rsf, result, vals, curr);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int max_minutes, d;
  while (cin >> max_minutes >> d) {
    int arr[d];
    REP(i, 0, d) { cin >> arr[i]; }

    int result = 0;
    vector<int> vals, curr;
    backtrack(arr, d, max_minutes, 0, 0, result, vals, curr);

    for (const auto &val : vals)
      cout << val << " ";
    cout << "sum:" << result << endl;
  }

  return 0;
}
