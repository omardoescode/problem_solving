#include <bits/stdc++.h>

using namespace std;

int arr[21];

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int n, p;
        scanf("%d %d", &n, &p);
        for (int i = 0; i < p; i++)
            scanf("%d", &arr[i]);

        bool solution = false;
        // This solution depends on creating the subsets using bit manipulation
        for (int i = 0; i < (1 << p) && !solution; i++) {
            // Solution 1
            int sum = 0;
            /*
            // i is a bit mask for each iteration
            for (int j = 0; j < p; j++)
                if (i & (1 << j)) // check if the j-th item is set on in the current mask
                    sum += arr[j];
             */

            // Solution 2
            int mask = i;
            while (mask) {
                int two_pow_j = mask & -(mask);
                int j = __builtin_ctz(two_pow_j);
                sum += arr[j];
                mask -= two_pow_j;
            }

            solution = sum == n;
        }

        printf("%s\n", solution ? "YES" : "NO");
        fflush(stdout);
    }
}
