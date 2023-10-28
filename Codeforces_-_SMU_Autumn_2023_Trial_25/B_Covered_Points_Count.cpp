/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-28 12:33:50
 *
 * Problem: B. Covered Points Count
 * Contest: Codeforces - SMU Autumn 2023 Trial 25
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/481917/problem/B
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
const int N = 400010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int b[N], s[N];

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    vector<PII> c(n);
    unordered_map<int, int> p, up, p1;
    for(int i = 0; i < n; i++) {
        cin >> c[i].fi >> c[i].se;
        a.push_back(c[i].fi);
        a.push_back(c[i].se);
    }
    sort(ALL(a));
    // a.erase(unique(ALL(a)), a.end());
    for(auto i : a)cout << i << ' ';
    cout << endl;
    for(int i = 0; i < a.size(); i++) {
        p[a[i]] = i + 1;
        p1[i + 1] = a[i];
        // debug2(a[i], p[a[i]]);
    }
    for(int i = 0; i < n; i++) {
        b[p[c[i].fi]]++;
        b[p[c[i].se] + 1]--;
        debug2(p[c[i].fi], p[c[i].se]);
    }
    for(int i = 1; i <= a.size(); i++) {
        s[i] = s[i - 1] + b[i];
        // up[s[i]]++;
    }
    // for(int i = 2; i <= a.size(); i++) {
    //     if(s[i] != s[i - 1])up[s[i - 1]]++;
    // }
    // up[s[a.size()]]++;
    for(int i = 1; i <= a.size(); i++)cout << s[i] << ' ';
    cout << endl;
    for(int i = 2; i <= a.size(); i++) {
        int mn = min(s[i], s[i - 1]);
        // debug1(up[mn]);
        // debug2(p1[i], p1[i - 1]);
        // debug1(max(abs(p1[i] - p1[i - 1]) - 1, 0ll));
        up[mn] += max(abs(p1[i] - p1[i - 1]) - 1, 0ll);
    }
    for(int i = 1; i <= n; i++)cout << up[i] << ' ';
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}