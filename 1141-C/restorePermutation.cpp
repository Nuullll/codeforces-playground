/*
 * https://codeforces.com/problemset/problem/1141/C
 * C. Polycarp Restores Permutation
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

/*
 * Solution goes here.
 */
vector<int> restorePermutation(int n, vector<int>& diff) {
    unordered_set<int> mem {0};

    int val = 0, min_v = 0, max_v = 0;
    for (auto& v : diff) {
        val += v;
        auto r = mem.insert(val);
        if (!r.second) return {-1};

        min_v = min(min_v, val);
        max_v = max(max_v, val);

        if (max_v - min_v > n - 1) return {-1};
    }

    val = 1 - min_v;
    vector<int> res {val};
    for (auto& v : diff) {
        val += v;
        res.push_back(val);
    }

    return res;
}

/*
 * Driver.
 */
int main() {
    int n;
    cin >> n;

    vector<int> diff(n-1);
    cin >> diff;

    cout << restorePermutation(n, diff) << endl;

    return 0;
}
