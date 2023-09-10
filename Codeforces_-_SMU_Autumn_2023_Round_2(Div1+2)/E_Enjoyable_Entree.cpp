/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-10 12:11:15
 *
 * Problem: E. Enjoyable Entree
 * Contest: Codeforces - SMU Autumn 2023 Round 2(Div.1+2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/472110/problem/E
 * MemoryL: 512 MB
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
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    double a = 100, b = 0;
    if(n == 1)cout << "100 0" << endl;
    else if(n == 2)cout << "0 100" << endl;
    else if(n <= 35) {
        for (int i = 3; i <= n; i++) {
            if(i == n) {
                printf("%.6f %.6f", a * 1.0 / 2 + b * 1.0 / 2, 100 - (a * 1.0 / 2 + b * 1.0 / 2));
            }
            double t = a;
            a = b;
            b = t / 2 + b / 2;
        }
    } else {
        cout << "33.333333 66.666667" << endl;
    }
}
int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}