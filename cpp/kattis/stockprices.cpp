#include <bits/stdc++.h>

#define DEBUGGING 0

#define SYNC                                                                   \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL)

typedef std::pair<int, int> ii;

using namespace std;

struct sell {
    int shares, ask;

    bool operator<(const sell &other) const {
        return ask > other.ask; // min heap
    }
};

struct buy {
    int shares, bid;

    bool operator<(const buy &other) const {
        return bid < other.bid; // max heap
    }
};

int main() {
    SYNC;
    int t, counter = 0;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int last_stock = -1;
        priority_queue<sell> sells; // we want this to be a min heap
        priority_queue<buy> buys; // we want this to be a max heap

        string order, _;
        int x, y;
        while (n--) {
            if (counter != 0) cout << "\n";
            cin >> order >> x;
            for (int i = 0; i < 2; i++) cin >> _;
            cin >> y;

            if (order == "sell") {
                sells.push({x, y});
            } else if (order == "buy") {
                buys.push({x, y});
            }

            while (!(buys.empty() || sells.empty())) {
                auto buy_top = buys.top();
                auto sell_top = sells.top();
                if (buy_top.bid >= sell_top.ask) {
                    last_stock = sell_top.ask;
                    int shares = min(buy_top.shares, sell_top.shares);
                    buy_top.shares -= shares;
                    sell_top.shares -= shares;

                    buys.pop();
                    sells.pop();

                    if (buy_top.shares > 0)
                        buys.push(buy_top);
                    if (sell_top.shares > 0)
                        sells.push(sell_top);
                } else {
                    break;
                }
            }

            if (!sells.empty()) cout << sells.top().ask;
            else cout << "-";
            cout << " ";
            if (!buys.empty()) cout << buys.top().bid;
            else cout << "-";
            cout << " ";
            if (last_stock != -1) cout << last_stock;
            else cout << "-";

            counter++;
        }
    }
}
