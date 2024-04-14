// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

string mul(string a,int b) {
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i] * b;
        B.push_back(t % 10);
        t /= 10;
    }
    while (t)B.push_back(t % 10), t /= 10;
    while (B.size() > 1 && B.back() == 0)B.pop_back();
    string s1;
    char op;
    for (int i = B.size() - 1; i >= 0; i--)s1 += (B[i] + '0');
    return s1;
}


void solve() {
    int a;
    string b, c, d = "1";
    cin >> a >> b;
    int cnt = 0;
    for (auto i : b) {
        if (i == '.') continue;
        c += i;
    }
    for (int i = b.size() - 1; i >= 0; i --) {
        if (b[i] == '.') break;
        cnt ++;
    }
    for (int i = 1; i <= a; i ++) c = mul(c, 2), d = mul(d, 2);
    string sans = c.substr(0, c.size() - cnt + 1);
    // cout << c << '\n';
    if (sans.back() >= '5') {
        sans.pop_back();
        sans.back() ++;
    } else sans.pop_back();
    cout << sans << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    // ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}