// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    string s; cin >> s;
    int X = 0, Y = 0;
    map<pair<int, int>, int> mp;
    if (x == 0 && y == 0) {
        cout << n * (n + 1) / 2 << '\n';
        return ;
    }
    int ans = 0;
    mp[ {0, 0}] ++;
    // debug1(n);
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'A') X --;
        else if (s[i] == 'D') X ++;
        else if (s[i] == 'W') Y ++;
        else Y --;
        int dx = X - x, dy = Y - y;
        ans += mp[ {dx, dy}] * (n - i);
        mp[ {dx, dy}] = 0;
        mp[ {X, Y}] ++;
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