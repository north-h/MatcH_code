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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), d(m + 1), f(k + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= m; i ++) cin >> d[i];
    for (int i = 1; i <= k; i ++) cin >> f[i];
    int p = -1, c = 0;
    set<int> st;
    map<int, int> mp;
    for (int i = 1; i < n; i ++) {
        if (a[i + 1] - a[i] > c) {
            c = a[i + 1] - a[i];
            p = i;
        }
        st.insert(a[i + 1] - a[i]);
        mp[a[i + 1] - a[i]] ++;
    }
    if (mp[c] > 1) {
        cout << c << endl;
        return ;
    }
    mp[c] --;
    if (mp[c] == 0) st.erase(c);
    sort(d.begin() + 1, d.end());
    sort(f.begin() + 1, f.end());
    int ans = LLONG_MAX;
    int g = (a[p] + a[p + 1]) / 2;
    for (int i = 1; i <= m; i ++) {
        int l = 1, r = k, res = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            int x = d[i] + f[mid];
            if (x >= g) r = mid - 1, res = mid;
            else l = mid + 1;
        }
        if (res != -1) {
            int y = d[i] + f[res];
            if (y <= a[p + 1] && y >= a[p]) {
                ans = min(ans, max(y - a[p], a[p + 1] - y));
            }
            if (res != 1) {
                int z = d[i] + f[res - 1];
                if (z <= a[p + 1] && z >= a[p]) {
                    ans = min(ans, max(z - a[p], a[p + 1] - z));
                }
            }
        } else {
            int y = d[i] + f[k];
            if (y <= a[p + 1] && y >= a[p]) {
                ans = min(ans, max(y - a[p], a[p + 1] - y));
            }
        }
    }
    if (ans == LLONG_MAX) ans = c;
    st.insert(ans);
    cout << *st.rbegin() << endl;
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