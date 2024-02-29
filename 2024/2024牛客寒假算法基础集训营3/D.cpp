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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int ans = -INF;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum = max(sum + a[i], a[i]);
        ans = max(ans, sum);
    }
    if (k == 0) {
        cout << ans << endl;
        return ;
    }
    ans = -INF;
    for (int i = 2; i <= n; i ++) {
        swap(a[i], a[i - 1]);
//         for (int j = 1; j <= n; j ++) cout << a[j] << ' ';
//         cout << endl;
        sum = 0;
        for(int j = 1; j <= n; j++){
            sum = max(sum + a[j], a[j]);
            ans = max(sum, ans);
//             debug1(sum);
        }
//         debug2(i, sum);
//         ans = max(sum, ans);
        swap(a[i], a[i - 1]);
//         for (int j = 1; j <= n; j ++) cout << a[j] << ' ';
//         cout << endl;
//         cout << endl;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
//     cin >> h_h;
    while (h_h--)solve();
    return 0;
}