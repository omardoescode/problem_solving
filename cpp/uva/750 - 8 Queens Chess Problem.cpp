// This is the solution mentioned in Competitive Programming Ed 4
// Yet to re-create my own solution
// Commented by me, depending on my own understanding
#include <bits/stdc++.h>

#define DEBUGGING 1

#if not DEBUGGING
#define fflush(stdout);
#endif
using namespace std;

/*
 * Ideas of optimizations:
 * 1. The value of row[i] descrive s the row position of the Queen in column i
 * For column i, the row that occupies this column is row[i]
 * 2. Two diagonal queens Q(i, j) & Q(k, l) can attack each other if abs(i - k) == abs(j - l)
 */
int row[8], a, b, lineCounter;

bool canPlace(int r, int c) {
    for (int prev = 0; prev < c; prev++) // check previous queens
        // This doesn't work if any of the previous queens had the same row row[prev] == r
        // or if they are on the same diagonal
        if (row[prev] == r || abs(row[prev] - r) == abs(prev - c))
            return false;
    return true;
}

void backtrack(int c) {
    if ((c == 8) && row[b] == a) { // In case a case was found with all the queens (c == 8) where row[b] == a
        printf("%2d      %d", ++lineCounter, row[0] + 1);
        for (int i = 1; i < 8; ++i) printf(" %d", row[i] + 1);
        printf("\n");
        return;
    }

    for (int r = 0; r < 8; ++r) {
        if ((c == b) && (r != a)) continue; // If it's the same column as desired but a different row, continue
        if (canPlace(r, c))
            row[c] = r, backtrack(c + 1);
    }
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &a, &b);
        a--, b--;
        // fill default values for row and lineCounter
        memset(row, 0, sizeof row);
        lineCounter = 0;

        // Print values
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0);
        if (TC) printf("\n");
    }
}
