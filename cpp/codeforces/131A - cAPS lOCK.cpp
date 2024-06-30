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

  string word;
  cin >> word;
  bool applicable = true;

  for (int i = 1; i < word.size(); i++) {
    auto &c = word[i];
    if (isalpha(c) && islower(c))
      applicable = false;
  }

  if (applicable) {
    for (auto &c : word) {
      if (isupper(c))
        cout << (char)tolower(c);
      else if (islower(c))
        cout << (char)toupper(c);
    }
    cout << endl;
  } else
    cout << word << endl;

  return 0;
}
