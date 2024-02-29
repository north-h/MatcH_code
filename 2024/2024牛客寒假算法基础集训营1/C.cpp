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
    int n, q, tc;
    cin >> n >> q >> tc;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + a[i];
    }
    while (q --) {
        int M;
        cin >> M;
        int l = 1, r = n, ans;
        while (l <= r) {
            int mid = l + r >> 1;
            if ((n - mid + 1) * tc <= M) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        cout << a[ans] + tc << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}