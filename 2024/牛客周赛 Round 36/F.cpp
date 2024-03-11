// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 100100;
const int INF = 0x3f3f3f3f;

using namespace std;

template <class T>
struct BIT {
    vector<T> sum1, sum2;
    int n;
    BIT() {}
    void init(int N) {
        n = N;
        sum1.resize(n);
        sum2.resize(n);
    }
    void add(int x, T k) {
        for(int i = x; i < n; i += (i & -i))
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
    vector<string> ss{"red", "rde", "edr", "erd", "dre", "der"};
    int n, m;
    string s;
    cin >> n >> m >> s;
    BIT<int> bit[6];
    for (int i = 0; i < 6; i ++) bit[i].init(n + 1);
    for (int i = 0 ; i < 6; i ++) {
        for (int j = 0; j < s.size(); j ++) {
            if (s[j] != ss[i][j % 3]) {
                bit[i].range_add(j + 1, j + 1, 1);
            }
        }
    }
    while (m --) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            char op;
            cin >> x >> op;
            x--;
            int y = x % 3;
            for (int i = 0; i < 6; i ++) {
                // if (s[x] != op && ss[i][y] == op) bit[i].range_add(x + 1, x + 1, -1);
                // if (s[x] == ss[i][y] && s[x] != op) bit[i].range_add(x + 1, x + 1, 1);
                if (s[x] == ss[i][y]) {
                    if (s[i] != op) bit[i].range_add(x + 1, x + 1, 1);
                } else {
                    if (ss[i][y] == op) bit[i].range_add(x + 1, x + 1, -1);
                }
            }
            s[x] = op;
        } else {
            int l, r;
            cin >> l >> r;
            int ans = INF;
            for (int i = 0; i < 6; i ++) {
                ans = min(ans, bit[i].range_query(l, r));
            }
            cout << ans << endl;
        }
    }
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