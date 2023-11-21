/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-19 22:36:18
 *
 * Problem: A. Milica and String
 * Contest: Codeforces - Codeforces Round 910 (Div. 2)
 * URL:     https://codeforces.com/contest/1898/problem/A
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
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt = 0;
    for(auto i : s) {
        cnt += (i == 'B');
    }
    if(k == cnt) {
        cout << 0 << endl;
        return ;
    }
    for(int i = s.size() - 1, x = 0; i >= 0; i--) {
        if(x == k) {
            cout << 1 << endl;
            cout << i + 1 << ' ' << 'A' << endl;
            return ;
        }
        if(s[i] == 'B')x++;
    }
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'B') {
            if(cnt + i == k) {
                cout << 1 << endl;
                cout << i - 1 + 1 << ' ' << 'B' << endl;
                return ;
            }
            cnt--;
        } else {
            if(i + 1 + cnt == k) {
                cout << 1 << endl;
                cout << i + 1 << ' ' << 'B' << endl;
                return ;
            }
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}