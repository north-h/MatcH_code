//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using PII = pair<ll, ll>;

const int N = 3e5 + 10, M = 210;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
int n, m, h;
vector<pair<int, int>> vct[200005];
bool mark[200005];
priority_queue<pair<int, pair<int, int>>> pq;
int dis1[200005][2], dis2[200005][2];  ////0为没有骑马,1为骑马
map<pair<int, int>, int> vis; ////<from,状态>
void dijkstra(int s, int typ) {
    vis.clear();
    if (typ == 1) for (int i = 1; i <= n; i++) dis1[i][0] = dis1[i][1] = LONG_LONG_MAX / 2;
    if (typ == 2) for (int i = 1; i <= n; i++) dis2[i][0] = dis2[i][1] = LONG_LONG_MAX / 2;
    typ == 1 ? dis1[s][0] = 0 : dis2[s][0] = 0;
    if (mark[s] && typ == 1) dis1[s][1] = 0;
    if (mark[s] && typ == 2) dis2[s][1] = 0;
    pq.push({0, {s, mark[s]}}); ////<权重,<from,状态>>
    while (pq.size()) {
        int from = pq.top().second.first, sta = pq.top().second.second;
        pq.pop();
        if (vis[ {from, sta}]) continue;
        vis[ {from, sta}] = 1;
        for (auto v : vct[from]) {
            int to = v.first, w = v.second;
            if (typ == 1) {
                if (sta) {
                    if (dis1[to][1] > dis1[from][1] + w / 2) {
                        dis1[to][1] = dis1[from][1] + w / 2;
                        pq.push({ -dis1[to][1], {to, 1}});
                    }
                }
                else if (mark[to]) {
                    if (dis1[to][1] > dis1[from][0] + w) {
                        dis1[to][1] = dis1[from][0] + w;
                        pq.push({ -dis1[to][1], {to, 1}});
                    }
                }
                else {
                    if (dis1[to][0] > dis1[from][0] + w) {
                        dis1[to][0] = dis1[from][0] + w;
                        pq.push({ -dis1[to][0], {to, 0}});
                    }
                }
            }
            if (typ == 2) {
                if (sta) {
                    if (dis2[to][1] > dis2[from][1] + w / 2) {
                        dis2[to][1] = dis2[from][1] + w / 2;
                        pq.push({ -dis2[to][1], {to, 1}});
                    }
                }
                else if (mark[to]) {
                    if (dis2[to][1] > dis2[from][0] + w) {
                        dis2[to][1] = dis2[from][0] + w;
                        pq.push({ -dis2[to][1], {to, 1}});
                    }
                }
                else {
                    if (dis2[to][0] > dis2[from][0] + w) {
                        dis2[to][0] = dis2[from][0] + w;
                        pq.push({ -dis2[to][0], {to, 0}});
                    }
                }
            }
        }
    }
}
void solve() {          ////E
    cin >> n >> m >> h;
    for (int i = 1; i <= n; i++) vct[i].clear(), mark[i] = false;
    for (int i = 1; i <= h; i++) {
        int x; cin >> x;
        mark[x] = true;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        vct[u].emplace_back(v, w);
        vct[v].emplace_back(u, w);
    }
    dijkstra(1, 1);
    dijkstra(n, 2);
    if (dis1[n][0] == LONG_LONG_MAX / 2 && dis1[n][1] == LONG_LONG_MAX / 2) {
        cout << "-1" << endl;
        return;
    }
    else {
        int ans = LONG_LONG_MAX;
        for (int i = 1; i <= n; i++) ans = min(ans, max(min(dis1[i][0], dis1[i][1]), min(dis2[i][0], dis2[i][1])));
        cout << ans << endl;
    }
}