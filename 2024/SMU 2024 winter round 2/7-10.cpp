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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(m + 1,INF));
    for (int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
        g[b][a] = g[a][b];
    }
    int k;
    cin >> k;
    int sum = 0, ans = INF, res = 0;
    for (int i = 1; i <= k; i ++) {
        int cnt;
        cin >> cnt;
        vector<int> road(cnt + 2);
        map<int,int> mp;
        for (int j = 1; j <= cnt; j ++) {
            cin >> road[j];
            mp[road[j]] ++;
        }
        if ((int)mp.size() != n || cnt != n) continue;
        // debug1(i);
        road[0] = 0;
        road[cnt + 1] = 0;
        int t = 0;
        bool ok = true;
        for (int j = 1; j <= cnt + 1; j ++) {
            if (g[road[j - 1]][road[j]] == INF) ok = false; 
            t += g[road[j - 1]][road[j]];
        }
        if (!ok) continue;
        // debug1(i);
        sum ++;
        if (t < ans) {
            ans = t;
            res = i;
        }
    }
    cout << sum << endl;
    cout << res << ' ' << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}