#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = long long;

#define int i64

using vi = vector<int>;
using pii = pair<int, int>;

const i32 inf = INT_MAX / 2;

const int mod = 1e9 + 7;

i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    int sum = 0 , pre = 0 , res = 0, len = n;

    for (auto i : a)
        sum = (sum + i) % mod, res = (res + sum) % mod;

    for (int i = 0; i < m; i++) {
        res = (res * 2 + sum * len) % mod;
        sum = sum * 2 % mod;
        len = len * 2 % mod;
    }

    auto b = a;
    ranges::reverse(a);
    a.insert(a.end(), b.begin(), b.end());
    int ret = 0;
    sum = 0, len = n * 2;
    for (auto i : a)
        sum = (sum + i) % mod, ret = (ret + sum) % mod;
    for (int i = 1; i < m; i++) {
        ret = (ret * 2 + sum * len) % mod;
        sum = sum * 2 % mod;
        len = len * 2 % mod;
    }
    cout << max(res, ret);
    return 0;
}

