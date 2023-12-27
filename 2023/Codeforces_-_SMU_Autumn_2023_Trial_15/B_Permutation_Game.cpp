/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-16 12:46:54
 *
 * Problem: B. Permutation Game
 * Contest: Codeforces - SMU Autumn 2023 Trial 15
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/478091/problem/B
 * MemoryL: 256 MB
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    vector<int> b(n + 1, 0);
    set<int> st;
    for(int i = 1; i < m; i++) {
        if(a[i - 1] < a[i]) {
            // b.push_back(a[i] - a[i - 1]);
            if(b[a[i - 1]] != 0 && b[a[i - 1]] != a[i] - a[i - 1]) {
                cout << -1 << endl;
                return ;
            }
            b[a[i - 1]] = a[i] - a[i - 1];
            st.insert(a[i] - a[i - 1]);
        } else {
            // b.push_back(n - a[i - 1] + a[i]);
            if(b[a[i - 1]] != 0 && b[a[i - 1]] != n - a[i - 1] + a[i]) {
                cout << -1 << endl;
                return ;
            }
            b[a[i - 1]] = n - a[i - 1] + a[i];
            st.insert(n - a[i - 1] + a[i]);
        }
    }
    // for(int i = 1; i <= n; i++)cout << b[i] << ' ';
    // cout << endl;
    vector<int> d;
    for(int i = 1; i <= n; i++) {
        if(!st.count(i))d.push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        if(b[i] == 0) {
            b[i] = d.back();
            d.pop_back();
        }
    }
    vector<int> c = b;
    sort(ALL(c));
    for(int i = 1; i <= n; i++) {
        if(c[i] != i) {
            cout << -1 << endl;
            return ;
        }
    }
    for(int i = 1; i <= n; i++)cout << b[i] << ' ';
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}