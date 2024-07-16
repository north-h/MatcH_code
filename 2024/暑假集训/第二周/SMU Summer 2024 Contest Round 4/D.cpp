// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

vector<int> vis(N + 1), prime;

void solve() {
    int n; cin >> n;
    // for (int i = 2; i <= N; i ++) {
    //     if (!vis[i]) prime.push_back(i);
    //     for (auto j : prime) {
    //         if (i * j > N) break;
    //         vis[i * j] = 1;
    //         if (i % j == 0) break;
    //     }
    // }
    // int ans = 0;
    // for (int i = 1; i <= n; i ++) {
    //     int fi = 1;
    //     int x = i;
    //     for (auto j : prime) {
    //         if (j > sqrt(x)) break;
    //         int cnt = 0;
    //         while (x % j == 0) x /= j, cnt ++;
    //         fi *= (cnt + 1);
    //     }
    //     if (x > 1) fi *= 2;
    //     ans += fi * i;
    // }
    // cout << ans << '\n';
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        for (int j = i; j <= n; j += i ) {
            f[j] ++ ;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i ++ ) res += f[i] * i;
    cout << res;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}