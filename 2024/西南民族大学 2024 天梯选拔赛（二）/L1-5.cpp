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
    vector<PII> red(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> red[i].fi >> red[i].se;
    }
    if (m == 0) {
        cout << 0 << endl;
        return ;
    }
    int sum = 0;
    for (int i = 2; i <= n; i ++) {
        sum += abs(red[i].fi - red[i - 1].fi) + abs(red[i].se - red[i - 1].se);
    }
    int x = (15 - m) * 2 + 1;
    cout << (sum + x - 1) / x << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}