<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 90c5dac4123b61d2fc7ce2560739d420090e8bb8
// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
<<<<<<< HEAD
// #define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;
=======
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        sum ^= x;
    }
    cout << sum << '\n';
    vector<int> b;
    while (sum) {
        b.push_back(sum % 2);
        sum /= 2;
    }
    reverse(b.begin(), b.end());
    for (auto i : b) cout << i << ' ';
    cout << '\n';
=======
#include <stdio.h>
char op[4] = {'+', '-', '*', '/'};
float result(float x, float y, char op) {
    if (op == '+')
        return x + y;
    if (op == '-')
        return x - y;
    if (op == '*')
        return x * y;
    if (op == '/')
        return x / y;
>>>>>>> b9e0498d9098f882ec14c44325069b8d0c626b6e
}
float model1(float a, float b, float c, float d, char op1, char op2, char op3) {
    float x, y, z;
    x = result(a, b, op1);
    y = result(x, c, op2);
    z = result(y, d, op3);
    return z;

<<<<<<< HEAD
int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
=======
}
float model2(float a, float b, float c, float d, char op1, char op2, char op3) {
    float x, y, z;
    x = result(b, c, op2);
    y = result(a, x, op1);
    z = result(y, d, op3);
    return z;
>>>>>>> 90c5dac4123b61d2fc7ce2560739d420090e8bb8

int n;
int dp[510][510];

void solve() {
    memset(dp, 0x3f, sizeof dp);
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        dp[i][i] = 1;
        dp[i][i + 1] = 1 + (a[i] != a[i + 1]);
    }
<<<<<<< HEAD
    for (int len = 3; len <= n ; len ++) {
        for (int i = 1; i + len - 1 <= n; i ++){
            int l = i, r = i + len - 1;
            if (a[l] == a[r]) dp[l][r] = min (dp[l + 1][r - 1], dp[l][r]);
            for (int k = l; k < r; k ++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
        }
    }
    // debug1(dp[2][3]);
    cout << dp[1][n] << '\n';
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
=======
    if (!flag)
        printf("-1");
>>>>>>> b9e0498d9098f882ec14c44325069b8d0c626b6e
>>>>>>> 90c5dac4123b61d2fc7ce2560739d420090e8bb8
    return 0;
}