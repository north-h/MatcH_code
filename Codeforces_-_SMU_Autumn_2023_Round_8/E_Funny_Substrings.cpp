/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-24 22:17:12
 *
 * Problem: E. Funny Substrings
 * Contest: Codeforces - SMU Autumn 2023 Round 8
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/481465/problem/E
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    int n;
    cin >> n;
    map<string, string> mp;
    map<string, int> pp;
    string s, key, val;
    // getchar();
    for(int k = 1; k <= n + 1; k++) {
        getline(cin, s);
        bool ok = true;
        int pos = -1;
        int p1 = -1;
        int p2 = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ':')pos = i;
            else if(s[i] == '=')p1 = i;
            else if(s[i] == '+')p2 = i;
        }
        // debug1(pos);
        auto get = [&](string s) {
            int cnt = 0;
            for(int i = 1; i < s.size(); i++) {
                if(s[i - 1] == 'h' && s[i] == 'a')cnt++;
            }
            return cnt;
        };
        int ans = 0;
        debug1(pos);
        if(pos == -1) {
            string s1 = mp[s.substr(0, p1 - 2)];
            string s2 = mp[s.substr(p1 + 2, p2 - p1 - 1)];
            string s3 = mp[s.substr(p2 + 2)];
            // int x1 = pp[s2];
            // int x2 = pp[s3];
            // string str = s1.substr(0, 3) + s2.substr(s2.size() - 3, 3);
            // int x3 = get(str);
            // pp[str] = x1 + x2 + x3;
            // mp[s1] = str;
        } else {
            // string ss = s.substr(0, pos - 1);//变量名
            // string str = s.substr(pos + 3);//变量值
            // mp[ss] = str;
            // pp[ss] = get(str);

        }
    }
    for(auto [x, y] : mp)cout << x << ' ' << y << endl;
    // cout << s << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}