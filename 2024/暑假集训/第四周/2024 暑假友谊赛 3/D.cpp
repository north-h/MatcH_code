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
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1, x; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int i = 1; i < n; i ++) {
        if (a[i] != i) continue;
        int as = mp[a[i]], bs = mp[a[i + 1]];
        swap(a[as], a[bs]);
        swap(mp[a[i]], mp[a[i + 1]]);
        ans ++;
    }
    if (a[n] == n) {
        int as = mp[a[n]], bs = mp[a[n - 1]];
        swap(a[as], a[bs]);
        swap(mp[a[n]], mp[a[n - 1]]);
        ans ++;
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