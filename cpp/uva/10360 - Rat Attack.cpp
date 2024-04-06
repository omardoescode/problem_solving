/*
 * Lesson learned:
 * Look at the problem from backwards:
 * instead of going at every place to bomb, just have an accumlator array that for each index (x, y) if a bomb is directed here, add it to the accumlator array for every cell that will kill this rat population
 */
#include <bits/stdc++.h>

using namespace std;


int killed[1025][1025];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int d, n;
        scanf("%d", &d);
        scanf("%d", &n);
        memset(killed, 0, sizeof killed);

        int max_i = 0, max_j = 0;
        // take input
        for (int k = 0; k < n; k++) {
            int x, y, strength;
            scanf("%d %d %d", &x, &y, &strength);
            x--;
            y--;
            for (int i = max(0, x - d); i < min(1025, x + d + 1); i++)
                for (int j = max(0, y - d); j < min(1025, y + d + 1); j++) {
                    killed[i][j] += strength;
                    if (killed[i][j] > killed[max_i][max_j] ||
                        (killed[i][j] == killed[max_i][max_j] && (i < max_i || i == max_i && j < max_j)))
                        max_i = i, max_j = j;
                }
        }

        printf("%d %d %d\n", max_i + 1, max_j + 1, killed[max_i][max_j]);
    }
}
