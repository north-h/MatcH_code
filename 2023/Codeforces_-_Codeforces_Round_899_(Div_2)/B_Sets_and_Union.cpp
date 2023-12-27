/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-25 22:35:39
 *
 * Problem: B. Sets and Union
 * Contest: Codeforces - Codeforces Round 899 (Div. 2)
 * URL:     https://codeforces.com/contest/1882/problem/B
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
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug(a) cout << #a << '=' << a << endl;
#define lf(x)   fixed << setprecision(x)
const double PI = 3.1415926;
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<set<int>> a(n);
    set<int> st;
    for(int i = 0, k; i < n; i++) {
        cin >> k;
        while(k--) {
            int x;
            cin >> x;
            a[i].insert(x);
            st.insert(x);
        }
    }
    int ans = 0;
    for(auto i : st) {
        set<int> t;
        for(int j = 0; j < n; j++) {
            if(!a[j].count(i)) {
                for(auto k : a[j])t.insert(k);
            }
        }
        ans = max(ans, (int)t.size());
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