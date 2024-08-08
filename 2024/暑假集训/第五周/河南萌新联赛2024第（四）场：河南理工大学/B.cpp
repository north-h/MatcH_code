// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int tr[N][2], vis[N][2];
int n, m, idx;

void insert(int x) {
    int p = 0;
    for (int i = m - 1; i >= 0; i --) {
        int u = (x >> i & 1);
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
}

int queyr(int x) {
    int p = 0, res = 0;
    for (int i = m - 1; i >= 0; i --) {
        int u = (x >> i & 1);
        if (tr[p][u]) res = res * 2 + 1, p = tr[p][u];
        else res = res * 2, p = tr[p][u ^ 1];
    }
    return res;
}

void solve() {
    cin >> n >> m;
    int ans = 0;
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        ans = max(ans, queyr(x));
        insert(x);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}