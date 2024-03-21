// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 200010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int ans = 0;
    unordered_map<int,int> up;
    int i, j;
    for (i = 1, j = 1; i <= n; i ++) {
        up[a[i]] ++;
        if (up.size() < 3) continue;
        while (up.size() > 3 && j <= i) {
            up[a[j]] --;
            if (up[a[j]] == 0) up.erase(a[j]);
            j ++;
        }
        ans ++;
    }
    while (up.size() == 3 && j <= n) {
        ans ++;
        up[a[j]] --;
        if (up[a[j]] == 0) up.erase(a[j]);
        j --;
    }
    cout << ans << endl;
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