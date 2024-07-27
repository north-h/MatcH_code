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
    int n, X; cin >> n >> X;
    vector<vector<int>> L(n + 1);
    for (int i = 1; i <= n; i ++) {
        int K; cin >> K;
        while (K --) {
            int x; cin >> x;
            L[i].push_back(x);
        }
    }
    auto dfs = [&](auto &&dfs, int u, int x) -> int {
        int sum = 0;
        if (x > X) return 0;
        if (u > n) {
            if (x == X) return 1;
            return 0;
        } 
        for (auto i : L[u]) {
            sum += dfs(dfs, u + 1, x * i);
        }
        return sum;
    };
    cout << dfs(dfs, 1, 1) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}