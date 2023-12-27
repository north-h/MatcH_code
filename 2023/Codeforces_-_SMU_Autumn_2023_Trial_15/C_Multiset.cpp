/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-16 12:46:58
 *
 * Problem: C. Multiset
 * Contest: Codeforces - SMU Autumn 2023 Trial 15
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/478091/problem/C
 * MemoryL: 28 MB
 * TimeL:   1500 ms
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
const int N = 1000010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int tr[N];
int n, m;

int lowbit(int x) {
    return x & -x;
}

void add(int x, int k) {
    for(int i = x; i < N; i += lowbit(i))
        tr[i] += k;
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
    cin >> n >> m;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        add(x, 1);
    }
    while(m--) {
        int k;
        cin >> k;
        if(k < 0) {
            k = abs(k);
            int l = 1, r = N, ans = 0;
            while(l <= r) {
                int mid = l + r >> 1;
                if(query(mid) >= k)r = mid - 1, ans = mid;
                else l = mid + 1;
            }
            // debug1(ans);
            if(ans != 0)add(ans, -1);
        } else add(k, 1);
    }
    for(int i = 1; i < N; i++) {
        // debug1(query(i, i));
        if(query(i, i) > 0) {
            cout << i << endl;
            return ;
        }
    }
    cout << 0 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}