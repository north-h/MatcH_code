/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-08 14:35:23
 *
 * Problem: C - World Tour Finals
 * Contest: AtCoder - UNIQUE VISION Programming Contest 2023 Autumn(AtCoder Beginner Contest 323)
 * URL:     https://atcoder.jp/contests/abc323/tasks/abc323_c
 * MemoryL: 1024 MB
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
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    vector<int> b(m + 1);
    vector<string> s(n + 1);
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        // debug1(s[i]);
        int score = 0;
        for(int j = 0; j < s.size(); j++) {
            if(s[i][j] == 'o')score += a[j + 1];
        }
        debug1(score);
        b[i] = score;
        mx = max(score, mx);
    }
    for(int i = 1; i <= n; i++) {
        if(mx != b[i]) {
            int res = mx - b[i];
            debug1(res);
            int cnt = 0;
            int sum=0;
            for(int j = s[i].size() - 1; j >= 0; j--) {
                if(a[j+1]>)
                if(s[i][j] == 'x') {
                    if(sum < res)cnt++, sum += a[j + 1];
                    else break;
                }
            }
            // mx=max(sum)
            cout << cnt << endl;
        } else cout << 0 << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}