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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> jzt(1010);
    int t = 0;
    for (int i = 1; i <= n; i ++) {
        int cz = INF, gd = 0, id = -1;
        for (int j = 0; j < t; j ++) {
            if (jzt[j].back() <= a[i]) continue;
            int x = jzt[j].back() - a[i];
            if (x > cz) continue;
            else {
                if (x == cz) {
                    int y = (int)jzt[j].size();
                    if (y >= gd) {
                        cz = x;
                        gd = (int)jzt[j].size();
                        id = j;
                    }
                } else {
                    cz = x;
                    gd = jzt[j].size();
                    id = j;
                }
            } 
        }
        if (id == -1) jzt[t ++].push_back(a[i]);
        else jzt[id].push_back(a[i]);
    }
    int ans = 0;
    for (int i = 0; i < t; i ++) {
        ans = max(ans, (int)jzt[i].size());
    }
    cout << ans << ' ' << t << endl;
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