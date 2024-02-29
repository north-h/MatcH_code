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
    int n, m, k;
    cin >> n >> m >> k;
    if (k == 1) cout << n * m << endl;
    else if (n == 1) {
        int nj = 1, nk = 1, nkj = 1;
        for (int i = 1; i <= n; i ++) nj *= i;
        for (int i = 1; i <= k; i ++) nk *= i;
        for (int i = 1; i <= n - k; i ++) nkj *= i;
        cout << nj / (nk * nkj) << endl;
    } else cout << "NO" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}