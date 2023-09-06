/*
 * =====================================
 * Author : north_h
 * Time : ctrl+shift+t
 * =====================================
 * Thirty years east, thirty years west,
 * don't you dare bully me because I'm poor now.
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
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(n), b(m), ans;
    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;
    int i, j;
    for(i = 0, j = 0; i < a.size() && j < b.size();) {
        while(a[i] <= b[j] && i < a.size()) {
            if(k < a[i] ) {
                cout << -1 << endl;
                return ;
            }
            ans.push_back(a[i]);
            if(a[i] == 0)k++;
            i++;
        }
        if(i == a.size())break;
        while(a[i] > b[j] && j < b.size()) {
            if(k < b[j]) {
                cout << -1 << endl;
                return ;
            }
            ans.push_back(b[j]);
            if(b[j] == 0)k++;
            j++;
        }
        if(j == b.size())break;
    }
    // cout << i << ' ' << j << endl;
    // cout << ans.size() << endl;
    for(int l = i; l < a.size(); l++) {
        if(k < a[l]) {
            cout << -1 << endl;
            return ;
        }
        if(a[l] == 0)k++;
        ans.push_back(a[l]);
    }
    for(int l = j; l < b.size(); l++) {
        if(k < b[l]) {
            cout << -1 << endl;
            return ;
        }
        if(b[l] == 0)k++;
        ans.push_back(b[l]);
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