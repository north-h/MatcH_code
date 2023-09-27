/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-26 22:36:45
 *
 * Problem: D. Reverse Madness
 * Contest: Codeforces - Codeforces Round 900 (Div. 3)
 * URL:     https://codeforces.com/contest/1878/problem/D
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
    int n, m;
    string s;
    cin >> n >> m >> s;
    s = " " + s;
    vector<int> l(m + 1), r(m + 1);
    for(int i = 1; i <= m; i++)cin >> l[i];
    for(int i = 1; i <= m; i++)cin >> r[i];
    int q;
    cin >> q;
    vector<PII> lr;
    for(int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        int li = 1, ri = m, ans;
        while(li <= ri) {
            int mid = li + ri >> 1;
            if(r[mid] >= x)ri = mid - 1, ans = mid;
            else li = mid + 1;
        }
        lr.push_back({min(x, l[ans] + r[ans] - x), max(x, l[ans] + r[ans] - x)});
    }
    sort(ALL(lr));
    vector<int> c(n + 10, 0), ss(n + 10, 0);
    for(auto [l, r] : lr) {
        c[l]++;
        c[r + 1]--;
    }
    for(int i = 1; i <= n; i++) {
        ss[i] = ss[i - 1] + c[i];
    }
    vector<PII> ans;
    auto &[li, ri] = lr[0];
    for(int i = 1; i < lr.size(); i++) {
        if(lr[i].fi > ri) {
            ans.push_back({li, ri});
            li = lr[i].fi;
            ri = lr[i].se;
        } else {
            li = min(li, lr[i].fi);
            ri = max(ri, lr[i].se);
        }
    }
    ans.push_back({li, ri});
    for(auto [l, r] : ans) {
        for(int i = l; i <= (l + r) / 2; i++) {
            if(ss[i] % 2)swap(s[i], s[l + r - i]);
        }
    }
    cout << s.substr(1) << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}