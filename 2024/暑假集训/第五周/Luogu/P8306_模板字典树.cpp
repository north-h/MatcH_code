/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-08-08 14:22:18 ms
 *
 * Problem: P8306 【模板】字典树
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8306
 * MemoryL: 1 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 3000010;
const int INF = 0x3f3f3f3f;

using namespace std;

int tr[N][65], cnt[N];
int n, m, idx;
map<char, int> mp;

void insert(string s) {
    int p = 0;
    for (auto i : s) {
        int u = mp[i];
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
        cnt[p] ++;
    }
}

int query(string s) {
    int p = 0;
    for (auto i : s) {
        int u = mp[i];
        if (!tr[p][u]) return 0;
        p = tr[p][u];
    }
    return cnt[p];
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i <= idx; i ++) {
        for (int j = 0; j < 65; j ++) {
            tr[i][j] = 0;
        }
        cnt[i] = 0;
    }
    idx = 0;
    for (int i = 1; i <= n; i ++) {
        string ss; cin >> ss;
        // debug1(ss);
        insert(ss);
    }
    while (m --) {
        string ss; cin >> ss;
        // debug1(ss);
        cout << query(ss) << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    int id = 0;
    for (auto i = 'A'; i <= 'Z'; i ++) mp[i] = id ++;
    for (auto i = 'a'; i <= 'z'; i ++) mp[i] = id ++;
    for (auto i = '0'; i <= '9'; i ++) mp[i] = id ++;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}