/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-05 12:52:42
 *
 * Problem: A. A+B问题
 * Contest: Codeforces - The 10th Jimei University Programming Contest
 * URL:     https://codeforces.com/gym/104741/problem/A
 * MemoryL: 512 MB
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

int get (int x, string s) {
    int cnt = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        int ans = 0;
        if(s[i] >= '0' && s[i] <= '9') {
            ans = s[i] - '0';
        }
        if(s[i] >= 'A' && s[i] <= 'Z') {
            ans = s[i] - 'A' + 10;
        }
        if(ans >= x) {
            cnt = -1;
            return cnt;
        }
        cnt += pow(x, s.size() - 1 - i) * ans;
    }
    return cnt;
}

void solve() {
    string a, b, s;
    cin >> a >> b >> s;
    for(int i = 2; i <= 16; i++) {
        int A = get(i, a);
        int B = get(i, b);
        int S = get(i, s);
        if(A + B == S && A >= 0 && B >= 0 && S >= 0) {
            cout << i << endl;
            return ;
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