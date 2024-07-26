
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
    int n; cin >> n;
    vector<array<int, 2>> seg, t;
    for (int i = 0; i < n; i ++) {
        int l, r; cin >> l >> r;
        seg.push_back({l, r});
    }
    t = seg;
    map<int, int> mp;
    sort(seg.begin(), seg.end(), [&](array<int, 2> a, array<int, 2> b) {
        return a[1] - a[0] < b[1] - b[0];
    });
    map<array<int, 2>, int> ans;
    for (auto [l, r] : seg) {
        for (int i = l; i <= r; i ++) {
            if (!mp.count(i)) {
                mp[i] ++;
                ans[ {l, r}] = i;
                break;
            }
        }
    }
    for (auto [l, r] : t) {
        cout << l << ' ' << r << ' ';
        cout << ans[ {l, r}] << '\n';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}