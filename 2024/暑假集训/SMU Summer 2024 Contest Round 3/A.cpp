// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int vis[N];

void solve() {
    // int n; cin >> n;
    while (cin >> n) {
        for (int i = n / 2; i >= 2; i --) {
            if (vis[i] && vis[n - i]) {
                cout << i << ' ' << n - i << '\n';
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    vis[0] = vis[1] = 1;
    for (int i = 2; i < N; i ++) {
        if (vis[i]) continue;
        for (int j = i + i; j < N; j += i) {
            vis[j] = 1;
        }
    }
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}