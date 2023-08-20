/*
   Author : north_h
   File : C.cpp
   Time : 2023/7/29/22:28
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
    vector<int> a(n + 1);
    PII mx, mn;
    mx.fi = -INF;
    mn.fi = INF;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (mx.fi <= a[i])mx = {a[i], i};
        if (mn.fi >= a[i])mn = {a[i], i};
    }
    if (is_sorted(a.begin() + 1, a.end())) {
        cout << 0 << endl;
        return;
    }
    if (mx.fi <= 0 || mn.fi >= 0) {
        cout << n - 1 << endl;
        for (int i = n - 1; i >= 1; i--)cout << i << ' ' << i + 1 << endl;
        return;
    }
    vector<PII > ans;
    while (mx.fi <= 20) {
        mx.fi += mx.fi;
        ans.push_back({mx.se, mx.se});
    }
    for (int i = 1; i <= n; i++) {
        while (a[i] < 0) {
            a[i] += mx.fi;
            ans.push_back({i, mx.se});
        }
    }
    for (int i = 2; i <= n; i++)ans.push_back({i, i - 1});
    cout << ans.size() << endl;
    for (auto [x, y]: ans)cout << x << ' ' << y << endl;
    //for(int i=1;i<=n;i++)cout<<a[i]<<' ';
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}