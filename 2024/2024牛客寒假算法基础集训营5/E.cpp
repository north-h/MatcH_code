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
    if (n % 2 == 0) cout << "YES" << endl;
    else {
        for (int i = n - 1, c  = 0; i >= 1; i --) {
            a[i] += c * i;
            if (a[i] > a[i + 1]) {
                cout << "NO" << endl;
                return ;
            }
            if (i % 2 == 0) {
                int v = (a[i + 1] - a[i]) / i;
                c += v;
                a[i] += i * v;
            }
        }
        cout << "YES" << endl; 
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}