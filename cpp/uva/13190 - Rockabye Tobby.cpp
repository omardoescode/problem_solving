#include <bits/stdc++.h>

using namespace std;


struct med {
    string name;
    int fre;
    int actual;
    int priority;

    bool operator<(const med &other) const {
        if (actual != other.actual) return actual > other.actual;
        return priority > other.priority;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;

        cin >> n >> k;
        priority_queue<med> meds;
        for (int i = 0; i < n; i++) {
            string name;
            int fre;
            cin >> name >> fre;
            meds.push({name, fre, fre, i});
        }


        while (k--) {
            auto tmp = meds.top();
            meds.pop();
            cout << tmp.actual << " " << tmp.name << "\n";
            meds.push({tmp.name, tmp.fre, tmp.actual + tmp.fre, tmp.priority});
        }
    }
}
