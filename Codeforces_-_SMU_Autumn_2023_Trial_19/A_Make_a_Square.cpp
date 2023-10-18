/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-18 10:56:45
 *
 * Problem: A. Make a Square
 * Contest: Codeforces - SMU Autumn 2023 Trial 19
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/479353/problem/A
 * MemoryL: 256 MB
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
const int N = 100010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> a;
    int x = n;
    while(x) {
        a.push_back(x % 10);
        x /= 10;
    }
    // for(auto i : a)cout << i << ' ';
    // cout << endl;
    for(int i = sqrt(n); i >= 1; i--) {
        int x = i * i;
        vector<int> b;
        int t = x;
        while(t) {
            b.push_back(t % 10);
            t /= 10;
        }
        int k = 0;
        for(int j = 0; j < a.size(); j++) {
            if(a[j] == b[k]) {
                k++;
                if(k == b.size())break;
            }
        }
        // debug1(k);
        if(k == b.size()) {
            cout << a.size() - b.size() << endl;
            return ;
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}