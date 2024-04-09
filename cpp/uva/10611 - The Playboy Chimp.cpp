#include <bits/stdc++.h>

using namespace std;


int binary_search(const int *arr, int n, int val) {
    int lo = 0, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (mid + 1 == n && arr[mid] < val)
            return mid;
        if (arr[mid] < val && arr[mid + 1] >= val)
            return mid;
        else if (arr[mid] < val)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int main() {
    int n, q, val;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &val);
        int res = binary_search(arr, n, val);
        if (res == -1) {
            printf("X ");
        } else {
            printf("%d ", arr[res]);
        }
        for (res = res == -1 ? 0 : res; res < n && arr[res] <= val; res++);
        if (res == n)
            printf("X\n");
        else
            printf("%d\n", arr[res]);
    }

}
