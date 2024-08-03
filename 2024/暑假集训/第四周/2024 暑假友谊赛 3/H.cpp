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
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n) {
        cout << -1 << '\n';
        return ;
    }
    vector<array<int, 3>> ans;
    for (int i = 2; i <= n; i ++) {
        int y = (i - a[i] % i + i) % i;
        ans.push_back({1, i, y});
        a[i] += y;
        a[1] -= y;
        ans.push_back({i, 1, a[i] / i});
        a[1] += a[i];
        a[i] = 0;
    }
    int x = sum / n;
    for (int i = 2; i <= n; i ++) {
        ans.push_back({1, i, x});
        a[i] = x;
        a[1] -= x;
    }
    cout << ans.size() << '\n';
    for (auto [x, y, z] : ans) cout << x << ' ' << y << ' ' << z << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}