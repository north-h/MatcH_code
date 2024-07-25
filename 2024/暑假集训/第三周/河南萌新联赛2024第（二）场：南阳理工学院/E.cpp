// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int base1 = 13331;
const int mod1 = 1e9 + 7;

using namespace std;

struct string_hash {
    int n;
    vector<long long> h1, p1;
    string_hash() {};
    string_hash(const string &s) {
        n = s.size() - 1;
        h1.resize(n + 1), p1.resize(n + 1);
        p1[0] = 1;
        for (int i = 1; i <= n; i ++) {
            p1[i] = p1[i - 1] * base1 % mod1;
        }
        for (int i = 1; i <= n; i ++) {
            h1[i] = (h1[i - 1] * base1 % mod1 + s[i]) % mod1;
        }
    }
    int get_hash(int l, int r) {
        int res1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
        return res1;
    }
    int add(int aa, int bb) {
        int res1 = (aa + bb) % mod1;
        return res1;
    }
    int mul(int aa, int kk) {
        int res1 = aa * p1[kk] % mod1;
        return res1;
    }
    int pin(int l1, int r1, int l2, int r2) {
        return add(mul(get_hash(l2, r2), r1 - l1 + 1), get_hash(l1, r1));
    }
};


void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b; a = " " + a; b = " " + b;
    vector<string_hash> Ha(27);
    vector<int> vis(27), Hb(27);
    for (auto i = 'a'; i <= 'z'; i ++) {
        string sa = " ", sb = " ";
        int ca = 0, cb = 0;
        for (int j = 1; j < a.size(); j ++) {
            if (a[j] == i) sa += a[j], ca ++;
            else sa += ' ';
        }
        for (int j = 1; j < b.size(); j ++) {
            if (b[j] == i) sb += b[j], cb ++;
            else sb += ' ';
        }
        long long H = 0;
        for (int j = 1; j < sb.size(); j ++) {
            H = (H * base1 % mod1 + sb[j]) % mod1;
        }
        Hb[i - 'a'] = H;
        if (ca == 0 || cb == 0) {
            vis[i - 'a'] = 1;
        } else {
            Ha[i - 'a'] = string_hash(sa);
        }
    }
    vector<char> cnt(27);
    for (int i = 1; i < n; i ++) {
        int l1 = 1, r1 = i, l2 = i + 1, r2 = n;
        for (auto j = 'a'; j <= 'z'; j ++) {
            if (vis[j - 'a']) continue;
            if (i == n && Ha[j - 'a'].get_hash(1, n) == Hb[j - 'a']) {
                cnt[j - 'a'] = 1;
                continue;
            }
            auto ah = Ha[j - 'a'].pin(l1, r1, l2, r2);
            auto bh = Hb[j - 'a'];
            if (ah == bh) cnt[j - 'a'] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < 27; i ++) ans += cnt[i] == 1;
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}