/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-14 15:05:36
 *
 * Problem: F1. Guess the K-th Zero (Easy version)
 * Contest: Codeforces - Codeforces Round 719 (Div. 3)
 * URL:     https://codeforces.com/contest/1520/problem/F1
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
// #define endl '\n'
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, t, k;
    cin >> n >> t >> k;
    int l = 1, r = n, ans;
    while(l <= r) {
        int mid = l + r >> 1;
        cout << "? " << l << " " << mid << endl;
        int x;
        cin >> x;
        int res = mid - l + 1 - x;
        if(res < k)l = mid + 1, k -= res;
        else r = mid - 1, ans = mid;
    }
    cout << "! " << l << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}