/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-03-30 22:36:09
 *
 * Problem: B. Bessie and MEX
 * Contest: Codeforces - CodeTON Round 8 (Div. 1 + Div. 2, Rated, Prizes!)
 * URL:     https://codeforces.com/contest/1942/problem/B
 * MemoryL: 256 MB
 * TimeL:   1500 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int mex = 0;
    set<int> st;
    for (int i = 1; i <= n; i ++) {
        if (a[i] < 0) {
            cout << mex + abs(a[i]) << ' ';
            st.insert(mex + abs(a[i]));
        }
        else {
            mex ++;
            while (st.count(mex)) mex ++;
            cout << mex - a[i] << ' ';
            st.insert(mex - a[i]);
        }
    }
    cout << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}