#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    int books[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &books[i]);

    int sum = 0, j = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        sum += books[i];
        while (sum > t) {
            sum -= books[j];
            j++;
        }

        ans = max(ans, i - j + 1);
    }

    printf("%d", ans);
}
