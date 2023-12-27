/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-26 11:12:26
 *
 * Problem: D. Ones and Twos
 * Contest: Codeforces - CodeTON Round 7 (Div. 1 + Div. 2, Rated, Prizes!)
 * URL:     https://codeforces.com/contest/1896/problem/D
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
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 100010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

template <class T>
struct BIT {
    vector<T> sum1, sum2;
    int n;
    BIT(int n) : n(n), sum1(n + 1), sum2(n + 1) {}
    void add(int x, T k) {
        for(int i = x; i <= n; i += (i & -i))
            sum1[i] += k, sum2[i] += x * k;
    }
    void range_add(int l, int r, T x) {
        add(l, x), add(r + 1, -x);
    }
    T query(int x) {
        T res = 0;
        for(int i = x; i > 0; i -= (i & -i))
            res += (x + 1) * sum1[i] - sum2[i];
        return res;
    }
    T range_query(int l, int r) {
        return query(r) - query(l - 1);

    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    BIT<int> bit(N);
    set<int> st;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        bit.range_add(i, i, a[i]);
        if(a[i] == 1)st.insert(i);
    }
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int s;
            cin >> s;
            int res = bit.range_query(1, n);
            if(res >= s && s % 2 == res % 2) {
                cout << "YES" << endl;
                continue;
            }
            if(!st.size()) {
                cout << "NO" << endl;
            } else {
                int l = *st.begin();
                int r = *st.rbegin();
                int pre = bit.range_query(1, r);
                int suf = bit.range_query(l, n);
                if(pre >= s || suf >= s)cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        } else {
            int p, v;
            cin >> p >> v;
            if(v == 1)st.insert(p);
            else st.erase(p);
            bit.range_add(p, p, v - a[p]);
            a[p] = v;
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}