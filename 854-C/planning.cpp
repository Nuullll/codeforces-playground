/*
 * https://codeforces.com/problemset/problem/854/C
 * C. Planning
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define MOD 1000000007

template<class T>
ostream& operator << (ostream& os, const vector<T>& arr) {
    for (const auto& v : arr) {
        os << v << " ";
    }
    return os;
}

template<class T>
istream& operator >> (istream& os, vector<T>& arr) {
    for (auto& v : arr) {
        os >> v;
    }
    return os;
}

struct Node {
    ll val;
    int i;
};

/*
 * Solution goes here.
 */
pair<ll, vector<int>> planning(int n, int k, vector<Node>& cost) {
    sort(cost.begin(), cost.end(), [](auto const& a, auto const& b) {
        return a.val > b.val;
    });

    vector<int> plan(n, 0);
    unordered_set<int> arranged;

    int now = k + 1;
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        int orig = cost[i].i + 1;

        if (now < orig) {
            // departure @orig
            plan[cost[i].i] = orig;
            arranged.insert(orig);
        } else {
            // departure @now
            plan[cost[i].i] = now;
            total += cost[i].val * (now - orig);

            // find next unscheduled time
            while (arranged.find(++now) != arranged.end()) continue;
        }
    }

    return {total, plan};
}

/*
 * Driver.
 */
int main() {
    int n, k;
    cin >> n >> k;

    vector<Node> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i].val;
        cost[i].i = i;
    }

    auto r = planning(n, k, cost);
    cout << r.first << endl << r.second << endl;

    return 0;
}
