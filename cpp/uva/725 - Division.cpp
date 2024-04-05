#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, tmp, counter = 1;
    while (scanf("%d", &n) && n != 0) {
        if (counter > 1) {
            printf("\n");
            fflush(stdout);
        }
        bool solutions = false;
        for (int fghij = 01234; fghij <= 98765 / n; fghij++) {
            int abcde = fghij * n;
            int used = fghij < 10000;
            tmp = abcde;
            while (tmp) {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            tmp = fghij;
            while (tmp) {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }

            if (used == (1 << 10) - 1) {
                printf("%05d / %05d = %d\n", abcde, fghij, n);
                fflush(stdout);
                solutions = true;
            }
        }
        if (!solutions) {
            printf("There are no solutions for %d.\n", n);
            fflush(stdout);
        }

        counter++;
    }
}
