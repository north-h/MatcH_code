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
    int n, p;
    cin >> n >> p;
    vector <int> sd(n + 2);
    for (int i = 1; i <= n; i ++) {
        cin >> sd[i];
    }
    if (sd[p] <= 8) {
        cout << "0 0" << endl;
        return ;
    }
    int l = p - 1, r = p + 1, cl = 1, cr = 1;
    while (true) {
        bool ok = false;
        if (l >= 1) {
            sd[l] += cl, cl = 0;
            if (sd[l] >= 10){
                cl = sd[l] - 10 + 1;
                cr ++;
                ok = true;
                l --;
            }
        }
        if (r <= n) {
            sd[r] += cr, cr = 0;
            if (sd[r] >= 10) {
                cr = sd[r] - 10 + 1;
                cl ++;
                ok = true;
                r ++;
            }
        }
        if (!ok) break;
    }
    cout << cl <<' ' << cr << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}