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

struct S {
    int l,r,cnt0,cnt1;
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<PII > a(n + 1);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
        a[i].fi %= k;
        if (a[i].fi == 0)ans.push_back(i);
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) {
        if (a[i].fi == 0)continue;
        ans.push_back(a[i].se);
    }
    for (auto i: ans)cout << i << ' ';
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
