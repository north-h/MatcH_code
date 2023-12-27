/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-04 10:14:02
 *
 * Problem: C. Simple Subset
 * Contest: Codeforces - SMU Autumn 2023 Trial 8
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475594/problem/C
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

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
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 2000010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

bool vis[N];

void solve() {
    int n;
    cin >> n;
    vector<int> a, b;
    int cnt = 0;
    int res = -1;
    int re = 0;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        if(x == 1)cnt++;
        re = x;
        if(!vis[x + 1] && x != 1)res = x;
        if(x & 1)a.push_back(x);
        else b.push_back(x);
    }
    int aa = -1, bb = -1;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            if(!vis[a[i] + b[j]]) {
                aa = a[i];
                bb = b[j];
                break;
            }
        }
    }
    int ans = 1;
    if(aa != -1 && bb != -1)ans = max(ans, 2);
    ans = max(ans, cnt);
    if(res != -1)ans = max(ans, cnt + 1);
    // debug2(ans, res);
    if(ans == 1) {
        cout << 1 << endl;
        cout << re << endl;
    } else if(ans == 2 && aa != -1 && bb != -1) {
        cout << 2 << endl;
        cout << aa << ' ' << bb << endl;
    } else if(ans == cnt) {
        cout << cnt << endl;
        while(cnt--)cout << 1 << ' ';
        cout << endl;
    } else {
        cout << cnt + 1 << endl;
        while(cnt--)cout << 1 << ' ';
        cout << res << endl;
    }
}

int32_t main() {
    vis[0] = vis[1] = true;
    for(int i = 2; i * i < N; i++) {
        if(vis[i])continue;
        for(int j = i + i; j < N; j += i) {
            vis[j] = true;
        }
    }
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}