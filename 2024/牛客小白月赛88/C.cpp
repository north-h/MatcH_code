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

using namespace std;

void solve() {
    int n;
    cin >> n;
    set<PII> st;
    for (int i = 1; i <= n; i ++) {
        int h, m;
        cin >> h >> m;
        // debug2(h, m);
        int m1, m3, m5, h1 = h, h3 = h, h5 = h;
        m1 = m - 1;
        if (m1 < 0) {
            m1 += 60;
            h1 = h - 1;
            if (h1 < 0) h1 += 24;
        }
        // debug2(h1, m1);
        st.insert({h1, m1});
        m3 = m - 3;
        if (m3 < 0) {
            m3 += 60;
            h3 = h - 1;
            if (h3 < 0) h3 += 24;
        }
        // debug2(h3, m3);
        st.insert({h3, m3});
        m5 = m - 5;
        if (m5 < 0) {
            m5 += 60;
            h5 = h - 1;
            if (h5 < 0) h5 += 24;
        }
        // debug2(h5, m5);
        st.insert({h5, m5});
    }
    cout << st.size() << endl;
    for (auto [x, y] : st) cout << x << ' ' << y << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}