#include <bits/stdc++.h>

using namespace std;
int main() {
  std::string word;
  cin >> word;

  map<char, int> val;

  for (const auto &c : word) {
    if (val.find(c) != val.end())
      val[c]++;
    else
      val[c] = 1;
  }

  int odd_ones = 0;
  for (const auto &[c, i] : val) {
    if (i % 2)
      odd_ones++;
  }

  if (odd_ones == 0)
    cout << "First" << endl;
  else if (odd_ones % 2)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
}
