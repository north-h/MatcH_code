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
    vector<set<int>> g(n + 1);
    vector<PII> a(n + 1);
    map<int, vector<int>> mp;
    // vector<set<int>> st(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    mp[0].push_back(1);
    sort(a.begin() + 1, a.end());
    for (int i = 2; i <= n; i ++) {
        if (mp[a[i].fi - 1].empty()) {
            cout << -1 << endl;
            return ;
        } else {
            g[a[i].se].insert(mp[a[i].fi - 1].back());
            g[mp[a[i].fi - 1].back()].insert(a[i].se);
            mp[a[i].fi].push_back(a[i].se);
            m --;
        }
    }
    set<PII> s;
    if (m > 0) {
        for (int i = 2; i <= n; i ++) {
            for (auto j : mp[a[i].fi]) {
                if (a[i].se == j || g[a[i].se].count(j)) continue;
                g[a[i].se].insert(j);
                g[j].insert(a[i].se);
                m --;
                if (m == 0) {
                    for (int i = 1; i <= n; i ++) {
                        for (auto j : g[i]) {
                            if (s.count({i, j}) || s.count({j, i})) continue;
                            cout << i << ' ' << j << endl;
                            s.insert({i,j});
                        }
                    }
                    return ;
                }
            }
            for (auto j : mp[a[i].fi - 1]) {
                if (g[a[i].se].count(j)) continue;
                g[a[i].se].insert(j);
                g[j].insert(a[i].se);
                m --;
                if (m == 0) {
                    for (int i = 1; i <= n; i ++) {
                        for (auto j : g[i]) {
                            if (s.count({i, j}) || s.count({j, i})) continue;
                            cout << i << ' ' << j << endl;
                            s.insert({i,j});
                        }
                    }
                    return ;
                }
            }
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}

