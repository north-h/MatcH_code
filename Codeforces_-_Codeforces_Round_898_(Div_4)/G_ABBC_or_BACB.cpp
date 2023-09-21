/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-21 22:36:14
 *
 * Problem: G. ABBC or BACB
 * Contest: Codeforces - Codeforces Round 898 (Div. 4)
 * URL:     https://codeforces.com/contest/1873/problem/G
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
#define debug(a,b) cout << (string)a << '=' << b << endl;
const double PI = 3.1415926;
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int get(string s) {
    int ans = 0;
    int cnt = 0;
    bool ok = false;
    int pos = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == 'B') {
            pos = i;
            break;
        }
    }
    // debug("pos", pos);
    int poss = 0;
    for(int i = pos; i >= 0; i--) {
        if(s[i] == 'B') {
            poss = i;
        } else break;
    }
    // if(pos == poss)pos++;
    // debug("poss", poss);
    if(pos != poss) {
        for(int i = poss; i >= 0; i--) {
            if(s[i] == 'B') {
                ok = true;
                ans += cnt;
                cnt = 0;
            } else {
                cnt++;
            }

        }
        if(ok)ans += cnt;
        cnt = 0;
        ok = false;
        for(int i = pos; i < s.size(); i++) {
            if(s[i] == 'B') {
                ok = true;
                ans += cnt;
                cnt = 0;
            } else {
                cnt++;
            }
        }
        if(ok)ans += cnt;
    } else {
        int res = 0;
        // cout << pos << ' ' << poss << endl;
        for(int i = pos; i >= 0; i--) {
            if(s[i] == 'B') {
                ok = true;
                res += cnt;
                cnt = 0;
            } else {
                cnt++;
            }

        }
        if(ok)res += cnt;
        // debug("res", res);
        ans = max(res, ans);
        // debug("ans", ans);
        cnt = 0;
        ok = false;
        res = 0;
        for(int i = pos; i < s.size(); i++) {
            if(s[i] == 'B') {
                ok = true;
                res += cnt;
                cnt = 0;
            } else {
                cnt++;
            }
        }
        if(ok)res += cnt;
        // debug("res1", res);
        ans = max(res, ans);
        // debug("ans", ans);
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    ans = max(ans, get(s));
    reverse(s.begin(), s.end());
    ans = max(ans, get(s));
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}