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

void backtrack(vector<vector<int>> &res, vector<int> &state, int rsf, int start,
               vector<int> &candidates, const int &target) {
  if (rsf == target) {
    res.push_back(state);
    return;
  }
  if (rsf > target || start == candidates.size()) {
    return;
  }
  state.push_back(candidates[start]);
  backtrack(res, state, rsf + candidates[start], start, candidates, target);
  state.pop_back();
  backtrack(res, state, rsf, start + 1, candidates, target);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  vector<vector<int>> res;
  vector<int> state;

  backtrack(res, state, 0, 0, candidates, target);

  return res;
}
int main() {}
