/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-01 22:06:42
 *
 * Problem: A. Binary String Reconstruction
 * Contest: Codeforces - SMU Autumn 2023 Trial 26
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/481918/problem/A
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
    string s;
    cin >> s;
    vector<int> ans(s.size() + 1, -1);
    s = " " + s;
    int x;
    cin >> x;
    for(int i = 1; i < s.size(); i++) {
        int p1 = i - x;
        int p2 = i + x;
        debug2(p1, p2);
        if(s[i] == '1') {
            if(p1 < 1) {
                if(ans[p2] != -1 && ans[p2] ) {
                    cout << -1 << endl;
                    return ;
                } else ans[p2] = 1;
            } else if(p2 >= s.size()) {
                if(ans[p1] != -1 && ans[p1] != 1) {
                    cout << -1 << endl;
                    return ;
                } else ans[p1] = 1;
            } else {
                if(ans[p1] == 1 || ans[p1] == -1)ans[p1] = 1;
                else {
                    if(ans[p2] == -1)ans[p2] = 1;
                    else {
                        cout << -1 << endl;
                        return ;
                    }
                }
            }
        } else {
            if(p1 < 1) {
                if(ans[p2] != -1 && ans[p2] == 1) {
                    cout << -1 << endl;
                    return ;
                } else ans[p2] = 0;
            } else if(p2 >= s.size()) {
                if(ans[p1] != -1 && ans[p1] == 1) {
                    cout << -1 << endl;
                    return ;
                } else ans[p1] = 0;
            } else {
                if(ans[p1] == 0 || ans[p1] == -1)ans[p1] = 0;
                else {
                    if(ans[p2] == -1)ans[p2] = 0;
                    else {
                        cout << -1 << endl;
                        return ;
                    }
                }
            }
        }
    }
    for(int i = 1; i < ans.size(); i++)cout << ans[i];
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}