/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-11-15 20:54:37
 *
 * Problem: C. Penchick and BBQ Buns
 * Contest: Codeforces - Codeforces Round 987 (Div. 2)
 * URL:     https://codeforces.com/contest/2031/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;


bool solve(int n) {
    // for (int i = 0; i <= 10; i ++) cout << js[i] << ' ';
    // cout << '\n';
    // int n; cin >> n;
    // if (n == 3 || n == 5 || n == 7) {
    //     cout << -1 << '\n';
    //     return ;
    // }
    int idx = 1;
    vector<int> ans(n + 1, -1);
    if (n & 1) {
        int p = n;
        while ((p - 1) % 4) p --;
        // debug1(p);
        for (int i = p; i >= 2; i -= 4) {
            // debug1(i);
            ans[i] = 1;
            ans[i - 1] = 2;
            ans[i - 2] = 3;
            ans[i - 3] = 4;
        }
        idx = 5;
        for (int i = p + 1; i <= n; i += 2) {
            ans[i] = ans[i + 1] = idx;
            idx ++;
        }
        ans[1] = ans[p];
    } else {
        for (int i = 1; i <= n; i += 2) {
            ans[i] = ans[i + 1] = idx;
            idx ++;
        }
    }
    // for (int i = 1; i <= n; i ++) cout << ans[i] << ' ';
    // cout << '\n';
    map<int, vector<int>> mp;
    set<int> st;
    for (int i = 1; i * i <= 2000000; i ++) st.insert(i * i);
    for (int i = 1; i < ans.size(); i ++) {
        mp[ans[i]].push_back(i);
    }
    for (auto [x, y] : mp) {
        if (y.size() < 2) return false;
        for (int i = 1; i < y.size(); i ++) {
            if (!st.count(abs(y[i] - y[i - 1]))) return false;
        }
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    // while (h_h--)solve();
    for (int i = 8; i <= 200000; i ++) {
        if (solve(i)) cout << "AC\n";
        else {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}