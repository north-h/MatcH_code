/*
Author : north_h
File : E.cpp
Time : 2023/8/3/15:36
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i], s[i] = s[i - 1] + a[i];
    for (int i = 2; i <= n; i++)a[i] = max(a[i], a[i - 1]);
    while (q--) {
        int k;
        cin >> k;
        if (k >= a[n])cout << s[n] << ' ';
        else if (k < a[1])cout << 0 << ' ';
        else {
            int pos = upper_bound(a.begin() + 1, a.end(), k) - (a.begin() + 1);
            cout << s[pos] << ' ';
        }
    }
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
