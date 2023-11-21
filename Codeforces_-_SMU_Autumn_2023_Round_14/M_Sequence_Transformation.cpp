/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-21 14:52:26
 *
 * Problem: M. Sequence Transformation
 * Contest: Codeforces - SMU Autumn 2023 Round 14
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/487840/problem/M
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ===========================================================================
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
#define PI acos(-1)
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    map<int, vector<int>> up;
    vector<int> a(n + 1);
    for(int i = 1, x; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    if(mp.size() == 1) {
        cout << 0 << endl;
        return ;
    }
    for(int i = 1; i < n; i++) {
        int x = i;
        while(a[i] == a[i + 1] && i < n)i++;
        up[x].push_back(x);
    }
    int ans = INF;
    for(auto [x, y] : up) {
        // cout << x << ':';
        // for(auto i : y)cout << i << ' ';
        // cout << endl;
        int a = y[0];
        int b = y.back();
        int res = 0;
        if(a == 1 && b == n)res = y.size() - 1;
        else if(a == 1 && b != n)res = y.size();
        else if(a != 1 && b == n)res = y.size();
        else res = y.size() + 1;
        ans = min(res, ans);
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