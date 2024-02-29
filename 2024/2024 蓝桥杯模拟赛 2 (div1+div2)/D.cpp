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
    int  n, m;
    cin >> n >> m;
    vector<int> dg(n + 1), a(m + 1), b(m + 1);
    for (int i = 1; i <= m; i ++) {
        cin >> a[i] >> b[i];
        dg[a[i]] ++;
        dg[b[i]] ++;
    }
    int ans = 0;
    for (int i = 1; i <= m; i ++) {
        ans += (dg[a[i]] - 1) * (dg[b[i]] - 1);
    }
    cout << (ans << 1) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}