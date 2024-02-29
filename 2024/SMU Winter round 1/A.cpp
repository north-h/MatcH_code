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
    int n, m;
    cin >> n >> m;
    ll sum = 0;
    vector <int> a( n * m + 1);
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    int x;
    if (n & 1) x = (n + 1) / 2;
    else x = n / 2;
    int y = n - x + 1;
    // debug2(x, y);
    for (int i = n * m - y + 1, j = 1; j <= m; i -= y, j++) {
        // debug2(i, a[i]);
        sum += a[i];
    }
    cout << sum << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}