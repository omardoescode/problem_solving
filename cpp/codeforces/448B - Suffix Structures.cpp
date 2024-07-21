#include <bits/stdc++.h>

using namespace std;
bool test_automation(const std::string &s, const std::string &t) {
  int j = 0;
  for (int i = 0; i < s.length() && j < t.length(); i++) {
    if (s[i] == t[j])
      j++;
  }
  return j == t.length();
}

bool test_array(const string &s, const string &t) {
  if (s.length() != t.length())
    return false;
  map<char, int> ss, tt;

  for (char c : s)
    ss[c]++;
  for (char c : t)
    tt[c]++;

  return ss == tt;
}

bool test_automation_and_array(const string &s, const string &t) {
  // cout << s << " " << t << endl;
  if (s.length() < t.length())
    return false;
  map<char, int> ss, tt;

  for (char c : s)
    ss[c]++;
  for (char c : t)
    tt[c]++;

  // for (const auto &[c, i] : ss) {
  //   cout << c << " " << i << endl;
  // }
  // cout << "Second table" << endl;
  // for (const auto &[c, i] : tt) {
  //   cout << c << " " << i << endl;
  // }

  for (const auto &[c, i] : tt) {
    if (ss[c] < i) {
      return false;
    }
  }

  return true;
}

int main() {
  string s, t;
  cin >> s >> t;
  if (test_automation(s, t))
    cout << "automaton";
  else if (test_array(s, t))
    cout << "array";
  else if (test_automation_and_array(s, t))
    cout << "both";
  else
    cout << "need tree";
}
