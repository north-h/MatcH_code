/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-30 13:13:48
 * =====================================
 *                  _   _         _
 * _ __   ___  _ __| |_| |__     | |__
 *| '_ \ / _ \| '__| __| '_ \    | '_ \
 *| | | | (_) | |  | |_| | | |   | | | |
 *|_| |_|\___/|_|   \__|_| |_|___|_| |_|
 *                          |_____|
 */

#pragma GCC optimize(3)

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
const int N = 100100;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int a[N], s[N];

void solve() {
    int l, r;
    cin >> l >> r;
    cout << s[r] - s[l - 1] << endl;
}

int32_t main() {
    IOS;
    for(int i = 1; i < N; i++)a[i] = 1;
    a[1] = 0;
    for(int i = 2; i * i < N; i++) {
        if(a[i]) {
            for(int j = i + i; j < N; j += i) {
                a[j] = 0;
            }
        }
    }
    for(int i = 0; i < N; i++)s[i] = s[i - 1] + a[i];
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}