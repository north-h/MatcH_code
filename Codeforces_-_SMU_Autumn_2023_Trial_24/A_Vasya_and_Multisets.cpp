/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-27 17:42:16
 *
 * Problem: A. Vasya and Multisets
 * Contest: Codeforces - SMU Autumn 2023 Trial 24
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/481916/problem/A
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
#define debug3(a,b,c) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<' '<<#c<<'='<<c<<endl
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
    vector<int> a(n);
    unordered_map<int, int> up;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        up[a[i]]++;
    }
    int c1 = 0, c2 = 0, c3 = 0;
    for(auto [x, y] : up) {
        if(y == 1)c1++;
        else if(y == 2)c2++;
        else c3++;
    }
    // debug2(c1, c2);
    // debug3(c1, c2, c3);
    int res = c1 + c2 * 2;
    if(res & 1) {
        if(c3 > 0) {
            cout << "YES" << endl;
            char op = 'A';
            vector<char> ans(n);
            int goal;
            for(auto i : a) {
                if(up[i] > 2) {
                    goal = i;
                    break;
                }
            }
            for(int i = 0; i < n; i++) {
                if(up[a[i]] == 2) {
                    if(op == 'A')ans[i] = 'A', op = 'B';
                    else ans[i] = 'B', op = 'A';
                }
            }
            bool ok = true;
            for(int i = 0; i < n; i++) {
                if(a[i] == goal) {
                    // debug1(i);
                    if(ok)ans[i] = 'A', ok = false;
                    else ans[i] = 'B';
                } else if(up[a[i]] > 2)ans[i] = 'A';
            }
            op = 'B';
            for(int i = 0; i < n; i++) {
                if(up[a[i]] == 1) {
                    if(op == 'A')ans[i] = 'A', op = 'B';
                    else ans[i] = 'B', op = 'A';
                }
            }
            for(auto i : ans)cout << i;
            cout << endl;
        } else cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        char op = 'A';
        for(int i = 0; i < n; i++) {
            if(up[a[i]] == 1) {
                if(op == 'A')cout << 'A', op = 'B';
                else cout << 'B', op = 'A';
            } else cout << 'A';
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}

// ABABAABAAABA
// 1234556667911
// BABAABABBBAB