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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            res += a[i][j];
        }
    }
    if(k >= m || k >= n) {
        cout << res << endl;
        return ;
    }
    ll ans = 0;
    for (int op = 0; op < (1 << n); op++) {
        b = a;
        int sum = __builtin_popcount(op);
        ll s = 0;
        if(sum > k)continue;
        // debug1(sum);
        for (int i = 0; i < n; i++){
            if((op >> i) & 1) {
                for (int j = 0; j < m; j++) {
                    s += b[i][j];
                    b[i][j] = 0;
                }
            }
        }
        vector<int> t;
        for (int i = 0; i < m; i++) {
            int re = 0;
            for (int j = 0; j < n; j++) {
                re += b[j][i];
            }
            t.push_back(re);
        }
        sort(t.begin(), t.end(), greater <int>());
        for (int i = 0; i < k - sum; i++){
            s += t[i];
        }
        ans = max(ans, s);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}