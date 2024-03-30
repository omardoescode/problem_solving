#include <bits/stdc++.h>

typedef std::pair<int, int> ii;

using namespace std;

struct m_int {
    int val, pos;

    bool operator<(const m_int &other) const {
        return val > other.val;
    }
};
/*
 * The idea of taking input is to handle all the calculations of finding smallest sums in two arrays and passing the values to the first array (we can call this merging), and then we take the next array to the second array as its values became unnecessary
 * To find the smallest sum, we used a struct to both convert our max heap to a min heap and to keep track of the position of the element we summed in the second array
 */
int main() {
    int k;
    while (scanf("%d", &k) != EOF) {
        int arr1[k], arr2[k];
        for (int i = 0; i < k; i++) scanf("%d", &arr1[i]);
        sort(arr1, arr1 + k);

        for (int _ = 0; _ < k - 1; _++) {
            for (int i = 0; i < k; i++) scanf("%d", &arr2[i]);
            sort(arr2, arr2 + k);
            priority_queue<m_int> vals;

            for (int i = 0; i < k; i++) vals.push({arr1[i] + arr2[0], 0});

            for (int i = 0; i < k; i++) {
                m_int tmp = vals.top();
                vals.pop();
                arr1[i] = tmp.val;
                if (tmp.pos + 1 < k)
                    vals.push({tmp.val - arr2[tmp.pos] + arr2[tmp.pos + 1], tmp.pos + 1});
            }
        }

        for (int i = 0; i < k - 1; ++i) printf("%d ", arr1[i]);
        printf("%d\n", arr1[k - 1]);
    }
}
