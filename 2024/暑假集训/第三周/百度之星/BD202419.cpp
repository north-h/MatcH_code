// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 1000010;
const int INF = 0x3f3f3f3f;

using namespace std;
int base1 = 131, mod1 = 1e9 + 7;

int Ha[27][N], p1[N], n, q;
string a, b;

int get_hash(int l, int r, int idx) {
    if (l > r) return 0;
    int res1 = (Ha[idx][r] - Ha[idx][l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
    return res1;
}

void solve() {
    cin >> n >> q;
    cin >> a;
    a = " " + a;
    p1[0] = 1;
    for (int i = 1; i <= n; i ++) {
        p1[i] = p1[i - 1] * base1 % mod1;
    }
    for (auto i = 'a'; i <= 'z'; i ++) {
        for (int j = 1; j <= n; j ++) {
            int op = 0;
            if (a[j] == i) op = 1;
            Ha[i - 'a'][j] = (Ha[i - 'a'][j - 1] * base1 % mod1 + op) % mod1;
        }
    }
    while (q --) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        string sans;
        for (auto j = 'a'; j <= 'z'; j ++) {
            if (get_hash(l1, r1, j - 'a') != get_hash(l2, r2, j - 'a')) sans += j;
        }
        cout << sans.size() << '\n' << sans << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}