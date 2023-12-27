/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-12 00:14:59
 *
 * Problem: G. Cleaning the Phone
 * Contest: Codeforces - SMU Autumn 2023 Round 6
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/476122/problem/G
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
    vector<PII > c(n);
    vector<int> a, b;
    for (int i = 0; i < n; i++)cin >> c[i].fi;
    for (int i = 0; i < n; i++)cin >> c[i].se;
    for (int i = 0; i < n; i++) {
        if (c[i].se == 1)a.push_back(c[i].fi);
        else b.push_back(c[i].fi);
    }
    sort(ALL(a));
    sort(ALL(b));
    //    for (auto i: a)cout << i << ' ';
    //    cout << endl;
    //    for (auto i: b)cout << i << ' ';
    //    cout << endl;
    int sum = 0, ans = 0;
    while (sum < m) {
        if (!a.size() && !b.size())break;
        int bb = 0, a1 = 0, a2 = 0;
        if (b.size()) {
            bb = b.back();
            b.pop_back();
        }
        if (a.size()) {
            a1 = a.back();
            a.pop_back();
        }
        if (sum + a1 >= m) {
            sum += a1;
            ans++;
            break;
        } else {
            if (a.size()) {
                a2 = a.back();
                a.pop_back();
            }
            int aa = a1 + a2;
            if (aa > bb) {
                b.push_back(bb);
                if (a2 != 0)a.push_back(a2);
                sum += a1;
                ans++;
            } else {
                if (a2 != 0)a.push_back(a2);
                if (a1 != 0)a.push_back(a1);
                sum += bb;
                ans += 2;
            }
        }
    }
    if (sum < m)cout << -1 << endl;
    else cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}