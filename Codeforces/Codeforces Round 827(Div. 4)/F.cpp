/*
   Author : north_h
   File : F.cpp
   Time : 2023/8/3/22:51
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
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s = "a", t = "a";
    map<char, int> mps, mpt;
    mps['a']++;
    mpt['a']++;
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        string str;
        cin >> n >> k >> str;
        for (auto i: str) {
            if (n == 1)mps[i] += k;
            if (n == 2)mpt[i] += k;
        }
        char opt = 'a';
        char ops = 'a';
        for (auto [x, y]: mpt)opt = max(opt, x);
        for (auto [x, y]: mps)ops = max(ops, x);
        if (opt == 'a') {
            if (ops != 'a')cout << "NO" << endl;
            else {
                if (mps['a'] < mpt['a'])cout << "YES" << endl;
                else cout << "NO" << endl;
            }

        } else cout << "YES" << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
