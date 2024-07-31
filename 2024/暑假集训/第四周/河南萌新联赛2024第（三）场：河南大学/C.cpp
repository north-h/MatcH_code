// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 1000010;
const int INF = 0x3f3f3f3f;

using namespace std;

int s[N];

void solve() {
    int n; cin >> n;
    if (n == 0) cout << 1 << ' ';
    else cout << n * n - (n - 2) << ' ';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}