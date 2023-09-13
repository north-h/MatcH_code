/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-13 16:05:31
 *
 * Problem: B. Gardener and Tree
 * Contest: Codeforces - SMU Autumn 2023 Round 3(Div.2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/470094/problem/B
 * MemoryL: 256 MB
 * TimeL:   4000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PDD pair<double,double>
#define PCI pair<char,int>
#define PSI pair<string,int>
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()
#define int128 __int128
#define endl '\n'
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1, vector<int> (n + 1, 0));
    vector<int> vis(n + 1, 0), dg(n + 1, 0);
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if(a > b)swap(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
        dg[a]++;
        dg[b]++;
    }
    // for(int i = 1; i <= n; i++) {
    //     if(dg[i] == 0)cout << i << ' ';
    // }
    // cout << endl;
    set<int> st;
    int ans = n;
    for(int i = 1; i <= n; i++) {
        if(dg[i] == 1) {
            st.insert(i);
        }
    }
    // for(int i = 1; i <= n; i++)cout << dg[i] << ' ';
    // cout << endl;
    for(int i = 1; i <= min(n, k); i++) {
        set<int> temp;
        for(auto j : st) {
            for(auto k : g[j]) {
                dg[k]--;
                if(dg[k] == 1)temp.insert(k);
            }
        }
        ans -= st.size();
        st = temp;
    }
    cout << ans << endl;
}
int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}