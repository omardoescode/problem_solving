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

void backtrack(vector<string> &res, map<int, string> &values, string current,
               int i, string &digits) {
  if (i == digits.size()) {
    if (!current.empty())
      res.push_back(current);
    return;
  }

  for (const auto &chr : values[digits[i] - '0']) {
    backtrack(res, values, current + chr, i + 1, digits);
  }
}
vector<string> letterCombinations(string digits) {
  map<int, string> values;
  values[2] = "abc";
  values[3] = "def";
  values[4] = "ghi";
  values[5] = "jkl";
  values[6] = "mno";
  values[7] = "pqrs";
  values[8] = "tuv";
  values[9] = "wxyz";

  vector<string> res;
  backtrack(res, values, "", 0, digits);
  return res;
}
int main() {
  auto val = letterCombinations("23");
  for (auto &i : val) {
    DEBUG(i);
  }
  return 0;
}
