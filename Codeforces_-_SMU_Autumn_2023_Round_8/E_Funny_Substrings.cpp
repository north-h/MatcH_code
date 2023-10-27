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
#define int long long
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

struct S {
    string f, b;
    int cnt;
};
unordered_map<string, S> mp;

int get(string s) {
    int cnt = 0;
    for(int i = 3; i < s.size(); i++) {
        if(s[i] == 'a' && s[i - 1] == 'h' && s[i - 2] == 'a' && s[i - 3] == 'h')
            cnt++;
    }
    return cnt;
}

void fbcnt(string s, string name) {
    mp[name].cnt = get(s);
    if(s.size() <= 3) {
        mp[name].f = mp[name].b = s;
    } else {
        mp[name].f = s.substr(0, 3);
        mp[name].b = s.substr(s.size() - 3, 3);
    }
}

void merge(string name, string a, string b) {
    string s = mp[a].b + mp[b].f;
    mp[name].cnt = get(s) + mp[a].cnt + mp[b].cnt;
    if(s.size() <= 3) {
        mp[name].f = mp[name].b = s;
    } else {
        if(mp[a].f.size() >= 3)mp[name].f = mp[a].f;
        else mp[name].f = s.substr(0, 3);
        if(mp[b].b.size() >= 3)mp[name].b = mp[b].b;
        else mp[name].b = s.substr(s.size() - 3, 3);
    }
}

void solve() {
    mp.clear();
    int n;
    cin >> n;
    int ans = 0;
    while(n--) {
        string name, op;
        cin >> name >> op;
        if(op == ":=") {
            string s;
            cin >> s;
            fbcnt(s, name);
            ans = mp[name].cnt;
        } else {
            string a, b;
            char op;
            cin >> a >> op >> b;
            merge(name, a, b);
            ans = mp[name].cnt;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}