/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-06 17:57:51
 *
 * Problem: E. Exact Change
 * Contest: Codeforces - SMU Autumn 2023 Round 1(Div.1)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/470089/problem/E
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    vector<int> a(n);
    for(auto &i : a)cin >> i;
    // for(auto i : a)cout << i << ' ';
    // cout << endl;
    int ans = INF;
    for(int i = 0; i <= 1; i++) {
        for(int j = 0; j <= 2; j++) {
            int res = 0;
            for(auto k : a) {
                int cnt = INF;
                for(int ii = 0; ii <= i; ii++) {
                    for(int jj = 0; jj <= j; jj++) {
                        int x = k - ii - jj * 2;
                        if(x >= 0 && x % 3 == 0) {
                            cnt = min(cnt, x / 3);
                        }
                    }
                }
                res = max(res, cnt);
            }
            ans = min(ans, res + i + j);
        }
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