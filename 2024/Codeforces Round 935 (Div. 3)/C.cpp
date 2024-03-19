// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<int> s1(s.size() + 1), s0(s.size() + 1);
    for (int i = 1; i < s.size(); i ++) {
        if (s[i] == '1') {
            s1[i] = s1[i - 1] + 1;
            s0[i] = s0[i - 1];
        } else {
            s0[i] = s0[i - 1] + 1;
            s1[i] = s1[i - 1];
        }
    }
    vector<int> id;
    for (int i = 0; i <= n; i ++) {
        int c1 = s0[i], c2 = s1[n] - s1[i];
        int x = c1 + c2;
        if ( x >= (n + 1) / 2 && c1 >= (i + 1) / 2 && c2 >= (n - i + 1) / 2) {
            id.push_back(i);
        } 
    }
    double x = n * 1.0 / 2;
    double res = INF;
    int d = 0;
    for (auto i : id) {
        if (abs(x - i) < res) {
            res = abs(x - i);
            d = i;
        } else if(abs(x - i) == res) {
            if (d > i) d = i;
        }
    }
    cout << d << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}