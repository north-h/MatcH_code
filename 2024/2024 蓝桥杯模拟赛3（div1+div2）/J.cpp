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
const int mod = 1e9 + 7;


using namespace std;

void solve() {
    int n;
    cin >> n;
    n --;
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans += (n - i + 1) * (n - i + 1);
        ans %= mod;
    }
    for (int i = 1; i <= n; i ++) {
        ans += (n - i + 1) * (n - i + 1) * (i - 1);
        ans %= mod;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}