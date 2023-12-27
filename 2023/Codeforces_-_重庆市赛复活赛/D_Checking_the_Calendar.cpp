/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-25 16:30:25
 *
 * Problem: D. Checking the Calendar
 * Contest: Codeforces - 重庆市赛复活赛
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/488622/problem/D
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
    string a, b;
    cin >> a >> b;

    int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string s[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

    int x;
    for (int i = 0; i < 7; i++) {
        if (s[i] == a) {
            x = i;
        }
    }

    for (int i = 0; i < 12; i++) {
        int k = d[i] % 7;
        if (s[(x + k) % 7] == b) {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}