// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
int cnt = 0;

void solve() {
    cnt ++;
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
    }
    int ans = abs(a[1] - b[1]) + abs(a[n] - b[n]), t;
    int r1, r2, r3, r4;
    r1 = r2 = r3 = r4 = INF;
    for (int i = 1; i <= n; i ++) r1 = min(r1, abs(a[1] - b[i])), r2 = min(r2, abs(a[n] - b[i]));
    for (int i = 1; i <= n; i ++) r3 = min(r3, abs(b[1] - a[i])), r4 = min(r4, abs(b[n] - a[i]));
    ans = min(ans, r1 + r2 + r3 + r4);
    ans = min(ans, abs(a[1] - b[1]) + r2 + r4);
    ans = min(ans, abs(a[n] - b[n]) + r1 + r3);
    ans = min(ans, abs(a[1] - b[n]) + abs(a[n] - b[1]));
    ans = min(ans, abs(a[1] - b[n]) + r2 + r3);
    ans = min(ans, abs(a[n] - b[1]) + r1 + r4);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}