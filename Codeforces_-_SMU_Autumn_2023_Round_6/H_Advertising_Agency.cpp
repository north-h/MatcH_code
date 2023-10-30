/*
 * =======================================================================
 * Author:  north_h
 * Time:    2023-09-29 13:02:57
 *
 * Problem: H. Advertising Agency
 * Contest: Codeforces - SMU Autumn 2023 Round 6
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/476122/problem/H
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ========================================================================
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
const double PI = 3.1415926;
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const int P = 1e9 + 7;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

template<const int T>
struct ModInt {
    const static int mod = T;
    int x;
    ModInt(int x = 0) : x(x % mod) {}
    ModInt(long long x) : x(int(x % mod)) {}
    int val() {
        return x;
    }
    ModInt operator + (const ModInt &a) const {
        int x0 = x + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod);
    }
    ModInt operator - (const ModInt &a) const {
        int x0 = x - a.x;
        return ModInt(x0 < 0 ? x0 + mod : x0);
    }
    ModInt operator * (const ModInt &a) const {
        return ModInt(1LL * x * a.x % mod);
    }
    ModInt operator / (const ModInt &a) const {
        return *this * a.inv();
    }
    bool operator == (const ModInt &a) const {
        return x == a.x;
    };
    bool operator != (const ModInt &a) const {
        return x != a.x;
    };
    void operator += (const ModInt &a) {
        x += a.x;
        if (x >= mod) x -= mod;
    }
    void operator -= (const ModInt &a) {
        x -= a.x;
        if (x < 0) x += mod;
    }
    void operator *= (const ModInt &a) {
        x = 1LL * x * a.x % mod;
    }
    void operator /= (const ModInt &a) {
        *this = *this / a;
    }
    friend ModInt operator + (int y, const ModInt &a) {
        int x0 = y + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod);
    }
    friend ModInt operator - (int y, const ModInt &a) {
        int x0 = y - a.x;
        return ModInt(x0 < 0 ? x0 + mod : x0);
    }
    friend ModInt operator * (int y, const ModInt &a) {
        return ModInt(1LL * y * a.x % mod);
    }
    friend ModInt operator / (int y, const ModInt &a) {
        return ModInt(y) / a;
    }
    friend ostream &operator<<(ostream &os, const ModInt &a) {
        return os << a.x;
    }
    friend istream &operator>>(istream &is, ModInt &t) {
        return is >> t.x;
    }

    ModInt pow(int64_t n) const {
        ModInt res(1), mul(x);
        while(n) {
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }

    ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        if (u < 0) u += mod;
        return u;
    }

};
using mint = ModInt<1000000007>;

mint dp[N][N];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp, p;
    for(auto &i : a) {
        cin >> i;
        mp[i]++;
    }
    sort(rALL(a));
    // for(auto i : a)cout << i << ' ';
    // cout << endl;
    for(int i = 0; i < k; i++) {
        p[a[i]]++;
    }
    mint ans = 1;
    set<int> st;
    for(int i = 0; i < n; i++) {
        if(mp[a[i]] != p[a[i]] && !st.count(a[i])) {
            int x = mp[a[i]];
            int y = p[a[i]];
            // cout << x << ' ' << y << endl;
            ans *= dp[x][y];
            st.insert(a[i]);
        }
    }
    cout << ans  << endl;
    // cout << dp[4][2] << endl;
}

int32_t main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = 1; //n个数中取0个，默认为1
            } else {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]);
            }
        }
    }
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}