/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-05 22:45:43
 *
 * Problem: G. Lights
 * Contest: Codeforces - Codeforces Round 913 (Div. 3)
 * URL:     https://codeforces.com/contest/1907/problem/G
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
const int N = 100010;
const int M = 110;

using namespace std;

int n;
string s;
int a[N], in[N];
vector<int> g[N], ans;

void bfs() {
    queue<int> q;
    vector<int> vi(n + 1);
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) {
            if(s[i] == '1') {
                ans.push_back(i);
                s[i] ^= 1;
                s[a[i]] ^= 1;
            }
            q.push(i);
            vi[i] = 1;
        }
    }
    while(q.size()) {
        auto t = q.front();
        q.pop();
        for(auto i : g[t]) {
            if(vi[i])continue;
            in[i]--;
            if(in[i] == 0) {
                if(s[i] == '1') {
                    ans.push_back(i);
                    s[i] ^= 1;
                    s[a[i]] ^= 1;
                }
                q.push(i);
                vi[i] = 1;
            }
        }
    }
}

void solve() {
    cin >> n >> s;
    s = " " + s;
    ans.clear();
    for(int i = 1; i <= n; i++) {
        in[i] = a[i] = 0;
        g[i].clear();
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        g[i].push_back(a[i]);
        in[a[i]]++;
    }
    bfs();
    for(int i = 1; i <= n; i++) {
        if(s[i] == '1') {
            vector<int> r1, r2;
            string t = s;
            if(s[i] == '1') {
                s[i] ^= 1;
                s[a[i]] ^= 1;
                r1.push_back(i);
            }
            int u = a[i];
            while(u != i) {
                if(s[u] == '1') {
                    s[u] ^= 1;
                    s[a[u]] ^= 1;
                    r1.push_back(u);
                }
                u = a[u];
            }
            int v = a[i];
            while(v != i) {
                if(t[v] == '1') {
                    t[v] ^= 1;
                    t[a[v]] ^= 1;
                    r2.push_back(v);
                }
                v = a[v];
            }
            if(r1.size() <= r2.size()) {
                for(auto i : r1)ans.push_back(i);
            } else {
                for(auto i : r2)ans.push_back(i);
            }
        }
    }
    for(auto i : s) {
        if(i == '1') {
            cout << -1 << endl;
            return ;
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans)cout << i << ' ';
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}