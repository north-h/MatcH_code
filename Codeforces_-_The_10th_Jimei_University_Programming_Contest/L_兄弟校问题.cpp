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
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int fa[N], S[N];

int find(int x) {
    if(fa[x] != x)find(fa[x]);
    return fa[x];
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)fa[i] = i, S[i] = 1;
    vector<vector<string>> g(n + 1), city(n + 1);
    for(int i = 1; i <= n; i++) {
        string a, b;
        cin >> a >> b;
        for(int j = 0; j < a.size(); j++) {
            if(a[j] >= 'a' && a[j] <= 'z')a[j] -= 32;
        }
        for(int j = 0; j < b.size(); j++) {
            if(b[j] >= 'a' && b[j] <= 'z')b[j] -= 32;
        }
        city[i].push_back(b);
        vector<int> c;
        for(int j = 0; j < a.size(); j++) {
            if(a[j] == '_') {
                c.push_back(j);
            }
        }
        string s = a.substr(0, c.front());
        // debug1(s);
        g[i].push_back(s);
        for(int j = 0; j < c.size() - 1; j++) {
            s = a.substr(c[j] + 1, c[j + 1] - c[j] - 1);
            // debug1(s);
            g[i].push_back(s);
        }
        s = a.substr(c.back() + 1);
        // debug1(s);
        g[i].push_back(s);
    }
    set<string> st;
    for(int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] >= 'a' && s[j] <= 'z')s[j] -= 32;
        }
        // debug1(s);
        st.insert(s);
    }


    vector<vector<string>> school(n + 1);
    vector<set<string>> sl(n + 1);
    for(int i = 1; i <= n; i++) {
        for(auto j : g[i]) {
            if(st.count(j)) {
                sl[i].insert(j);
                school[i].push_back(j);
            }
        }
    }
    // for(int i = 1; i <= n; i++) {
    //     for(auto j : school[i])cout << j << ' ';
    //     cout << endl;
    // }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(city[i] == city[j]) {
                int pi = find(i);
                int pj = find(j);
                if(pi != pj) {
                    fa[i] = j;
                    S[j] += S[i];
                }
            } else {
                for(int k = 0; k < school[i].size(); k++) {
                    if(sl[j].count(school[i][k])) {
                        int pi = find(i);
                        int pj = find(j);
                        if(pi != pj) {
                            fa[i] = j;
                            S[j] += S[i];
                            break;
                        }
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)cout << S[find(i)] - 1  << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}