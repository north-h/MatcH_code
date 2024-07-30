#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int mod = 998244353;
int n;
int arr[105];

void solve() {   ////L
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int i = 2, j = 1;
    for (; i <= n; i ++) {
        if (arr[i] < arr[i - 1]) {
            int sum = 0, m = i - j, left = 0;
            for (int k = j ; k < i; k ++) sum += arr[k];
            int avg = sum / m;
            for (int k = i - 1; k > j; k --) {
                if (arr[k] >= avg) {
                    left += arr[k] - avg;
                    arr[k] = avg;
                } else {
                    arr[k] = avg;
                    left -= avg - arr[k];
                }
                m --;
                sum -= arr[k];
                avg = sum / m;
            }
            arr[j] = avg;
            j = i;
        }
    }
    int sum = 0, m = i - j, left = 0;
    for (int k = j ; k < i; k ++) sum += arr[k];
    int avg = sum / m;
    for (int k = i - 1; k > j; k --) {
        if (arr[k] >= avg) {
            left += arr[k] - avg;
            arr[k] = avg;
        } else {
            arr[k] = avg;
            left -= avg - arr[k];
        }
        m --;
        sum -= arr[k];
        avg = sum / m;
    }
    arr[j] = avg;
    int ans = 1;
    for (int k = 1; k <= n; k ++) {
        ans *= arr[k];
        ans %= mod;
    }
    // for (int i = 1; i <= n; i ++) cout << arr[i] << ' ';
    // cout << '\n';
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
