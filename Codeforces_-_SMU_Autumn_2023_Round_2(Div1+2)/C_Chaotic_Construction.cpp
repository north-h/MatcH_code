/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-10 12:11:49
 *
 * Problem: C. Chaotic Construction
 * Contest: Codeforces - SMU Autumn 2023 Round 2(Div.1+2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/472110/problem/C
 * MemoryL: 512 MB
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
const int N = 100010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, q;
int tr[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int k) {
    for(int i = x; i <= n; i += lowbit(i))tr[i] += k;
}

int query(int x) {
    int res = 0;
    for(int i = x; i; i -= lowbit(i))res += tr[i];
    return res;
}

int query(int l, int r) {
    return query(r) - query(l - 1);
}

void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++)add(i, 1);
    while(q--) {
        char op;
        cin >> op;
        int l, r, x;
        if(op == '?') {
            cin >> l >> r;
            if(l > r)swap(l, r);
            if(query(l, r) == r - l + 1 || query(1, l) + query(r, n) == l + n - r + 1) cout << "possible" << endl;
            else cout << "impossible" << endl;
        } else if(op == '+') {
            cin >> x;
            if(query(x, x) == 0)add(x, 1);
        } else {
            cin >> x;
            add(x, -1);
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}