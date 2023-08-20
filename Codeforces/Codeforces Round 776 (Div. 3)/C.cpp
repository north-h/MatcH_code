/*
Author : north_h
File : C.cpp
Time : 2023/8/4/10:00
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
#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define TIII tuple<int,int,int>
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
    vector<PII > a, b;
    int k, n;
    cin >> k >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(i, x);
        b.emplace_back(i, y);
        mp[i] = y;
    }
    sort(ALL(b), [](PII x, PII y) {
        return x.se > y.se;
    });
    sort(ALL(a), [](PII x, PII y) {
        return x.se < y.se;
    });
    vector<bool> vis(n + 1, false);
    vector<PII > ans;
    int anss = 0;
    for (int i = 0; i < n - k * 2; i++) {
        vis[b[i].fi] = true;
    }
    for (int i = 0, j = n - 1, cnt = 0; cnt < k; i++, j--, cnt++) {
        while (vis[a[i].fi] && i < j)i++;
        while (vis[a[j].fi] && i < j)j--;
        ans.emplace_back(a[i].fi, a[j].fi);
        anss += mp[a[i].fi] + mp[a[j].fi];
    }
    cout << anss << endl;
    for (auto [x, y]: ans)cout << x << ' ' << y << endl;
    cout << endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
