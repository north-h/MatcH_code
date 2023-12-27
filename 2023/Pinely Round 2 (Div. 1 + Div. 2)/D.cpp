/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-31 15:54:45
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<char>> b(n, vector<char>(m, '.'));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        int res = 0;
        vector<int> ans;
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'U' ) {
                res++;
                ans.push_back(j);
            }
        }
        if(res % 2 != 0) {
            cout << -1 << endl;
            return ;
        }
        for(int j = 0; j < ans.size() / 2; j++)b[i][ans[j]] = 'B', b[i + 1][ans[j]] = 'W';
        for(int j = ans.size() / 2; j < ans.size(); j++)b[i][ans[j]] = 'W', b[i + 1][ans[j]] = 'B';
    }
    for(int j = 0; j < m; j++) {
        int res = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(a[i][j] == 'L') {
                res++;
                ans.push_back(i);
            }
        }
        if(res % 2 != 0) {
            cout << -1 << endl;
            return ;
        }
        for(int i = 0; i < ans.size() / 2; i++)b[ans[i]][j] = 'B', b[ans[i]][j + 1] = 'W';
        for(int i = ans.size() / 2; i < ans.size(); i++)b[ans[i]][j] = 'W', b[ans[i]][j + 1] = 'B';
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << b[i][j];
        }
        cout << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}