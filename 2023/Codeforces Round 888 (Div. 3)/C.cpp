/*
    Author : north_h
    File : C.cpp
    Time : 2023/7/26/12:53
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
    map<int, int> mp;
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    int now = a[1];
    int cnt = 0;
    bool ok = false;
    bool f = false;
    for (int i = 1; i <= n; i++) {
        if (a[i] == now)cnt++;
        if (cnt == k && !ok) {
            now = a[n];
            cnt = 0;
            ok = true;
            if (i == n || (i != n && a[n] == a[i])) {
                cout << "YES" << endl;
                return;
            }
            //cout<<i<<endl;
        }
        else if (cnt == k && ok && !f) {
            f = true;
        }
    }
    if (ok && f)cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
