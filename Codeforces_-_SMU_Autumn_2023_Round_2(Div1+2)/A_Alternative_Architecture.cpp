/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-10 12:11:40
 *
 * Problem: A. Alternative Architecture
 * Contest: Codeforces - SMU Autumn 2023 Round 2(Div.1+2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/472110/problem/A
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
#define endl '\n'
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

bool check(int x, int z) {
    int y = z * z - x * x;
    int res = sqrtl(y);
    return y == res * res;
}

void solve() {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if(a > b)swap(a, b);
    int ans = 1;
    if(__gcd(a, b) == 1) {
        cout << ans + (a != b) << endl;
        return ;
    }
    for(int i = a - 1; i >= 1; i--) {
        if(check(i, a)) {
            int res = b / a;
            if(check(i * res, a * res))ans++;
        }
    }
    if(a != b)ans *= 2;
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}