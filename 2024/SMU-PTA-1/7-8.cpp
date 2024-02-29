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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

ll get(string s) {
    ll res = 0;
    for (auto i : s) res = res * 10 + (s[i] - '0');
    return res;
}

bool Prime(ll x) {
    if (x == 0 || x == 1) return false;
    for (int i = 2; i * i <= x; i ++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i + k - 1 < s.size(); i ++) {
        ll x = get(s.substr(i, k));
        if (Prime(x)) {
            debug1(x);
            cout << s.substr(i, k) << endl;
            return ;
        }
    }
    cout << "404" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}