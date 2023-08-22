/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-12 09:44:50
 * =====================================
 *                  _   _         _
 * _ __   ___  _ __| |_| |__     | |__
 *| '_ \ / _ \| '__| __| '_ \    | '_ \
 *| | | | (_) | |  | |_| | | |   | | | |
 *|_| |_|\___/|_|   \__|_| |_|___|_| |_|
 *                          |_____|
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
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    sort(rALL(a));
    // for(auto i : a)cout << i << ' ';
    // cout << endl;
    for(int j = 0; j < n; j++) {
        int m = a[j];
        while(m && mp.count(m)||m>n) {
            m /= 2;
        }
        mp[m]=1;
    }
    for(int i = 1; i <= n; i++) {
        if(!mp.count(i)) {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}