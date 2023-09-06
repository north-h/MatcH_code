/*
Author : north_h
File : C.cpp
Time : 2023/8/5/10:32
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
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a)cin >> i;
    int MIN = 1, MAX = n;
    for (int i = 0, j = n - 1; i < j;) {
        bool ok1 = true, ok2 = true;
        if (a[i] == MIN)i++, MIN++, ok1 = false;
        if (a[j] == MIN)j--, MIN++, ok2 = false;
        if (a[i] == MAX)i++, MAX--, ok1 = false;
        if (a[j] == MAX)j--, MAX--, ok2 = false;
        if (ok1 && ok2) {
            cout << i + 1 << ' ' << j + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
