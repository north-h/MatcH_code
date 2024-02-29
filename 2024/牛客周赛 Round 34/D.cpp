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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2), b(n + 2);
    int c = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        c += (a[i] == 0);
        b[i] = a[i] - a[i - 1];
    }
    if (c == n) {
        cout << 2 << ' ';
        for (int i = 1; i < n; i ++) cout << 1 << ' ';
        cout << endl;
        return ;
    }
    int l, r;
    int op;
    for (l = 1, r = 1; r <= n; r ++) {
        if (a[r] != 0) {
            op = a[r];
            b[l] += op;
            b[r] -= op;
            l = r + 1;
        }
    }
    b[l] += op;
    b[r] -= op;
    for (int i = 1; i <= n; i ++) b[i] += b[i - 1];
    int ans = 0;
    for (int i = 2; i <= n; i ++) {
        ans += abs(b[i] - b[i - 1]);
        if (ans > 1) {
            cout << -1 << endl;
            return ;
        }
    }
    if (ans == 0) {
        bool ok = true;
        if (a[1] == 0) {
            b[1] ++;
            ok = false;
        } else if (a[n] == 0) {
            b[n] ++;
            ok = false;
        }
        if (ok) {
            cout << -1 << endl;
            return ;
        }
    }
    for (int i = 1; i <= n; i ++) cout << b[i] << " \n"[i == n];
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}