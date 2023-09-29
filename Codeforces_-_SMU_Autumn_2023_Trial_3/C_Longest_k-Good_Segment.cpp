/*
 * =======================================================================
 * Author:  north_h
 * Time:    2023-09-29 10:37:16
 *
 * Problem: C. Longest k-Good Segment
 * Contest: Codeforces - SMU Autumn 2023 Trial 3
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475546/problem/C
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ========================================================================
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
const double PI = 3.1415926;
const int N = 1000010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

// int mp[N];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>a (n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> mp;
    int ans = 0;
    int l, r;
    for(int i = 0, j = 0; i < n; i++) {
        mp[a[i]]++;
        while(j < n && mp.size() > k ) {
            mp[a[j]]--;
            if(mp[a[j]] == 0)mp.erase(a[j]);
            j++;
        }
        if(ans < i - j + 1) {
            ans = i - j + 1;
            l = j;
            r = i;
        }
    }
    cout << l + 1 << ' ' << r + 1 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}