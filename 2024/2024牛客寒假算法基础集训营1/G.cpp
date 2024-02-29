// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<PII> a(n + 1);
    vector<int> s(n + 1);
    for (int i = 1; i <=n; i ++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <=n; i ++) {
        a[i].se += a[i - 1].se;
    }
    int ans = m;
    for (int i = 1; i <=n; i ++) {
        if (a[i].se < a[i].fi) {
            if (a[i].se + m == a[i].fi) ans = max(ans, a[i].fi);
        } else {
            ans = max(ans, a[i].se + m);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}