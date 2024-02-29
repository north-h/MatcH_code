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
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];
    sort(a.begin() + 1, a.end());
    int as = INF, ap, bp;
    for (int i = 1; i <= n; i ++) {
        int l = 1, r = n, ans = n;
        while (l <= r) {
            int mid = l + r >> 1;
            if (a[mid] >= b[i]) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
//         debug2(a[ans], ans);
        int res = 0;
        res = abs(a[ans] - b[i]);
        if (res < as) {
            as = res;
            ap = ans;
            bp = i;
        }
//         debug2(ap, bp);
        if (ans != 1) {
            res = min(res, abs(a[ans - 1] - b[i]));
            if (res < as) {
                as = res;
                ap = ans - 1;
                bp = i;
            }
        }
//         debug2(ap, bp);
    }
    swap(a[ap], a[bp]);
    for (int i = 1; i <= n; i ++) cout << a[i] << ' ';
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}