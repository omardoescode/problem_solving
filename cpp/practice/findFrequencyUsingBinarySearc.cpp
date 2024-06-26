#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define inf 1000000000
#define f first
#define b first
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = (a), _end = (b); i < _end; i++)
#define sq(a) ((a) * (a))
#define debug(output) cout << output << endl

void findFrequency(int nums[], int n, unordered_map<int, int> &freq) {
  if (nums[0] == nums[n - 1]) {
    freq[nums[0]] += n;
    return;
  }
  findFrequency(nums, n / 2, freq);
  findFrequency(nums + n / 2, n - n / 2, freq);
}

// Keep searcing till finding the first array after lo that has the same element
// and when found update lo and freq, and also reset hi to n - 1
void findFrequencyIterative(int nums[], int n, unordered_map<int, int> &freq) {
  int lo = 0, hi = n - 1;
  while (lo <= hi) {
    if (nums[lo] == nums[hi]) {
      freq[nums[lo]] +=
          hi - lo +
          1; // This is addition because we don't get the exact repeatd arrays
      lo = hi + 1;
      hi = n - 1;
    } else {
      hi = (lo + hi) / 2;
    }
  }
}

int main() {
  unordered_map<int, int> freq;
  int nums[] = {2, 2, 2, 2, 4, 4, 4, 5, 5, 6, 6};
  findFrequencyIterative(nums, 11, freq);

  for (const auto &[f, s] : freq)
    printf("%d occurred %d\n", f, s);

  return 0;
}
