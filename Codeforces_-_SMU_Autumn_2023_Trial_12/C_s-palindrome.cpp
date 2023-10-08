/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-08 13:31:42
 *
 * Problem: C. s-palindrome
 * Contest: Codeforces - SMU Autumn 2023 Trial 12
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475602/problem/C
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
    string s;
    cin >> s;
    if(s.size() == 1 && (s != "o" && s != "O" && s != "X" && s != "x" && s != "V" &&
                         s != "v" && s != "U" && s != "A" && s != "I" && s != "H" && s != "M" &&
                         s != "Y" && s != "T" && s != "W" && s != "w")) {
        cout << "NIE" << endl;
        return ;
    }
    for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
        // if(s[i] == s[j])continue;
        if(s[i] == 'p' && s[j] == 'q')continue;
        if(s[i] == 'q' && s[j] == 'p')continue;
        if(s[i] == 'b' && s[j] == 'd')continue;
        if(s[i] == 'd' && s[j] == 'b')continue;
        if(s[i] == 'o' && s[j] == 'o')continue;
        if(s[i] == 'O' && s[j] == 'O')continue;
        if(s[i] == 'X' && s[j] == 'X')continue;
        if(s[i] == 'x' && s[j] == 'x')continue;
        if(s[i] == 'V' && s[j] == 'V')continue;
        if(s[i] == 'v' && s[j] == 'v')continue;
        if(s[i] == 'U' && s[j] == 'U')continue;
        if(s[i] == 'A' && s[j] == 'A')continue;
        if(s[i] == 'I' && s[j] == 'I')continue;
        if(s[i] == 'H' && s[j] == 'H')continue;
        if(s[i] == 'M' && s[j] == 'M')continue;
        // if(s[i] == 'm' && s[j] == 'm')continue;
        // if(s[i] == 'n' && s[j] == 'n')continue;
        if(s[i] == 'Y' && s[j] == 'Y')continue;
        if(s[i] == 'T' && s[j] == 'T')continue;
        if(s[i] == 'w' && s[j] == 'w')continue;
        if(s[i] == 'W' && s[j] == 'W')continue;
        cout << "NIE" << endl;
        return ;
    }
    string op = "";
    op += s[s.size() / 2];
    // debug1(op);
    if(s.size() & 1 && op != "o" && op != "O" && op != "X" && op != "x" &&
            op != "V" && op != "v" && op != "U" && op != "A" && op != "I" &&
            op != "H" && op != "M" && op != "Y" && op != "T" && op != "W" && op != "w")
        cout << "NIE" << endl;
    else cout << "TAK" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}