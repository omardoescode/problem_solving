#include <bits/stdc++.h>

using namespace std;

// Ofc, one can use std::next_permutation, but this ain't fun while learning
/*
bool next_permutation(vector<int>& nums) {
	return next_permutation(nums.begin(), nums.end());
}
*/
bool next_permutation(vector<int> &nums) {
    int n = nums.size(), i, j;
    for (i = n - 2; i >= 0 && nums[i] >= nums[i + 1]; i--); // keep going as it's non-increasing order

    // special case: descending order
    if (i < 0) {
        // alternatives are sorting or reversing using a for loop for n/2 elements
        reverse(nums.begin(), nums.end());
        return false;
    }

    // other cases
    // swap with the least element greater than the pivot then sort
    for (j = n - 1; j > i && nums[j] <=
                             nums[i]; j--); // keep going as long as the numbers are less than the number before the pivot
    swap(nums[i], nums[j]);
    sort(nums.begin() + i + 1, nums.end());
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    do {
        for (int i = 0; i < n - 1; i++) {
            printf("%d ", nums[i]);
        }
        printf("%d\n", nums[n - 1]);
    } while (next_permutation(nums));

}
