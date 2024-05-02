// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    map<char, ll> mp;
    for (auto i : b) mp[i] ++;
    ll c1 = 0, c0 = 0;
    ll ans = 0;
    for (int i = 0; i < a.size(); i ++) {
        if (a[i] == '0') c0 ++;
        else c1 ++;
        if (c1 <= mp['1'] && c0 <= mp['0']) ans = i + 1;
    }
    cout << n << '\n';
    // int n; cin >> n;
    // vector<int> a(n - 1);
    // for (auto &i : a) cin >> i;
    // cout << a[0] + 1 << ' ';
    // int lst = a[0] + 1;
    // for (int i = 0; i < n - 1; i ++) {
    //     if (i == n - 2) cout << lst + a[i] << ' ';
    //     else {
    //         // if (a[i] < lst) {
    //         //     cout << a[i] << ' ';
    //         //     lst = a[i];
    //         // } else {
    //         // debug2(lst, a[i]);
    //         if (lst > a[i + 1]) {
    //             lst += a[i];
    //             cout << lst << ' ';
    //         } else {
    //             lst = lst + ((a[i + 1] - lst) / a[i] + 1) * a[i];
    //             cout << lst << ' ';
    //         }
    //         // }
    //     }
    // }
    // cout << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}