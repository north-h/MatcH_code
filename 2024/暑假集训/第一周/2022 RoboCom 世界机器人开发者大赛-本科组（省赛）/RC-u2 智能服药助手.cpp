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
    int n, m; cin >> n >> m;
    vector<int> T(n + 1), last(n + 1, -INF);
    for (int i = 1; i <= n; i ++) cin >> T[i];
    while (m --) {
        int t, k; cin >> t >> k;
        for (int i = 1, x; i <= k; i ++) {
            cin >> x;
            if (T[x] == -1) continue;
            if (abs(t - last[x]) < T[x]) {
                cout << "Don't take " <<  x << " at " << t << "!" << '\n';
            } else {
                last[x] = t;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}