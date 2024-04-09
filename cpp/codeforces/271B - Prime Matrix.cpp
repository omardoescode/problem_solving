#include <bits/stdc++.h>
#include <climits>

using namespace std;

int prime_nums[100015], prime_nums_counter = 0, arr[100015];

bool is_prime(const int &n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}

void fill_in_prime() {
    for (int i = 0; i < 100015; i++)
        if (is_prime(i))
            prime_nums[prime_nums_counter++] = i;
}

void fill_in_arr() {
    int i = 0, k;
    for (k = 0; k < 100001; k++) {
        i += k > prime_nums[i];
        arr[k] = prime_nums[i] - k;
        //printf("%d %d %d\n", k, prime_nums[i], arr[k]);
    }
}

int main() {
    fill_in_prime();
    fill_in_arr();

    int n, m;
    scanf("%d %d", &n, &m);

    int matrix[n][m], temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &temp);
            matrix[i][j] = arr[temp];
        }

    int ans = INT_MAX;
    // Get sum of rows
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++)
            sum += matrix[i][j];
        ans = min(ans, sum);
    }
    // Get sum of cols
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += matrix[j][i];
        ans = min(ans, sum);
    }

    printf("%d", ans);
}
