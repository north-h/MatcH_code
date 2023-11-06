/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-05 12:53:28
 *
 * Problem: L. 兄弟校问题
 * Contest: Codeforces - The 10th Jimei University Programming Contest
 * URL:     https://codeforces.com/gym/104741/problem/L
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
const int N = 200010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int fa[N], S[N];

int find(int x) {
    if(fa[x] != x)fa[x] = find(fa[x]);
    return fa[x];
}

void tow(string &s) {
    for(int j = 0; j < s.size(); j++) {
        if(s[j] >= 'A' && s[j] <= 'Z')s[j] += 32;
    }
}

void solve() {
    map<string, int> city, key;
    int n, m;
    cin >> n >> m;
    int idx = 1;
    for(int i = 1; i <= n; i++)fa[i] = i, S[i] = 1;
    vector<string> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        if(city[b[i]] == 0)city[b[i]] = idx++;
    }
    for(int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        if(key[s] == 0)key[s] = idx++;
    }
    // for(auto [x, y] : city)cout << x << ' ' << y << endl;
    // cout << endl;
    // for(auto [x, y] : key)cout << x << ' ' << y << endl;
    for(int i = 1; i <= n; i++) {
        tow(a[i]);
        // debug1(a[i]);
        for(auto [x, y] : key) {
            if(a[i].find(x) != -1) {
                int pcity = find(city[b[i]]);
                int pkey = find(y);
                if(pkey != pcity) {
                    fa[pkey] = pcity;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            // debug2(city[b[i]], city[b[j]]);
            if(i == j)continue;
            int pi = find(city[b[i]]);
            int pj = find(city[b[j]]);
            if(b[i] == b[j]) {
                fa[pi] = pj;
                S[pj] + S[pi];
            }
        }
    }
    for(int i = 1; i <= n; i++)cout << S[find(city[b[i]])] - 1 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}