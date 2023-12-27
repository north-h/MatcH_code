/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-14 14:01:49
 *
 * Problem: C. Magic Ship
 * Contest: Codeforces - SMU Autumn 2023 Trial 14
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/478090/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> dx(n + 1), dy(n + 1);
    for (int i = 1; i <= n; i++) {
        dx[i] = dx[i - 1];
        dy[i] = dy[i - 1];
        if (s[i] == 'U')dy[i]++;
        else if (s[i] == 'D')dy[i]--;
        else if (s[i] == 'L')dx[i]--;
        else dx[i]++;
    }
    auto check = [&](int x) -> bool {
        int day = x / n;
        int days = x % n;
        int xx = x1 + dx[n] * day + dx[days];
        int yy = y1 + dy[n] * day + dy[days];
        int dx = abs(xx - x2);
        int dy = abs(yy - y2);
        int res = dx + dy;
        return res <= x;
    };
    int ll = 0, rr = 1e15, ans = -1;
    while (ll <= rr) {
        int mid = ll + rr >> 1;//二分天数
        // cout << ll << ' ' << rr << endl;
        if (check(mid))rr = mid - 1, ans = mid;
        else ll = mid + 1;
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