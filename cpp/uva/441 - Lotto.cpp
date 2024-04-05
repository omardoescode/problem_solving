#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, counter = 1;
    while (scanf("%d", &k) && k != 0) {
        if (counter > 1) printf("\n");
        int arr[k];
        for (int i = 0; i < k; i++) scanf("%d", &arr[i]);

        for (int a = 0; a < k - 5; a++)
            for (int b = a + 1; b < k - 4; b++)
                for (int c = b + 1; c < k - 3; c++)
                    for (int d = c + 1; d < k - 2; d++)
                        for (int e = d + 1; e < k - 1; e++)
                            for (int f = e + 1; f < k; f++)
                                printf("%d %d %d %d %d %d\n", arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);
        counter++;
    }
}
