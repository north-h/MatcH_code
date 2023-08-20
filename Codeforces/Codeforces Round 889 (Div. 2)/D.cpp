/*
   Author : north_h
   File : D.cpp
   Time : 2023/7/30/12:03
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
    vector<int> a(n);
    int cntz = 0, cntf = 0;
    PII mx, mn;
    mx.fi = INT_MIN;
    mn.fi = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (mx.fi < a[i])mx = {a[i], i};
        if (mn.fi > a[i])mn = {a[i], i};
        if (a[i] < 0)cntf++;
        if (a[i] > 0)cntz++;
    }
    if (is_sorted(ALL(a))) {
        cout << 0 << endl;
        return;
    }
//    cout<<mx.fi<<' '<<mx.se<<endl;
//    cout<<mn.fi<<' '<<mn.se<<endl;
    vector<PII > ans;
    if (cntz >= 13) {
        while (mx.fi <= 20)ans.push_back({mx.se + 1, mx.se + 1}), mx.fi += mx.fi;
        for (int i = 0; i < n; i++)if (a[i] < 0)ans.push_back({i + 1, mx.se + 1});
        for (int i = 1; i < n; i++)ans.push_back({i + 1, i});
    } else if (cntf >= 13) {
        while (abs(mn.fi) <= 20)ans.push_back({mn.se + 1, mn.se + 1}), mn.fi += mn.fi;
        for (int i = 0; i < n; i++)if (a[i] > 0)ans.push_back({i + 1, mn.se + 1});
        for (int i = n - 2; i >= 0; i--)ans.push_back({i + 1, i + 2});
    } else {
        if (mx.fi > abs(mn.fi)) {
            for (int i = 0; i < n; i++)if (a[i] < 0)ans.push_back({i + 1, mx.se + 1});
            for (int i = 1; i < n; i++)ans.push_back({i + 1, i});
        } else {
            for (int i = 0; i < n; i++)if (a[i] > 0)ans.push_back({i + 1, mn.se + 1});
            for (int i = n - 2; i >= 0; i--)ans.push_back({i + 1, i + 2});
        }
    }
    cout << ans.size() << endl;
    for (auto [x, y]: ans)cout << x << ' ' << y << endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}