/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-24 16:23:08
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
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    ll sum = 0;
    int cnt = 0;
    vector<int> a(7);
    for(int i = 0; i < 7; i++) {
        cin >> a[i];
    }
    sort(ALL(a));
    int mx = a[6];
    vector<int> ans;
    for(int i = 0; i < 7; i++) {
        if(ans.size() < 3) {
            sum += a[i];
            ans.push_back(a[i]);
            // cout << a[i] << ' ';
        }
        if(ans.size() == 3) {
            if(sum < mx) {
                sum -= a[i];
                ans.pop_back();
            } else break;
        }
    }
    for(auto i : ans)cout << i << ' ';
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}