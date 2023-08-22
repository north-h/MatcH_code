/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-11 10:45:42
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
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x % 10]++;
    }
    // for(auto [x, y] : mp)cout << x << ' ' << y << endl;
    bool ok = false;
    for(int i = 0; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k <= 9; k++) {
                if((i + j + k) % 10 == 3) {
                    if(i == j && j == k && mp[i] >= 3)ok = true;
                    else if(i == j && j != k && mp[i] >= 2 && mp[k] >= 1)ok = true;
                    else if(i == k && k != j && mp[i] >= 2 && mp[j] >= 1)ok = true;
                    else if(k == j && i != k && mp[j] >= 2 && mp[i] >= 1)ok = true;
                    else if(i != j && j != k&&i!=k && mp[j] >= 1 && mp[k] >= 1 && mp[i] >= 1)ok = true;
                    if(ok) {
                    	// cout << mp[i] << ' ' <<LL mp[j] << ' ' << mp[k] << endl;
                        // cout << i << ' ' << j << ' ' << k << endl;
                        cout << "YES" << endl;
                        return ;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}