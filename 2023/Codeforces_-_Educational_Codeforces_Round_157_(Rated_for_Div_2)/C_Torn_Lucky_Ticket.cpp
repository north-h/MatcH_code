/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-28 23:21:54
 *
 * Problem: C. Torn Lucky Ticket
 * Contest: Codeforces - Educational Codeforces Round 157 (Rated for Div. 2)
 * URL:     https://codeforces.com/problemset/problem/1895/C
 * MemoryL: 512 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 1910;

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<PII, int> cnt;
    vector<string> s(n + 1);
    auto get = [&](string s) {
        int res = 0;
        for(auto i : s)res += (i - '0');
        return res;
    };
    for(int i = 1, sum = 0; i <= n; i++) {
        cin >> s[i];
        cnt[ {get(s[i]), (int)s[i].size()}]++;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < s[i].size(); j++) {
            string pres = s[i].substr(0, j + 1);
            string sufs = s[i].substr(j + 1);

            int pre = get(pres);
            int suf = get(sufs);

            ans += cnt[ {pre - suf, pres.size() - sufs.size()}];

            ans += cnt[ {suf - pre, sufs.size() - pres.size()}];

            // debug2(ans, i);
        }
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