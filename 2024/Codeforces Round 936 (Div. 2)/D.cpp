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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    vector<vector<int>> b(n + 1, vector<int>(31));
    vector<int> s(31);
    for (int j = 0; j < 31; j ++) {
        for (int i = 1; i <= n; i ++) {
            b[i][j] = ((a[i] >> (30 - j)) & 1);
            s[j] += b[i][j];
        }
    }
    vector<int> vx(31);
    for (int i = 0; i < 31; i ++) {
        vx[i] = ((x >> (30 - i)) & 1);
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 31; j ++) {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < 31; i ++) cout << s[i] << ' ';
    cout << endl;
    for (int i = 0; i < 31; i ++) cout << vx[i] << ' ';
    cout << endl;
    for (int i = 1; i < 31; i ++) {
        
    }
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