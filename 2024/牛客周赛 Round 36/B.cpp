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
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    int c = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            c += g[i][j];
        }
    }
    set<int> st;
    for (int i = 1; i <= n; i ++) {
        int v = 0;
        for (int j = 1; j <= m; j ++) {
            v ^= g[i][j];
        }
        st.insert(v);
    }
    for (int i = 1; i <= m; i ++) {
        int v = 0;
        for (int j = 1; j <= n; j ++) {
            v ^= g[j][i];
        }
        st.insert(v);
    }
    if (st.size() == 1 && c == x) cout << "accepted" << endl;
    else cout << "wrong answer" << endl;
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