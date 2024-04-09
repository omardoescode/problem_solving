#include <bits/stdc++.h>

using namespace std;

int binary_search(const int *arr, int n, int val) {
    int lo = 0, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == val) {
            for (; mid > 0 && arr[mid - 1] == arr[mid]; mid--); // to get the first value
            return mid;
        } else if (arr[mid] < val)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int main() {
    int n, q, counter = 1;
    while (scanf("%d %d", &n, &q), n && q) {
        int arr[n];
        // index + 1 : the marble number
        // val: the number on the marble
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr + n);
        printf("CASE# %d:\n", counter++);
        for (int i = 0; i < q; i++) {
            int val;
            scanf("%d", &val);
            int res = binary_search(arr, n, val);
            if (res == -1) {
                printf("%d not found\n", val);
            } else {
                printf("%d found at %d\n", val, res + 1);
            }
        }
    }
}
