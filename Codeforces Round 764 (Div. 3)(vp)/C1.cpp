/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-12 15:19:31
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
    vector<int> a(n), vis(n, false);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    sort(rALL(a));
    // for(auto i : a)cout << i << ' ';
    // cout << endl;
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < n; j++) {
            int m = a[j];
            bool ok = false;
            while(m && !vis[j]) {
                if(i == m) {
                    vis[j] = true;
                    cnt++;
                    ok = true;
                    break;
                }
                m /= 2;
            }
            if(ok)break;
        }
    }
    // cout << cnt << endl;
    if(cnt == n)cout << "YES" << endl;
    else cout << "NO" << endl;
 
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}