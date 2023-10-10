/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-10 13:00:53
 *
 * Problem: F. Lost Permutation
 * Contest: Codeforces - SMU Autumn 2023 Round 7
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/478437/problem/F
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
    int m, s;
    cin >> m >> s;
    vector<int> a(m);
    set<int> st;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    int mx = *max_element(ALL(a));
    // debug1(mx);
    int sum = 0;
    for(int i = 1; i <= mx; i++) {
        if(!st.count(i)) {
            sum += i;
        }
    }
    // debug1(sum);
    if(sum == s) {
        cout << "YES" << endl;
        return ;
    } else if(sum > s) {
        cout << "NO" << endl;
        return ;
    }
    for(int i = mx + 1;; i++) {
        sum += i;
        // debug1(sum);
        if(sum == s) {
            cout << "YES" << endl;
            return ;
        } else if(sum > s) {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "NO" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}