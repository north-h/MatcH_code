/*
    Author : north_h
    File : E.cpp
    Time : 2023/7/26/14:58
                    _   _         _
   _ __   ___  _ __| |_| |__     | |__
  | '_ \ / _ \| '__| __| '_ \    | '_ \
  | | | | (_) | |  | |_| | | |   | | | |
  |_| |_|\___/|_|   \__|_| |_|___|_| |_|
                            |_____|
*/
#pragma GCC optimize(3)

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
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.begin(),a.end()
#define int128 __int128
#define endl '\n'
const int N = 10010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int s;
    cin >> s;
    int a1, a2, a3, a4, a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    int sum = a6 + a5 + a4 + (a3 + 3) / 4;
    int cnt2 = a4 * 5;
    if (a3 % 4 == 1)cnt2 += 5;
    else if (a3 % 4 == 2)cnt2 += 3;
    else if (a3 % 4 == 3)cnt2++;
    int cnt1 = 11 * a5;
    if (a3 % 4 == 1)cnt1 += 7;
    else if (a3 % 4 == 2)cnt1 += 6;
    else if (a3 % 4 == 3)cnt1 += 5;
    if (a2 > cnt2) {
        a2 -= cnt2;
        int cnt = (a2 + 8) / 9;
        sum += cnt;
        int y = (cnt * 9 - a2);
        cnt1 += y * 4;
    } else {
        int cnt = cnt2 - a2;
        cnt1 += cnt * 4;
    }
    a1 = max(0ll, a1 - cnt1);
    sum += (a1 + 35) / 36;
    if (sum <= s)cout << "Yes" << endl;
    else cout << "No" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
