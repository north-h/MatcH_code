/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-03-19 00:45:42
 *
 * Problem: P1879 [USACO06NOV] Corn Fields G
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P1879
 * MemoryL: 125 MB
 * TimeL:   1000 ms
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
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;
const int mod = 1e8;
#define int long long
using namespace std;
multiset<int>st;
int n;
int a[1005];
int s[1005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    st.insert(-1e18);
    st.insert(1e18);
    int ans = LLONG_MAX;
    for (int l = 1; l <= n; l++) {
        for (int i = 1; i < l; i++) {
            st.insert(s[l - 1] - s[i - 1]);
        }

        for (int r = l; r <= n; r++) {
            int dq = s[r] - s[l - 1];
            auto nl = st.lower_bound(dq);
            auto pl = prev(nl);
            ans = min({ans, abs(dq - *nl), abs(dq - *pl)});
        }
    }
    reverse(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    st.clear();
    st.insert(-1e18);
    st.insert(1e18);
    for (int l = 1; l <= n; l++) {
        for (int i = 1; i < l; i++) {
            st.insert(s[l - 1] - s[i - 1]);
        }
        for (int r = l; r <= n; r++) {
            int dq = s[r] - s[l - 1];
            auto nl = st.lower_bound(dq);
            auto pl = prev(nl);
            ans = min({ans, abs(dq - *nl), abs(dq - *pl)});
        }
    }
    cout << ans << endl;
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