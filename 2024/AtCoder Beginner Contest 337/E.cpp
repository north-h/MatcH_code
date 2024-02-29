// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
// #define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    int  m = 1, cnt = 0;
    while (m < n) m <<= 1, cnt++;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < cnt; j++) {
            if ((i >> j) & 1) {
                a[j].push_back(i + 1);
            }
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << a[i].size() << ' ';
        for (auto j : a[i]) cout << j << ' ';
        cout << endl;
    }
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int x = 0;
    for (auto i : s) x = x * 2 + (i - '0');
    cout << x + 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}