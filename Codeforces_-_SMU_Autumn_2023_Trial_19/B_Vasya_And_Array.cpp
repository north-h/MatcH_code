/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-18 10:56:49
 *
 * Problem: B. Vasya And Array
 * Contest: Codeforces - SMU Autumn 2023 Trial 19
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/479353/problem/B
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
    vector<int> a(n + 1), s(n + 1), ss(n + 1);
    vector<PII> b;
    while(m--) {
        int t, l, r;
        cin >> t >> l >> r;
        if(t) {
            a[l]++;
            a[r]--;
        } else b.push_back({l, r});
    }
    for(int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];
    for(int i = 1; i <= n; i++) {
        if(s[i])s[i] = 1;
        else s[i] = 0;
    }
    for(int i = 1; i <= n; i++)ss[i] = ss[i - 1] + s[i];
    for(auto [l, r] : b) {
        if(ss[r] - ss[l - 1] == r - l + 1) {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
    int mx = n;
    for(int i = 2; i <= n; i++) {
        if(s[i - 1])cout << mx << ' ';
        else {
            mx--;
            cout << mx << ' ';
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}