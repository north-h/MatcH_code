#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 5e5 + 5;
const ll INF = 1e14;
struct node {
    ll col, u, v, w;
};
struct ds {
    ll id, time, dist;
};
bool operator < (ds xx, ds yy) {
    if (xx.time == yy.time) return xx.dist > yy.dist;
    return xx.time > yy.time;
}
struct ST {
    vector<vector<ll>> f;
    ll len;
    void init(vector<pair<ll, ll>> &a) {
        f.resize(len + 5, vector<ll>(22, 0));
        for (int i = 1; i <= len; i ++) {
            f[i][0] = a[i].second;
        }
        for (int j = 1; j <= 20; j ++) {
            for (int i = 1; i + (1 << j) - 1 <= len; i ++) {
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    ll query(ll l, ll r) {
        ll k = log2(r - l + 1);
        return max(f[l][k], f[r - (1 << k) + 1][k]);
    }
} xm[MAXN];
ll Tex, n, m, k;
bool flag[MAXN];
ll tis[MAXN];
ll dis[MAXN];
vector<node> mp[MAXN];
vector<pair<ll, ll>> cp[MAXN];
void dijkstra() {
    priority_queue<ds> op;
    op.push({1, 0, 0});
    tis[1] = 0;
    dis[1] = 0;
    while (!op.empty()) {
        ds qwq = op.top();
        op.pop();
        if (flag[qwq.id]) continue;
        flag[qwq.id] = 1;
        for (auto it : mp[qwq.id]) {
            if (flag[it.v]) continue;
            ll idx = lower_bound(cp[it.col].begin(), cp[it.col].end(), make_pair(qwq.time, 0ll)) - cp[it.col].begin();
            if (idx == cp[it.col].size()) continue;
            if (cp[it.col][idx].first == qwq.time) {
                if (cp[it.col][idx].second >= qwq.dist + it.w) {
                    tis[it.v] = qwq.time;
                    dis[it.v] = qwq.dist + it.w;
                    op.push({it.v, tis[it.v], dis[it.v]});
                    continue;
                }
                idx ++;
            }
            ll l = idx, r = cp[it.col].size();
            while (l < r) {
                ll mid = l + r >> 1;
                if (xm[it.col].query(l, mid) >= it.w) r = mid;
                else l = mid + 1;
            }
            if (cp[it.col].size() <= l) continue;
            if (tis[it.v] < cp[it.col][l].first) continue;
            if (xm[it.col].query(l, l) >= it.w) {
                tis[it.v] = cp[it.col][l].first;
                dis[it.v] = it.w;
                op.push({it.v, tis[it.v], dis[it.v]});
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (flag[i]) cout << 1;
        else cout << 0;
    }
    cout << endl;
    return;
}
void AC() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++) {
        mp[i].clear();
        flag[i] = 0;
        tis[i] = INF;
        dis[i] = INF;
    }
    for (int i = 1; i <= m; i ++) {
        cp[i].clear();
        cp[i].push_back({ -1, -1});
        ll x, y, col, z;
        cin >> x >> y >> col >> z;
        mp[x].push_back({col, x, y, z});
        mp[y].push_back({col, y, x, z});
    }
    for (int i = 1; i <= k; i ++) {
        ll col, dist;
        cin >> col >> dist;
        cp[col].push_back({i, dist});
    }
    for (int i = 1; i <= m; i ++) {
        if (cp[i].size() > 1) {
            xm[i].len = cp[i].size() - 1;
            xm[i].init(cp[i]);
        }
    }
    dijkstra();
}
int main() {
    ios::sync_with_stdio(false);
    Tex = 1;
    // cin >> Tex;
    while (Tex --) AC();
    return 0;
}