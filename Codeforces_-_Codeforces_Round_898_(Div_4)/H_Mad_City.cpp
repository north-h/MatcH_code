/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-21 22:36:18
 *
 * Problem: H. Mad City
 * Contest: Codeforces - Codeforces Round 898 (Div. 4)
 * URL:     https://codeforces.com/contest/1873/problem/H
 * MemoryL: 256 MB
 * TimeL:   4000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
const double PI = 3.1415926;
const int N = 200010;
const int M = 1910;

using namespace std;

vector<int>g[N];
int n, a, b;
int dg[N],  vis[N], db[N], da[N];

void bfs() {
    queue<int> q;
    vector<int> vi(n + 1);
    for(int i = 1; i <= n; i++) {
        if(dg[i] == 1) {
            q.push(i);
            vi[i] = 1;
            vis[i] = 0;
        }
    }
    while(q.size()) {
        auto t = q.front();
        q.pop();
        for(auto i : g[t]) {
            if(vi[i])continue;
            dg[i]--;
            if(dg[i] == 1) {
                q.push(i);
                vi[i] = 1;
                vis[i] = 0;
            }
        }
    }
}

PII bfs_b(int b) {
    queue<int> q;
    vector<int> vi(n + 1);
    q.push(b);
    vi[b] = 1;
    db[b] = 0;
    while(q.size()) {
        auto t = q.front();
        q.pop();
        for(auto i : g[t]) {
            if(vi[i])continue;
            q.push(i);
            vi[i] = 1;
            db[i] = db[t] + 1;
            if(vis[i])return {i, db[i]};
        }
    }
}

int bfs_a(int x, int y) {
    queue<int> q;
    vector<int> vi(n + 1);
    q.push(x);
    vi[x] = 1;
    da[x] = 0;
    if(x == y)return da[x];
    while(q.size()) {
        auto t = q.front();
        q.pop();
        for(auto i : g[t]) {
            if(vi[i])continue;
            q.push(i);
            vi[i] = 1;
            da[i] = da[t] + 1;
            if(i == y)return da[i];
        }
    }
}

void solve() {
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++) {
        vis[i] = 1;
        dg[i] = db[i] = da[i] = 0;
        g[i].clear();
    }
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        dg[x]++;
        dg[y]++;
    }
    bfs();
    if(a == b) {
        cout << "NO" << endl;
        return ;
    }
    if(vis[b]) {
        cout << "YES" << endl;
        return ;
    }
    auto d = bfs_b(b);
    int disb = d.se;
    int disa = bfs_a(a, d.fi);
    if(disb < disa)cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}