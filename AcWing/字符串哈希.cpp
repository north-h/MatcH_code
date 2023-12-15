/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-15 09:49:27
 *
 * Problem: 字符串哈希
 * Contest: AcWing
 * URL:     https://www.acwing.com/problem/content/843/
 * MemoryL: 64 MB
 * TimeL:   1000 ms
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
const int M = 110;

using namespace std;


template<class T, int P1, int mod1, int P2, int mod2>
struct SH {
    vector<T> p1, p2, h1, h2;
    string s;
    SH(const string &str) :
        s(" " + str),
        p1(str.size() + 1),
        h1(str.size() + 1),
        p2(str.size() + 1),
        h2(str.size() + 1) {
        p1[0] = p2[0] = 1;
        for (int i = 1; i < s.size(); i++) {
            p1[i] = (p1[i - 1] * P1) % mod1;
            h1[i] = (h1[i - 1] * P1 % mod1 + s[i]) % mod1;
            p2[i] = (p2[i - 1] * P2) % mod2;
            h2[i] = (h2[i - 1] * P2 % mod2 + s[i]) % mod2;
        }
    }

    T get1(int l, int r) {
        return (h1[r] - (h1[l - 1] * p1[r - l + 1] % mod1) + mod1) % mod1;
    }

    T get2(int l, int r) {
        return (h2[r] - (h2[l - 1] * p2[r - l + 1] % mod2) + mod2) % mod2;
    }

    bool query(int sl, int sr, int el, int er) {
        if(get1(sl, sr) == get1(el, er) && get2(sl, sr) == get2(el, er))return true;
        return false;
    }
};

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    SH<ll, 13331, 1000000007, 131, 1000000009> H(s);
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(H.query(a, b, c, d))cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}