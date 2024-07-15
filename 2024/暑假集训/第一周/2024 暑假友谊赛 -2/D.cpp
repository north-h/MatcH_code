// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int avg = s[n] / 4;
    int ans = LLONG_MAX;
    for (int i = 2; i <= n - 2; i ++) {
        int l = 1, r = i - 1, ans1 = i - 1, ans2 = n - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (s[mid] >= s[i] / 2) r = mid - 1, ans1 = mid;
            else l = mid + 1;
        }

        l = i + 1, r = n - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (s[mid] - s[i] >= (s[n] - s[i]) / 2) r = mid - 1, ans2 = mid;
            else l = mid + 1;
        }


        int s1 = s[ans1], s2 = s[i] - s[ans1], s3 = s[ans2] - s[i], s4 = s[n] - s[ans2];
        int mx = max({s1, s2, s3, s4});
        int mn = min({s1, s2, s3, s4});
        ans = min(ans, mx - mn);

        if (ans1 != 1) {
            s1 = s[ans1 - 1], s2 = s[i] - s[ans1 - 1], s3 = s[ans2] - s[i], s4 = s[n] - s[ans2];
            mx = max({s1, s2, s3, s4});
            mn = min({s1, s2, s3, s4});
            ans = min(ans, mx - mn);
        }
        if (ans2 != i + 1) {
            s1 = s[ans1], s2 = s[i] - s[ans1], s3 = s[ans2 - 1] - s[i], s4 = s[n] - s[ans2 - 1];
            mx = max({s1, s2, s3, s4});
            mn = min({s1, s2, s3, s4});
            ans = min(ans, mx - mn);
        }

        if (ans1 != 1 && ans1 != i + 1) {
            s1 = s[ans1 - 1], s2 = s[i] - s[ans1 - 1], s3 = s[ans2 - 1] - s[i], s4 = s[n] - s[ans2 - 1];
            mx = max({s1, s2, s3, s4});
            mn = min({s1, s2, s3, s4});
            ans = min(ans, mx - mn);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}