/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-11-01 15:40:38
 *
 * Problem: J. New Energy Vehicle
 * Contest: Codeforces - SMU Autumn 2024 Team Round 10
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/562089/problem/J
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), vis(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    map<int, vector<int>> mp;
    vector<array<int, 2>> v(m + 1);
    for (int i = 1; i <= m; i ++) {
        int x, y; cin >> x >> y;
        mp[y].push_back(x);
        v[i] = {x, y};
    }
    for (auto &[x, y] : mp) reverse(y.begin(), y.end());
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>>pq;
    for (auto &[x, y] : mp) {
        // cout << x << ":";
        // for (auto i : mp[x]) cout << i << ' ';
        // cout << '\n';
        pq.push({y.back(), a[x], x});
        y.pop_back();
        vis[x] = 1;
    }
    for (int i = 1; i <= n; i ++) {
        if (!mp.count(i)) {
            pq.push({INF, a[i], i});
            vis[i] = 1;
        }
    }
    // debug1(pq.size());
    int ans = 0;
    for (int i = 1; i <= m; i ++) {
        while (pq.size() && ans + pq.top()[1] < v[i][0]) {
            // debug1(pq.top()[1]);
            ans += pq.top()[1];
            pq.pop();
        }
        debug2(ans, v[i][0]);
        if (ans >= v[i][0]) {
            if (pq.size() && pq.top()[2] == v[i][1]) pq.pop();
            if (!mp[v[i][1]].size()) pq.push({INF, a[v[i][1]], v[i][1]});
            else {
                pq.push({mp[v[i][1]].back(), a[v[i][1]], v[i][1]});
                mp[v[i][1]].pop_back();
            }
        } else if (pq.size()) {
            auto [dis, dl, id] = pq.top();
            // debug2(dis, dl);
            pq.pop();
            if (id != v[i][1]) pq.push({dis, ans + dl - v[i][0]});
            ans = v[i][0];
            if (!mp[v[i][1]].size()) pq.push({INF, a[v[i][1]], v[i][1]});
            else {
                pq.push({mp[v[i][1]].back(), a[v[i][1]], v[i][1]});
                mp[v[i][1]].pop_back();
            }
        } else break;
    }
    debug2(ans, pq.size());
    while (pq.size()) {
        debug1(pq.top()[1]);
        ans += pq.top()[1];
        pq.pop();
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}

