#include <bits/stdc++.h>

#define DEBUGGING 1

#if not DEBUGGING
#define fflush(stdout);
#endif
using namespace std;

int result, row[8], arr[64];

bool canPlace(int r, int c) {
    for (int prev = 0; prev < c; ++prev)
        if (row[prev] == r || abs(row[prev] - r) == abs(prev - c))
            return false;
    return true;
}

void backtrack(int c, int rsf) {
    if (c == 8) {
        result = max(result, rsf);
        return;
    }

    for (int r = 0; r < 8; r++) {
        if (canPlace(r, c))
            row[c] = r, backtrack(c + 1, rsf + arr[r * 8 + c]);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(row, 0, sizeof row);
        for (int i = 0; i < 64; i++) scanf("%d", &arr[i]);
        result = -1;
        backtrack(0, 0);
        printf("%5d", result);
        printf("\n");
    }
}
