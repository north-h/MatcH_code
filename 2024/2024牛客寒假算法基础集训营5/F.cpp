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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    a.push_back(LLONG_MAX);
    auto check = [&](int x) -> bool {
        vector<int> b = a;
        int c = 0;
        for (int i = n; i >= 1; i --) {
            b[i] += c * i;
            if (i % 2 == 0 && b[i] < b[i + 1]) {
                int v = (b[i + 1] - b[i]) / i;
                v = min(v, x);
                x -= v;
                c += v;
                b[i] += i * v;
            }
        }
        for (int i = 2; i <= n; i ++) {
            if (b[i] < b[i - 1]) return false;
        }
        return true;
    };
    int l = 0, r = 1e13, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1; 
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}