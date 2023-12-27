/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-09 13:45:17
 *
 * Problem: B. Balanced Substring
 * Contest: Codeforces - SMU Autumn 2023 Trial 13
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475604/problem/B
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
const int N = 100010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

// int mp[N];

void solve() {
    int n;
    string  ss;
    map<int, int> mp;
    cin >> n >> ss;
    vector<int> s(n + 1);
    for(int i = 0; i < n; i++) {
        if(ss[i] == '1')s[i + 1] = 1;
        else s[i + 1] = -1;
    }
    for(int i = 1; i <= n; i++) {
        s[i] += s[i - 1];
        // debug1(s[i]);
        mp[s[i]] = max(mp[s[i]], i);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, mp[s[i - 1]] - i + 1);
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
