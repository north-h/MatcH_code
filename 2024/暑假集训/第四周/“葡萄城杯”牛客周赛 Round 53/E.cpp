// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 1000010;
const int INF = 0x3f3f3f3f;

using namespace std;


void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    vector<vector<int>> ve(n + 1);
    for (int i = 1; i <= n; i ++) {
        int x = a[i];
        while (x) {
            if (x >= n) {
                x >>= 1;
                continue;
            }
            ve[x].push_back(a[i]);
            x >>= 1;
        }
        ve[0].push_back(a[i]);
    }
    auto check = [&](int x) -> bool {
        auto vis = mp;
        for (int i = x; i >= 0; i --) {
            bool ok = false;
            for (auto j : ve[i]) {
                if (vis[j]) {
                    vis[j] --;
                    ok = true;
                    break;
                }
            }
            if (!ok) return false;
        }
        return true;
    };
    int l = 0, r = n, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans + 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}