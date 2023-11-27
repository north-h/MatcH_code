/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-26 15:44:10
 *
 * Problem: 我爱贵工程
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/69246/G
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

void solve() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    while(n--) {
        getline(cin, s);
        // debug1(s);
        map<char, int> mp;
        for(auto j : s) {
            if(j >= '0' && j <= '9')mp[j]++;
        }
        int ans = 0;
        char op;
        int cnt = 0;
        char o1 = '0';
        for(auto [x, y] : mp) {
            if(x == o1) {
                o1++;
                cnt++;
            } else break;
        }
        for(auto [x, y] : mp) {
            if(ans < y) {
                ans = y;
                op = x;
            } else if(ans == y) {
                if(x < op) {
                    op = x;
                }
            }
        }
        cout << op << ' ' << ans << endl;;
        if(cnt == 10)cout << "I Love GUES！" << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}