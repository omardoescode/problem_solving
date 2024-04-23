#include <bits/stdc++.h>
using namespace std;

int main() {
  int mass[10];
  int c, s, counter = 1;
  while (scanf("%d %d", &c, &s) != EOF) {
    double average = 0, imbalance = 0;
    for (int i = 0; i < s; i++) {
      scanf("%d", &mass[i]);
      average += mass[i];
    }
    average /= c;
    for (int i = s; i < 2 * c; i++)
      mass[i] = 0;

    printf("Set #%d\n", counter++);
    sort(mass, mass + 2 * c);

    for (int i = 0; i < c; i++) {
      printf(" %d:", i);
      if (mass[i])
        printf(" %d", mass[i]);
      if (mass[2 * c - i - 1])
        printf(" %d", mass[2 * c - i - 1]);
      printf("\n");
      imbalance += abs(mass[i] + mass[2 * c - i - 1] - average);
    }
    printf("IMBALANCE = %05f\n\n", imbalance);
  }
}
