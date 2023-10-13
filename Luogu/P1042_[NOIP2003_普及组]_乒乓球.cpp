/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-13 19:08:50
 *
 * Problem: P1042 [NOIP2003 普及组] 乒乓球
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P1042
 * MemoryL: 128 MB
 * TimeL:   1000 ms
 * ===========================================================================
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
#define PI acos(-1)
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s, str;
    while(cin >> str) {
        s += str;
    }
    // cin >> s >> str;
    // s += str;
    int W = 0, L = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'W')W++;
        else if(s[i] == 'L')L++;
        else  {
            cout << W << ':' << L << endl;
            cout << endl;
            break;
        }
        // debug2(L, W);
        if((W >= 11 || L >= 11) && abs(W - L) >= 2) {
            cout << W << ':' << L << endl;
            W = L = 0;
        }
    }

    W = L = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'W')W++;
        else if(s[i] == 'L')L++;
        else {
            cout << W << ':' << L << endl;
            break;
        }
        if((W >= 21 || L >= 21) && abs(W - L) >= 2) {
            cout << W << ':' << L << endl;
            W = L = 0;
        }
    }

}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}