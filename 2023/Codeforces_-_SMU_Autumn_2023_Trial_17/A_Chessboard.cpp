/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-14 15:07:50
 *
 * Problem: A. Chessboard
 * Contest: Codeforces - SMU Autumn 2023 Trial 17
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/478093/problem/A
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
    string sans1, sans2;
    for(int i = 0; i < n * 2 * n * 2; i++) {
        if(i & 1)sans1 += '1';
        else sans1 += '0';
    }
    sans2 = sans1.substr(1) + sans1[0];
    vector<string> a;
    for(int i = 0; i < 4 ; i++) {
        string s;
        for(int j = 0; j < n; j++) {
            string str;
            cin >> str;
            s += str;
        }
        a.push_back(s);
    }
    vector<int> b{1, 2, 3, 4};
    int ans = INT_MAX;
    do {
        int cnt1 = 0;
        int cnt2 = 0;
        string s1;
        for(auto i : b)s1 += a[i - 1];
        for(int i = 0; i < n * 2 * n * 2; i++) {
            if(sans1[i] != s1[i])cnt1++;
            if(sans2[i] != s1[i])cnt2++;
        }
        ans = min({cnt1, cnt2, ans});
    } while(next_permutation(ALL(b)));
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}