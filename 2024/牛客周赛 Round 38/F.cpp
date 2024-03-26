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

template<class T>
struct ST {
    T n;
    vector<vector<T>> f, g;
    vector<int> lg2;
    ST(const vector<T> &a) {
        n = (int)a.size();
        lg2.resize(n + 1);
        lg2[0] = -1;
        for(int i = 1; i <= n; i ++) {
            lg2[i] = lg2[i >> 1] + 1;
        }
        f.resize(n + 1, vector<T>(lg2[n] + 1));
        g.resize(n + 1, vector<T>(lg2[n] + 1));
        for (int i = 1; i <= n; i++) {
            f[i][0] = a[i];
            g[i][0] = a[i];
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
                g[i][j] = min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query_max(int l, int r) {
        int k = lg2[r - l + 1];
        return max(f[l][k], f[r - (1 << k) + 1][k]);
    }

    T query_min(int l, int r) {
        int k = lg2[r - l + 1];
        return min(g[l][k], g[r - (1 << k) + 1][k]);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    map<int, int> lst;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        if (lst.count(x)) {
            b[i] = lst[x];
        }
        lst[x] = i;
    }
    for (int i = n; i >= 1; i --) {
        if (b[i] == i - 1) b[i] = b[i - 1];
    }
    ST<int> st(b);
    while (m --) {
        int l, r;
        cin >> l >> r;
        if (st.query_max(l, r) >= l) cout << "YES\n";
        else cout << "NO\n";
    }
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