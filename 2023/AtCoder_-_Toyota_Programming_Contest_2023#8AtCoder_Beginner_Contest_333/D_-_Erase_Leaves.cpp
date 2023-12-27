/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-16 20:00:24
 *
 * Problem: D - Erase Leaves
 * Contest: AtCoder - Toyota Programming Contest 2023#8（AtCoder Beginner Contest 333）
 * URL:     https://atcoder.jp/contests/abc333/tasks/abc333_d
 * MemoryL: 1024 MB
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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    auto bfs = [&](int s)->int{
        int res = 0;
        queue<int> q;
        vector<int> vis(n + 1);
        q.push(s);
        vis[s] = 1;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            for(auto i : g[t]) {
                if(vis[i])continue;
                q.push(i);
                vis[i] = 1;
                res++;
            }
        }
        return res;
    };
    int ans = M;
    for(auto t : g[1]) {
        ans = min(ans, bfs(t));
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}