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
    int w, m, n;
    cin >> w >> m >> n;
    int sm = (m + w - 1) / w;
    int sn = (n + w - 1) / w;
    int em, en;
    if (sm & 1) {
        em = m % w;
    } else {
        em = w - m % w + 1;
    }
    if (sn & 1) {
        en = n % w;
    } else {
        en = w - n % w + 1;
    }
    int ans = abs(sm - sn) + abs(em - en);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}