/*
 * https://codeforces.com/problemset/problem/1217/C
 * C. The Number Of Good Substrings
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
int log2(int x) {
    if (x <= 1) return 0;

    return 1 + log2(x>>1);
}

int numberOfGoodSubstrings(string& s) {
    int n = s.size();

    if (n == 1 && s[0] == '0') return 0;

    vector<int> contZeros(n+1);

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') ++count;
        else count = 0;

        contZeros[i+1] = count;
    }

    // consider the number of good substrings end at index i
    int res = s[0] == '1' ? 1 : 0;
    for (int i = 1; i < n; ++i) {
        int max_len = i + 1;
        int left_flag = max(0, i - log2(max_len));

        int j = i;
        int x = 0;
        while (j >= left_flag) {
            if (s[j] == '1') {
                x += 1<<(i-j);
                if (x > max_len) break;
                if (contZeros[j] >= x-(i-j+1)) ++res;
            }

            j -= contZeros[j] + 1;
        }
    }

    return res;
}

/*
 * Driver.
 */
int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;

        cout << numberOfGoodSubstrings(s) << endl;
    }

    return 0;
}
