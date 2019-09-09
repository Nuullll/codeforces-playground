/*
 * https://codeforces.com/problemset/problem/496/C
 * C. Removing Columns
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
int removingColumns(int n, int m, vector<string>& table) {
    // corner cases
    if (n == 1) return 0;

    vector<bool> sorted(n, false);

    int count = 0;
    for (int j = 0; j < m; ++j) {
        char c = table[0][j];
        vector<bool> tmp = sorted;
        bool remove = false;

        for (int i = 1; i < n; c = table[i][j], ++i) {
            if (tmp[i] || table[i][j] == c) continue;

            if (table[i][j] > c) {
                tmp[i] = true;
                continue;
            }

            // deletion needed
            remove = true;
            break;
        }

        if (remove) ++count;
        else sorted = tmp;
    }

    return count;
}

/*
 * Driver.
 */
int main() {
    int n, m;
    cin >> n >> m;

    vector<string> table(n);
    cin >> table;

    cout << removingColumns(n, m, table) << endl;

    return 0;
}
