/*
Author : north_h
File : D.cpp
Time : 2023/7/28/13:01
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
    int m1 = 0, m2 = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i], m1 = max(m1, a[i]);
    int m;
    cin >> m;
    vector<PII > b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i].fi >> b[i].se;
        m2 = max(m2, b[i].fi);
    }
    if (m1 > m2) {
        cout<<-1<<endl;
        return;
    }
    sort(ALL(b));
    for (int i = m - 2; i >= 0; i--)b[i].se = max(b[i + 1].se, b[i].se);
    int ans = 1;
    int killed = 0;
    int mins = INF;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(ALL(b), PII(a[i], -INF)) - b.begin();
        mins = min(mins, b[pos].se);
        //cout << pos << ' ' << mins <<endl;
        if (mins < i - killed + 1) {
            ans++;
            killed = i;
            mins = b[pos].se;
        }
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
