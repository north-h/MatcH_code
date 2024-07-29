// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    int ans = 0;
    vector<int> ws;
    int mx = 0;
    for (int i = 0; i < 32; i ++) {
        if (n >> i & 1) ws.push_back(1), mx = max(i, mx);
        else ws.push_back(0);
    }
    for (int i = 0; i <= mx; i ++) ws[i] ^= 1;
    bool ok = false;
    for (auto i : ws) {
        if (i == 1) ans = ans * 2 + 1, ok = true;
        else if (ok) ans = ans * 2;
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