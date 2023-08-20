/*
   Author : north_h
   File : C.cpp
   Time : 2023/7/20/7:30
                  _   _         _     
 _ __   ___  _ __| |_| |__     | |__  
| '_ \ / _ \| '__| __| '_ \    | '_ \ 
| | | | (_) | |  | |_| | | |   | | | |
|_| |_|\___/|_|   \__|_| |_|___|_| |_|
                          |_____|
 */

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
#define int128 __int128
#define  a_ a a.begin(),a.end()
#define endl '\n'
const int N = 200010;
const int M = 110;
const int MOD = 1e9 + 7;
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0), last(n + 1, 0), first(n + 1, 0), second(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int len = i - last[a[i]] - 1;
        if (len > first[a[i]]) {
            second[a[i]] = first[a[i]];
            first[a[i]] = len;
        } else if (len > second[a[i]]) {
            second[a[i]] = len;

        }
        last[a[i]] = i;
    }
//    for(int i=1;i<=m;i++)cout<<last[i]<<' ';cout<<endl;
//    for(int i=1;i<=m;i++)cout<<first[i]<<' ';cout<<endl;
//    for(int i=1;i<=m;i++)cout<<second[i]<<' ';cout<<endl;
    for (int i = 1; i <= m; i++) {
        int len = n - last[i];
        if (len > first[i]) {
            second[i] = first[i];
            first[i] = len;
        } else if (len > second[i]) {
            second[i] = len;
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= m; i++) {
        ans = min(max(first[i] / 2, second[i]), ans);
    }
    cout << ans << endl;
}

int main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}