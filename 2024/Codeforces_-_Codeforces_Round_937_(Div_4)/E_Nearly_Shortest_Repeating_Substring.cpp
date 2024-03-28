/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-03-28 22:46:39
 *
 * Problem: E. Nearly Shortest Repeating Substring
 * Contest: Codeforces - Codeforces Round 937 (Div. 4)
 * URL:     https://codeforces.com/contest/1950/problem/E
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
// #define LOCAL
const int N = 200010;
const int INF = 0x3f3f3f3f;

using namespace std;

int vis[N];

set<int> get(int x) {
    set<int> res;
    for (int i = 2; i * i <= x; i ++ ) {
        if (x % i == 0) {
            res.insert(i);
            res.insert(x / i);
        }
    }
    return res;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    map<char, int> mp;
    int c = 0;
    for (auto i : s) {
        mp[i] ++;
        c = max(c, mp[i]);
    }
    if (c >= n - 1) {
        cout << 1 << endl;
        return ;
    }
    if (!vis[n]) cout << n << endl;
    else {
        auto t = get(n);
        for (auto i : t) {
            map<string, int> T;
            for (int j = 0; j < n; j += i) {
                T[s.substr(j, i)] ++;
            }
            if (T.size() > 2) continue;
            auto s1 = (*T.begin()).fi;
            auto s2 = (*T.rbegin()).fi;
            if (s1 == s2) {
                cout << i << endl;
                return ;
            }
            int f1 = 0, f2 = 0;
            f2 += (T[s1] > 1);
            f2 += (T[s2] > 1);
            for (int j = 0; j < i; j ++) {
                if (s1[j] != s2[j]) f1 ++;
            }
            if (f1 >= 2 || f2 >= 2 )continue;
            cout << i << endl;
            return ;
        }
        cout << n << endl;
    }
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    for (int i = 2; i < N; i ++) {
        if (vis[i]) continue;
        for (int j = i + i; j < N; j += i) {
            vis[j] = 1;
        }
    }
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}