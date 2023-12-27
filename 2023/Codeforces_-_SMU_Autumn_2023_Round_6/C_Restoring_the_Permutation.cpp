/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-12 00:14:42
 *
 * Problem: C. Restoring the Permutation
 * Contest: Codeforces - SMU Autumn 2023 Round 6
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/476122/problem/C
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    vector<PII> b;
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i - 1])cnt++;
        else b.push_back({a[i - 1], cnt}), cnt = 0;
    }
    b.push_back({a[n - 1], cnt});
    // for(auto [x, y] : b)cout << x << ' ' << y << endl;
    // cout << endl;
    // if(n == 1)b.push_back({a[0], 1});
    set<int> p1, p2;
    for(int i = 1; i <= n; i++) {
        if(!st.count(i))p1.insert(i);
    }
    p2 = p1;
    vector<int> ans1, ans2;
    // for(auto i : p1)cout << i << ' ';
    // cout << endl;
    for(int i = 0; i < b.size(); i++) {
        ans1.push_back(b[i].fi);
        auto l = p1.begin();
        for(int j = 0; j < b[i].se; j++) {
            ans1.push_back(*l);
            l++;
            p1.erase(ans1.back());
        }
    }
    for(int i = 0; i < b.size(); i++) {
        ans2.push_back(b[i].fi);
        auto r = p2.lower_bound(b[i].fi);
        if(r != p2.begin())r--;
        // r--;
        for(int j = 0; j < b[i].se; j++) {
            ans2.push_back(*r);
            r--;
            p2.erase(ans2.back());
        }
    }
    for(auto i : ans1)cout << i << ' ';
    cout << endl;
    for(auto i : ans2)cout << i << ' ';
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}