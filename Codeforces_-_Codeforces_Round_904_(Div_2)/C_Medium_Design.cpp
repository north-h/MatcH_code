/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-02 15:27:34
 *
 * Problem: C. Medium Design
 * Contest: Codeforces - Codeforces Round 904 (Div. 2)
 * URL:     https://codeforces.com/problemset/problem/1884/C
 * MemoryL: 256 MB
 * TimeL:   3000 ms
 * ===========================================================================
 */
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define int long long
#define fi first
#define se second
#define PII pair<int,int>
#define PI acos(-1)
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 100010;
const int M = 110;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<PII > seg;
    vector<int> l, r;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        seg.push_back({x, y});
        if (x != 1) {
            l.push_back(x);
            l.push_back(y);
        }
        if (y != m) {
            r.push_back(x);
            r.push_back(y);
        }
    }
    sort(l.begin(), l.end());
    l.erase(unique(l.begin(), l.end()), l.end());
    // debug1(l.size());
    vector<int> s(n * 2 + 10);
    for (int i = 0; i < n; i++) {
        if (seg[i].fi == 1)continue;
        auto ll = lower_bound(l.begin(), l.end(), seg[i].fi) - l.begin() + 1;
        auto rr = lower_bound(l.begin(), l.end(), seg[i].se) - l.begin() + 1;
        s[ll]++;
        s[rr + 1]--;
    }
    int ans = 0;
    for (int i = 1; i < s.size(); i++) {
        s[i] += s[i - 1];
        ans = max(ans, s[i]);
    }
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    for(auto &i : s)i = 0;
    for (int i = 0; i < n; i++) {
        if (seg[i].se == m)continue;
        auto ll = lower_bound(r.begin(), r.end(), seg[i].fi) - r.begin() + 1;
        auto rr = lower_bound(r.begin(), r.end(), seg[i].se) - r.begin() + 1;
        s[ll]++;
        s[rr + 1]--;
    }
    for (int i = 1; i < s.size(); i++) {
        s[i] += s[i - 1];
        ans = max(ans, s[i]);
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