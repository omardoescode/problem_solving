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

int maxSubArray(vector<int> &nums) {
  int sum = INT_MIN / 2, best = INT_MIN;
  for (int k = 0; k < nums.size(); k++) {
    sum = max(sum + nums[k], nums[k]);
    best = max(sum, best);
  }
  return best;
}
int main() {}
