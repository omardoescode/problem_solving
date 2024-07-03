// Refer back to the original solution. I couldn't solve it but rather
// understood it from here My original solution was similar
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int TC;
  scanf("%d", &TC);
  while (TC--) {
    int p, c;
    scanf("%d %d", &p, &c);
    int prod[p], cons[c], all[p + c + 1];

    for (int i = 0; i < p; i++) {
      scanf("%d", &prod[i]);
      all[i] = prod[i];
    }

    for (int i = 0; i < c; i++) {
      scanf("%d", &cons[i]);
      all[p + i] = cons[i];
    }

    all[p + c] = 0; // insert a zero value that is might be true in case
                    // there are either no producers or consumers
    sort(prod, prod + p);
    sort(cons, cons + c);
    sort(all, all + p + c + 1);

    int angry = INT_MAX, price;

    for (const auto &i : all) {
      int test = (lower_bound(cons, cons + c, i) - cons) +
                 (p - (upper_bound(prod, prod + p, i) - prod));
      if (test < angry)
        angry = test, price = i;
    }

    printf("%d %d\n", price, angry);
  }

  return 0;
}
