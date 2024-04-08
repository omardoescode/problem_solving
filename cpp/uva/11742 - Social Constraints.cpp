#include <bits/stdc++.h>

using namespace std;

const int EPS = 1e-9;

/*
 * A constaint is (a, b, c)
 * a is the first person number
 * b is the second person number
 * c is a number
 * if positive, a and b must be at most c seats apart
 * if negative, a and b must be at least -c seats apart
 */
struct Constraint {
    int a, b, c;
};

vector<Constraint> constraints;
int n, m, teens[10], a, b, c;

/*
 * Teens is an array of [index, val]
 * index is the number of the teen
 * val is the place where he will be sitting
 */

int main() {
    while (scanf("%d %d", &n, &m), n != 0 || m != 0) {
        constraints.clear();
        iota(teens, teens + n, 0);
        // Take constraints input
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            constraints.push_back({a, b, c});
        }
        int solutions = 0;
        do {
            bool valid = true;
            for (int i = 0; i < m && valid; i++) {
                auto constraint = constraints[i];
                auto distance = abs(teens[constraint.b] - teens[constraint.a]);
                c = constraint.c;
                valid = c > 0 ? distance <= c : distance >= -c;
            }
            if (valid)
                solutions++;
        } while (next_permutation(teens, teens + n));

        printf("%d\n", solutions);
    }
}
