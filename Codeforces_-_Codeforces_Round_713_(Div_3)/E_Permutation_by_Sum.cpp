/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-15 13:25:31
 *
 * Problem: E. Permutation by Sum
 * Contest: Codeforces - Codeforces Round 713 (Div. 3)
 * URL:     https://codeforces.com/contest/1512/problem/E
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
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int s1 = 0, s2 = 0;
    int res = r - l + 1;
    for(int i = 1; i <= res; i++)s1 += i;
    for(int i = n; i >= n - res + 1; i--)s2 += i;
    if(s1 > s || s > s2)cout << -1 << endl;
    else {
        int sum = s1;
        vector<int> ans, vis(n + 1);
        for(int i = 1; i <= res; i++) {
            ans.push_back(i);
            vis[i] = 1;
        }
        int li = n;
        for(int i = ans.size() - 1; i >= 0; i--) {
            if(sum == s)break;
            while(sum < s && ans[i] < li) {
                ans[i]++;
                vis[ans[i]] = 1;
                vis[ans[i] - 1] = 0;
                sum++;
            }
            if(ans[i] == li)li--;
        }
        vector<int> f;
        for(int i = 1; i <= n; i++) {
            if(!vis[i])f.push_back(i);
        }
        for(int i = 1; i < l; i++) {
            cout << f.back() << ' ';
            f.pop_back();
        }
        for(auto i : ans)cout << i << ' ';
        for(int i = r + 1; i <= n; i++) {
            cout << f.back() << ' ';
            f.pop_back();
        }
        cout << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}