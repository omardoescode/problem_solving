#include <bits/stdc++.h>

using namespace std;

int books[10000], cur_i = 0, n, m;

bool binarySearch(int b, int start) {
    int lo = start, hi = n, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (books[mid] == b)
            return true;
        else if (books[mid] < b)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    return false;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%d", &books[i]);
        scanf("%d", &m);

        sort(books, books + n);
        int i = books[0], j = books[n - 1];
        for (int k = 0; k < n; k++) {
            int b1 = books[k];
            int b2 = m - b1;

            if (b1 > b2)
                break;


            if (binarySearch(b2, k + 1)) {
                if (b2 - b1 < j - i) {
                    i = b1;
                    j = b2;
                }
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", i, j);
        fflush(stdout);
    }
}
