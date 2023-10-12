/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-09 13:45:21
 *
 * Problem: C. Exponential notation
 * Contest: Codeforces - SMU Autumn 2023 Trial 13
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475604/problem/C
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
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int get(int x) {
    int ans = 0;
    while(x) {
        ans++;
        x /= 10;
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    while(s.back() == '0')s.pop_back();
    reverse(ALL(s));
    while(s.back() == '0')s.pop_back();
    reverse(ALL(s));
    cout << s << endl;
    int pos;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '.') {
            pos = i;
            break;
        }
    }
    int pre = 0;
    int post = 0;
    for(int i = 0; i < pos; i++)pre = pre * 10 + (s[i] - '0');
    for(int i = pos + 1; i < s.size(); i++)post = post * 10 + (s[i] - '0');
    int len = 0;
    for(int i = pos + 1; i < s.size(); i++) {
        if(s[i] == '0')len++;
        else break;
    }
    string str = s.substr(0, pos + 1);
    if(pre != 0) {
        cout << s.substr(0, 1) << '.' << s.substr(2, pos - 2) << 'E' << str.size() - 1 << endl;
    } else {

    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}