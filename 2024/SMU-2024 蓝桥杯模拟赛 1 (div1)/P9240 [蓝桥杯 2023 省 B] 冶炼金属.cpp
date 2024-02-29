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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<PII> a(n + 1);
    int ans1 = INF, ans2 = 0;
    for (int i = 0; i < n; i++) {
        // cin >> a[i].fi >> a[i].se;
        int x, y;
        cin >> x >> y;
        ans1 = min(ans1, x / y);
        ans2 = max(ans2, x / (y + 1) + 1);
    }
    cout << ans2 << ' ' << ans1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}