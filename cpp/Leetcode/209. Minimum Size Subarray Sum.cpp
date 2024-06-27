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

int minSubArrayLen(int target, vector<int> &nums) {
  int i = 0, j = 0;
  int current_sum = 0;
  int result = nums.size() + 1;

  while (j < nums.size()) {
    current_sum += nums[j++];

    while (current_sum - nums[i] >= target)
      current_sum -= nums[i++];

    if (current_sum >= target)
      result = min(result, j - i);
  }

  return result == nums.size() + 1 ? 0 : result;
}
