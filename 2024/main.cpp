// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 10000010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int r4 = 0, r3 = 0;
    map<int, int> mp;
    for (int i = 1,j = 1; i <= n; i ++) {
        mp[a[i]] ++;
        while (mp.size() > 3 && j <= i) {
            j ++;
            mp[a[j]] --;
            if (mp[a[j]] == 0) mp.erase(a[j]);
        }
        if (mp.size() >= 3) r3 += j;
    }
    mp.clear();
    for (int i = 1, j = 1; i <= n; i ++) {
        mp[a[i]] ++;
        while (mp.size() > 4 && j <= i) {
            j ++;
            mp[a[j]] --;
            if (mp[a[j]] == 0) mp.erase(a[j]);
        }
        if (mp.size() >= 4) r3 += j;
    }
    // debug2(r2, r3);
    cout << r3 - r4 << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}