// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

template <class T>
struct BIT {
    vector<T> sum1, sum2;
    int n;
    BIT(int N) {
        n = N;
        sum1.resize(n + 1);
        sum2.resize(n + 1);
    }
    void add(int x, T k) {
        for (int i = x; i <= n; i += (i & -i))
            sum1[i] += k, sum2[i] += x * k;
    }
    void range_add(int l, int r, T x) {
        add(l, x), add(r + 1, -x);
    }
    T query(int x) {
        T res = 0;
        for (int i = x; i > 0; i -= (i & -i))
            res += (x + 1) * sum1[i] - sum2[i];
        return res;
    }
    T range_query(int l, int r) {
        return query(r) - query(l - 1);

    }
};

BIT<int> bit(N + 1);

int get(vector<int> a) {
    int mx = *max_element(a.begin() + 1, a.end());
    int cv = 0;
    for (int i = 1; i < a.size(); i ++) {
        cv += bit.range_query(a[i] + 1, N);
        bit.range_add(a[i], a[i], 1);
    }
    for (int i = 1; i < a.size(); i ++) {
        bit.range_add(a[i], a[i], -1);
    }
    return cv;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> M(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> M[i][j];
        }
    }
    int mx = max(n, m);
    if (n > m) {
        int d = n - m;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= d; j ++) {
                M[i].push_back(0);
            }
        }
    } else {
        int d = m - n;
        for (int i = 1; i <= d; i ++) {
            vector<int> t(1);
            for (int j = 1; j <= m; j ++) {
                t.push_back(0);
            }
            M.push_back(t);
        }
    }
    auto calc = [&](int x) -> int{
        if (x == 1) {
            return M[1][1];
        }
        if (x == 2) {
            int xx = M[1][1] * M[2][2];
            int yy = M[1][2] * M[2][1];
            return xx - yy;
        }
        vector<int> ab(1);
        for (int i = 1; i <= x; i ++) ab.push_back(i);
        int res = 0;
        do {
            int sum = 1;
            for (int i = 1; i <= x; i ++) {
                sum *= M[i][ab[i]];
            }
            int x = get(ab);
            if (x & 1) sum *= (-1);
            res += sum;
        } while (next_permutation(ab.begin() + 1, ab.end()));
        return res;
    };

    int ans = INF;
    for (int i = 1; i <= mx; i ++) {
        ans = min(ans, calc(i));
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}