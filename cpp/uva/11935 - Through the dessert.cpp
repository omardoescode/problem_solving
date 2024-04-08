#include <bits/stdc++.h>

using namespace std;

const int EPS = 1e-9;

/*
* An event is pair(d, n)
* d is the distance at which the event occurred
* n is one of
* - <= num -> consumption by the -n
* - = 1 -> leak
* - = 2 -> gas station
* - = 3 -> mechanic
* - = 4 -> goal
*/
vector<pair<int, int>> events;

// Simulation for the events with some initial capacity
bool works(double test) {
    double initial_val = test, cur_consumption, leak_rate = 0, cur_d = 0, dt;
    for (auto &event: events) {
        test -= (event.first - cur_d) / 100.0 * cur_consumption; // consumption per 100
        test -= (event.first - cur_d) * leak_rate;

        if (test < 0) return false; // Cannot be zero at any time t

        if (event.second <= 0)
            cur_consumption = -event.second;
        else if (event.second == 1) // Leak
            ++leak_rate;
        else if (event.second == 2) // Gas Station
            test = initial_val;
        else if (event.second == 3) // Mechanic
            leak_rate = 0;
        else if (event.second == 4) // Goal
            break;

        cur_d = event.first;
    }

    return (test >= 0.0);
}

int main() {
    int n;
    char line[100];
    while (scanf("0 Fuel consumption %d\n", &n), n) {
        events.clear(); // restart
        events.push_back({0, -n});
        int d;
        while (true) {
            scanf("%d ", &d);
            gets(line);
            if (strncmp(line, "Fuel", 4) == 0) {
                sscanf(line, "Fuel consumption %d", &n); // not from stdin
                events.emplace_back(d, -n);
            } else if (strcmp(line, "Leak") == 0) {
                events.emplace_back(d, 1);
            } else if (strcmp(line, "Gas station") == 0) {
                events.emplace_back(d, 2);
            } else if (strcmp(line, "Mechanic") == 0) {
                events.emplace_back(d, 3);
            } else if (strcmp(line, "Goal") == 0) {
                events.emplace_back(d, 4);
                break;
            }
        }

        double lo = 0, hi = 10000.0;
        while (fabs(hi - lo) > EPS) {
            double mid = (hi + lo) / 2.0;
            // if the mid value can work as an initial capacity, we will try some lower value
            works(mid, events) ? hi = mid : lo = mid;
        }

        printf("%.3lf\n", hi); // A double to three precision points
        fflush(stdout);
    }
}
