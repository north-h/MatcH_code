/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-11 23:08:15
 *
 * Problem: F. Selling a Menagerie
 * Contest: Codeforces - Codeforces Round 895 (Div. 3)
 * URL:     https://codeforces.com/problemset/problem/1872/F
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 0x3f3f3f3f;

using namespace std;

vector<int> g[N], a, c;
int n, in[N], vis[N];
vector<int> ans;

void bfs() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) {
            q.push(i);
            vis[i] = 1;
            ans.push_back(i);
        }
    }
    while(q.size()) {
        auto t = q.front();
        q.pop();
        for(auto i : g[t]) {
            if(vis[i])continue;
            in[i]--;
            if(in[i] == 0) {
                q.push(i);
                vis[i] = 1;
                ans.push_back(i);
            }
        }
    }
}

void solve() {
    cin >> n;
    a.resize(n + 1, 0);
    c.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        in[i] = 0;
        g[i].clear();
        vis[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        g[i].push_back(a[i]);
        in[a[i]]++;
    }
    for(int i = 1; i <= n; i++)cin >> c[i];
    ans.clear();
    bfs();
    set<int> st;
    for(int i = 1; i <= n; i++) {
        vector<PII> ve;
        if(!vis[i]) {
            st.insert(i);
        }
    }
    for(auto i : st) {
        int now = a[i];
        while(now != i) {
            ans.push_back(now);
            now = a[now];
            st.erase(now);
        }
    }
    for(auto i : ans) {
        cout << i << ' ';
    }
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}