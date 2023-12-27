/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-10 13:00:31
 *
 * Problem: A. Restore the Permutation
 * Contest: Codeforces - SMU Autumn 2023 Round 7
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/478437/problem/A
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
    set<int> a;
    unordered_map<int, int> up;
    vector<int> s(n / 2 + 1);
    for (int i = 1, x; i <= n / 2; i++) {
        cin >> s[i];
        up[s[i]] = 1;
    }
    if(up.size() != n / 2) {
        cout << -1 << endl;
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (!up.count(i))
            a.insert(i);
    }
    vector<int> ans;
    for (int i = n / 2; i >= 1; i--) {
        ans.push_back(s[i]);
        auto pos = a.upper_bound(s[i]);
        if (pos == a.begin()) {
            cout << -1 << endl;
            return;
        }
        pos--;
        ans.push_back(*pos);
        a.erase(pos);
    }
    reverse(ALL(ans));
    for (auto i : ans)cout << i << " \n"[i == ans.back()];
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}