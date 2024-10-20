/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-19 13:35:39
 *
 * Problem: G. Be Positive
 * Contest: Codeforces - SMU Autumn 2024 Team Round 8
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/559336/problem/G
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    for (int i = 1; i <= 11; i ++) {
        vector<int> a;
        bool ok = false;
        for (int j = 1; j <= i; j ++) a.push_back(j - 1);
        do {
            int ans = 0;
            // for (auto i : a) cout << i << ' ';
            // cout << '\n';
            bool f = false;
            for (auto k : a) {
                ans ^= k;
                if (ans == 0) f = true;
            }
            if (ans > 0 && !f) {
                for (auto k : a) cout << k << ' ';
                cout << '\n';
                ok = true;
                break;
            }
        } while (next_permutation(a.begin(), a.end()));
        if (!ok) cout << "NO\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}