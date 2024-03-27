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
    int n, x;
    cin >> n >> x;
    x ++;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) cin >> a[i];
    int ans = -1;
    for (int i = 30; i >= 0; i --) {
        vector<int> t;
        bool ok = false;
        for (int j = 0; j < a.size(); j ++) {
            if (!ok) t.push_back(a[j]);
            else t.back() ^= a[j];
            // debug2((a[j] >> i & 1), ok);
            if (a[j] >> i & 1) ok = !ok;
            // debug2((a[j] >> i & 1), ok);
        }
        // debug2(i, (int)t.size());
        // for (auto j : t) cout << j << ' ';
        // cout << endl;
        // debug1(ok);
        if (x >> i & 1) {
            if (!ok) ans = max(ans, (int)t.size());
        } else {
            if (ok) {
                cout << ans << endl;
                return ;
            }
            a = t;
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