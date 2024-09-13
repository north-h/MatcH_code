#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto &i : a) cin >> i;
    vi l(n), r(n);
    for (auto &i : l) cin >> i;
    for (auto &i : r) cin >> i;

    vi f(n);
    f[0] = 1;
    for (int i = 1; i < n; i++) {
        if (l[i] == r[i]) f[i] = a[i] + 1;
        else f[i] = max(f[i - 1] + a[i] + 1 - abs(l[i] - r[i]), a[i] + 1 + abs(l[i] - r[i]));
    }
    cout << ranges::max(f) << "\n";
}

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}