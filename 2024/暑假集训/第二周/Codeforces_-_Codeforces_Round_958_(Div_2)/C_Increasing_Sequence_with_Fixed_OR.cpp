/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-07-15 22:36:48
 *
 * Problem: C. Increasing Sequence with Fixed OR
 * Contest: Codeforces - Codeforces Round 958 (Div. 2)
 * URL:     https://codeforces.com/contest/1988/problem/C
 * MemoryL: 512 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int get(string s) {
    int res = 0;
    for (auto i : s) {
        if (i == '0') res = res * 2;
        else res = res * 2 + 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    string s;
    int x = n, c = 0;
    while (x) {
        s += (x % 2 + '0');
        c += (x % 2 == 1);
        x /= 2;
    }
    reverse(s.begin(), s.end());
    vector<int> ans;
    ans.push_back(n);
    // debug1(s);
    if (c == 1) {
        cout << 1 << '\n';
        cout << n << '\n';
        return ;
    }
    string str;
    for (int i = s.size() - 1; i >= 1; i --) {
        if (s[i] == '1') {
            str = s;
            str[i] = '0';
            ans.push_back(get(str));
        }
    }
    s[0] = '0';
    ans.push_back(get(s));
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}