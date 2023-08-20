//
//  Author : north_h
//  File : C.cpp
//  Time : 2023/7/21/12:38
//                  _   _         _     
// _ __   ___  _ __| |_| |__     | |__  
//| '_ \ / _ \| '__| __| '_ \    | '_ \ 
//| | | | (_) | |  | |_| | | |   | | | |
//|_| |_|\___/|_|   \__|_| |_|___|_| |_|
//                          |_____|     

//#pragma GCC optimize(3)
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
const int N = 100010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

inline int read() {
    int x = 0, f = 1, ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x * f;
}
struct S{
    int a, b, c;
}a[N];
//int a[N];
//int a[N];
bool cmp(S c,S d){
    return c.c>d.c;
}

void solve() {
    int n, m;
    cin >> n >> m;

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
//        int x,y;
//        cin>>x>>y;
//        a[i].c = x - y;
//        sum += x;
        cin>>a[i].a>>a[i].b;
        a[i].c = a[i].a - a[i].b;
        sum += a[i].a;
    }
    if (sum <= m) {
        cout << 0 << endl;
        return;
    }
    sort(a+1, a+n+1, cmp);
    for (int i = 1; i <= n; i++) {
        if (sum - a[i].c <= m) {
            cout << i << endl;
            return;
        }
        sum -= a[i].c;
    }
    cout << -1 << endl;
}

int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}
