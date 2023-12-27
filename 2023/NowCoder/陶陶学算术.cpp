/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-18 18:41:36
 *
 * Problem: 陶陶学算术
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/69791/C
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
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
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

vector<PII> get(int x) {
    vector<PII> a;
    for(int i = 2; i <= x / i; i++) {
        if(x % i == 0) {
            int cnt = 0;
            while(x % i == 0)x /= i, cnt++;
            a.push_back({i, cnt});
        }
    }
    if(x > 1)a.push_back({x, 1});
    return a;
}

void solve() {
    int n, cn = 0;
    cin >> n;
    map<int, int> mp;
    while(n--) {
        int op, x;
        cin >> op >> x;
        if(x < 0)cn++, x = abs(x);
        vector<PII> res = get(x);
        if(op == 1)for(auto [x, y] : res)mp[x] += y;
        else for(auto [x, y] : res)mp[x] -= y;
    }
    int m, cm = 0;
    cin >> m;
    while(m--) {
        int op, x;
        cin >> op >> x;
        if(x < 0)cm++, x = abs(x);
        vector<PII> res = get(x);
        if(op == 1)for(auto [x, y] : res)mp[x] -= y;
        else for(auto [x, y] : res)mp[x] += y;
    }
    if(cn % 2 != cm % 2) {
        cout << "NO" << endl;
        return ;
    }
    for(auto [x, y] : mp) {
        if(y != 0) {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}