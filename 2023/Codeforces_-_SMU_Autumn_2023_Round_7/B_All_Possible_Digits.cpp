/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-10 13:00:35
 *
 * Problem: B. All Possible Digits
 * Contest: Codeforces - SMU Autumn 2023 Round 7
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/478437/problem/B
 * MemoryL: 256 MB
 * TimeL:   3000 ms
 * ===========================================================================
 */
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define int long long
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

int cnt = 0;
int t;

void solve() {
    cnt++;
    int n, p;
    cin >> n >> p;
    vector<int> a(n + 1);
    map<int, int> mp;
    a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    bool ok = true;
    for(int i = 0; i < a[n]; i++) {
        if(!mp.count(i)) {
            ok = false;
            break;
        }
    }
    if(ok) {
        int t = p - 1;
        while(mp[t])t--;
        cout << max(0ll, t - a[n]) << endl;
    } else {
        int ans = p - a[n];
        mp[0] = 1;
        for (int i = n - 1; i >= 0; i--) {
            a[i]++;
            if(a[i] == p)a[i] = 0;
            else break;
        }
        for(int i = 0; i <= n; i++)mp[a[i]] = 1;
        int t = a[n] - 1;
        while(mp.count(t))t--;
        cout << ans + max(0ll, t) << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    t = h_h;
    while (h_h--)solve();
    return 0;
}