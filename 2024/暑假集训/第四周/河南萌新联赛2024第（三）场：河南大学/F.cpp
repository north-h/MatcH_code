#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 2000010;
const int INF = 0x3f3f3f3f;

using namespace std;

int pre[N + 10];

int get(int x, int y) {
    int cnt = 0;
    while (x && y) {
        int tx = x % 2, ty = y % 2;
        if (tx != ty) cnt ++;
        x /= 2, y /= 2;
    }
    while (x) {
        if (x % 2 == 1) cnt ++;
        x /= 2;
    }
    while (y) {
        if (y % 2 == 1) cnt ++;
        y /= 2;
    }
    return cnt;
}

void solve() {
    int x, y; cin >> x >> y ;
    int l = x, r = x + y;
    cout << pre[r] - pre[l] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    for (int i = 2; i < N; i ++) {
        pre[i] = pre[i - 1] + get(i - 1, i);
    }
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
