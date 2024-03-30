#include <bits/stdc++.h>

#define DEBUGGING 0

#define SYNC                                                                   \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL)

typedef std::pair<int, int> ii;

using namespace std;


struct moose {
    int year{}, strength{};
    bool is_akal = false;

    bool operator<(const moose &other) const {
        return strength < other.strength;
    }
};

int main() {
    SYNC;
    int k, n, y, p;
    cin >> k >> n >> y >> p;

    moose arr[n + k - 2];
    int max_year = 2011;

    for (int i = 0; i < n + k - 2; i++) {
        int year, strength;
        cin >> year >> strength;
        arr[i] = {year, strength};
        max_year = max(max_year, year);
    }

    sort(arr, arr + n + k - 2, [](const moose &a, const moose &b) {
        return a.year < b.year;
    });

    int current_year = 2011;
    priority_queue<moose> vals;

    int i = 0;
    while (arr[i].year <= max_year) {
        while (arr[i].year == current_year) {
            vals.push(arr[i]);
            i++;
        }
        if (y == current_year) {
            vals.push({y, p, true});
        }

        if (vals.size() != k) {
            cout << "unknown";
            return 0;
        }

        auto tmp = vals.top();
        if (tmp.is_akal) {
            cout << current_year;
            return 0;
        }
        vals.pop();
        current_year++;
    }

    cout << "unknown";
}
