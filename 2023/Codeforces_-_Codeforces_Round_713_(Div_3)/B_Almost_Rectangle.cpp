/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-15 13:25:18
 *
 * Problem: B. Almost Rectangle
 * Contest: Codeforces - Codeforces Round 713 (Div. 3)
 * URL:     https://codeforces.com/contest/1512/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
const int N = 410;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

char g[N][N];

void solve() {
    int n;
    cin >> n;
    int x1, x2, y1, y2;
    bool ok = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> g[i][j];
            if(g[i][j] == '*' ) {
                if(ok) {
                    ok = false;
                    x1 = i, y1 = j;
                } else x2 = i, y2 = j;
            }
        }
    }
    // cout << x1 << ' ' << y1 << endl;
    // cout << x2 << ' ' << y2 << endl;
    if(x1 == x2) {
        if(x1 == n - 1) {
            g[x1 - 1][y1] = g[x2 - 1][y2] = '*';
        } else {
            g[x1 + 1][y1] = g[x2 + 1][y2] = '*';
        }
    } else if(y1 == y2) {
        if(y1 == n - 1) {
            g[x1][y1 - 1] = g[x2][y2 - 1] = '*';
        } else {
            g[x1][y1 + 1] = g[x2][y2 + 1] = '*';
        }
    } else {
        g[x2][y1] = g[x1][y2] = '*';
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << g[i][j];
        }
        cout << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}