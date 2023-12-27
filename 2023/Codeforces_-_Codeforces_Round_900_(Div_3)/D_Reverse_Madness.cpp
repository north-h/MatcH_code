/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-26 22:36:45
 *
 * Problem: D. Reverse Madness
 * Contest: Codeforces - Codeforces Round 900 (Div. 3)
 * URL:     https://codeforces.com/contest/1878/problem/D
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
#define lcm(x,y) x*y/__gcd(x,y)
#define debug(a) cout << #a << '=' << a << endl;
#define lf(x)   fixed << setprecision(x)
const double PI = 3.1415926;
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    s = " " + s;
    vector<int> l(m + 1), r(m + 1);
    for(int i = 1; i <= m; i++)cin >> l[i];
    for(int i = 1; i <= m; i++)cin >> r[i];
    vector<int> vis(n + 1);
    for(int i = 1; i <= m; i++) {
        for(int j = l[i]; j <= r[i]; j++) {
            vis[j] = i;
        }
    }
    vector<int> ss(n + 10);
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        int id = vis[x];
        int a = min(x, l[id] + r[id] - x);
        int b = max(x, l[id] + r[id] - x);
        ss[a]++;
        ss[b + 1]--;
    }
    for(int i = 1; i <= n; i++) {
        ss[i] += ss[i - 1];
    }
    for(int i = 1; i < s.size(); i++) {
        if(ss[i] % 2) {
            int id = vis[i];
            int a = l[id];
            int b = r[id];
            cout << s[a + b - i];
        } else cout << s[i];
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