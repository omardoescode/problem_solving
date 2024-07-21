#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum subarray sum using Kadane's algorithm
int maxSubarraySum(const vector<int> &arr, int start, int end) {
  int max_sum = INT_MIN, current_sum = 0;
  for (int i = start; i <= end; i++) {
    current_sum = max(arr[i], current_sum + arr[i]);
    max_sum = max(max_sum, current_sum);
  }
  return max_sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    vector<int> left_max(n), right_max(n);

    // Compute maximum subarray sums for subarrays ending at each index
    // (left_max)
    int current_max = INT_MIN, current_sum = 0;
    for (int i = 0; i < n; i++) {
      current_sum = max(arr[i], current_sum + arr[i]);
      current_max = max(current_max, current_sum);
      left_max[i] = current_max;
    }

    // Compute maximum subarray sums for subarrays starting at each index
    // (right_max)
    current_max = INT_MIN, current_sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      current_sum = max(arr[i], current_sum + arr[i]);
      current_max = max(current_max, current_sum);
      right_max[i] = current_max;
    }

    // Find the optimal split point to minimize the absolute difference between
    // left and right sums
    int min_diff = INT_MAX;
    for (int p = 1; p < n; p++) {
      int left_sum = left_max[p - 1];
      int right_sum = right_max[p];
      min_diff = min(min_diff, abs(left_sum - right_sum));
    }

    cout << min_diff << '\n';
  }

  return 0;
}
