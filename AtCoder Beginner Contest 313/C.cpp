/*
   Author : north_h
   File : C.cpp
   Time : 2023/8/5/20:11
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
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)cin >> a[i], sum += a[i];
    int ans1 = 0, ans2 = 0;
    int v1 = sum / n, v2 = (sum + n - 1) / n;
    for (int i = 0; i < n; i++) {
        if (v1 > a[i])ans1 += v1 - a[i];
        if (v2 < a[i])ans2 += a[i] - v2;
    }
    cout << max(ans1, ans2) << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
//    cin >> h_h;
    while (h_h--)solve();
    return 0;
}