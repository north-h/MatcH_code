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
    getline(cin, s);
    int ans = 0;
    for(int k = 1; k <= n; k++) {
        getline(cin, s);
        bool ok = true;
        int pos = -1;
        int p1 = -1;
        int p2 = -1;
        // debug1(s);
        for(int i = 0; i < s.size(); i++) {
            // cout << s[i];
            if(s[i] == ':')pos = i;
            if(s[i] == '=')p1 = i;
            if(s[i] == '+')p2 = i;
        }
        // cout << endl;
        // debug1(pos);
        auto get = [&](string s) {
            int cnt = 0;
            for(int i = 3; i < s.size(); i++) {
                if(s[i] == 'a' && s[i - 1] == 'h' && s[i - 2] == 'a' && s[i - 3] == 'h')cnt++;
            }
            return cnt;
        };
        // debug1(pos);
        if(s.find(":", 0) == -1) {
            // debug2(p1, p2);
            // cout << s << endl;
            key = s.substr(0, p1 - 1);
            string goal = key;
            string s1 = mp[key];
            // debug1(key);
            key = s.substr(p1 + 2, p2 - p1 - 3);
            string s2 = mp[key];
            // debug1(key);
            key = s.substr(p2 + 2);
            string s3 = mp[key];
            // debug1(key);
            // cout << "------------" << endl;
            // cout << s2 << ' ' << s3 << endl;
            int x2 = pp[s2];
            int x3 = pp[s3];
            debug2(s2, s3);
            string str;
            if(s2.size() <= 3)str += s2;
            else str += s2.substr(s2.size() - 3, 3);
            if(s3.size() <= 3)str += s3;
            else str += s3.substr(0, 3);
            int x = get(str);
            debug2(x, str);
            pp[goal] = x + x2 + x3;
            mp[goal] = str;
            ans = x + x2 + x3;
            // debug1(ans);
        } else {
            string key = s.substr(0, pos - 1);//变量名
            string val = s.substr(pos + 3);//变量值
            // debug2(key, val);
            mp[key] = val;
            pp[key] = get(val);

            // for(auto [x, y] : pp)cout << x << ' ' << y << endl;
        }
    }
    cout << ans << endl;
    // cout << s << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}