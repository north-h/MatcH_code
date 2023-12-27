/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-04 11:55:57
 *
 * Problem: A. Vasya and Robot
 * Contest: Codeforces - SMU Autumn 2023 Trial 29
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/484045/problem/A
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
    int n, sx, sy;
    string s;
    cin >> n >> s >> sx >> sy;
    s = " " + s;
    vector<int> u(n + 1), d(n + 1), r(n + 1), l(n + 1);
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == 'U')u[i]++;
        u[i] += u[i - 1];
        if(s[i] == 'D')d[i]++;
        d[i] += d[i - 1];
        if(s[i] == 'R')r[i]++;
        r[i] += r[i - 1];
        if(s[i] == 'L')l[i]++;
        l[i] += l[i - 1];
    }
    auto check = [&](int mid) {
        for(int i = 1; i + mid - 1 <= n; i++) {
            int U = u[i - 1] + (u[n] - u[i + mid - 1]);
            int D = d[i - 1] + d[n] - d[i + mid - 1];
            int R = r[i - 1] + r[n] - r[i + mid - 1];
            int L = l[i - 1] + l[n] - l[i + mid - 1];
            int x = R - L;
            int y = U - D;
            // debug2(x, y);
            int res = abs(sx - x) + abs(sy - y);
            // debug2(res, mid);
            if(res <= mid && (mid - res) % 2 == 0)return true;
        }
        return false;
    };
    int li = 0, ri = n, ans = -1;
    while(li <= ri) {
        int mid = li + ri >> 1;
        if(check(mid))ri = mid - 1, ans = mid;
        else li = mid + 1;
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}

