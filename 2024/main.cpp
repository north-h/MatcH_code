// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

using namespace std;
// using ll = long long;

int get(int n, int d) {
    for (int k = 1; k <= 1000000000; k ++) {
        string s = to_string(n * k);
        map<int, int> mp;
        for (auto i : s) mp[i - '0'] ++;
        int f = 0;
        for (int i = 1; i <= 9; i ++) {
            if (i == d) f += mp[i] >= 2;
            else f += mp[i] >= 1;
        }
        if (f == 9) return k;
    }
    return -1;
}


bool check(int x) {
    map<int, int> mp;
    string s = to_string(x);
    for (auto i : s) mp[i - '0'] ++;
    int f = 0;
    for (int i = 1; i <= 9; i ++) {
        f += mp[i] >= 1;
    }
    if (f == 9) return true;
    return false;
}

void solve() {
    string s = "123456789";
    string sans;
    int ans = 0;
    do {
        // debug1(s);
        int res = 0;
        for (auto i : s) res = res * 10 + (i - '0');
        int c = 0;
        for (int i = 1; i <= 40; i ++) {
            // cout << i << ':' << res * i;
            if (check(res * i)) c ++;
        }
        if (ans < c) {
            sans = s;
            ans = c;
        }
        // cout << c << ' ' << s << '\n';
    } while (next_permutation(s.begin(), s.end()));
    // int c = 123456789, v = 0;
    // for (int i = 1; i <= 40; i ++) {
    //     // cout << i << ':' << res * i;
    //     if (check(c * i)) cout << c * i << "true\n", v ++;
    //     else cout << "fasle\n";
    // }
    // cout << v << '\n';
    cout << sans << ' ' << ans << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}