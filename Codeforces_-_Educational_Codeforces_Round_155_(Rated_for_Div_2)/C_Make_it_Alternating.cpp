/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-24 22:35:32
 *
 * Problem: C. Make it Alternating
 * Contest: Codeforces - Educational Codeforces Round 155 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1879/problem/C
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
#define debug(a) cout << #a << '=' << a << endl;
#define lf(x)   fixed << setprecision(x)
const double PI = 3.1415926;
const int N = 200010;
const int M = 1910;
const int p = 998244353;
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
using mint = ModInt<998244353>;

int f[N];

void solve() {
    string s;
    cin >> s;
    int cnt = 1;
    mint ans = 1;
    int res = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i - 1])cnt++;
        else {
            if(cnt > 1) res += cnt - 1;
            ans *= cnt;
            cnt = 1;
        }
    }
    if(cnt > 1) res += cnt - 1;
    ans = ans * cnt;
    for(int i = 1; i <= res; i++)ans = ans * i;
    cout << res << ' ' << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}