/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-10 13:00:35
 *
 * Problem: B. All Possible Digits
 * Contest: Codeforces - SMU Autumn 2023 Round 7
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/478437/problem/B
 * MemoryL: 256 MB
 * TimeL:   3000 ms
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
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for(auto &i : a) {
        cin >> i;
        if(i == 0)i = p;
    }
    set<int> pre, post;
    for(auto i : a) {
        if(i < a.back())pre.insert(i);
        if(i > a.back())post.insert(i);
    }
    // for(auto i : pre)cout << i << ' ';
    // cout << endl;
    // for(auto i : post)cout << i << ' ';
    // cout << endl;
    int le = pre.size();
    int lt = post.size();
    // debug2(le, lt);
    if(le + lt + 1 == p) {
        cout << 0 << endl;
        return ;
    }
    // set<int> se, st;
    // if(se.size())mxe = *max_element(ALL(se));
    // if(st.size())mxt = *max_element(ALL(st));
    int ans = 0;
    int mxe = -1, mxt = -1;
    for(int i = 1; i < a.back(); i++) {
        if(!pre.count(i))mxe = max(mxe, i);
    }
    for(int i = a.back() + 1; i <= p; i++) {
        if(!post.count(i))mxt = max(mxt, i);
    }
    debug2(mxe, mxt);
    if(mxe == -1 && mxt != -1) {
        ans += mxt - a.back();
    } else {
        ans += p - a.back() + mxe;
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