// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

struct S{
    int l, r, id, pos;
};

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1), belong(n + 1);
    int block = sqrt(n);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        belong[i] = i / block + 1;
    }
    vector<S> Q(m + 1);
    map<int, int> cnt;
    for (int i = 1; i <= m; i ++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i]. id = belong[Q[i].l];
    }
    sort(Q.begin() + 1, Q.end(), [&](S a, S b) {
        if (a.id == b.id) return a.r <= b.r;
        return a.id < b.id;
    });
    int sum = 0;
    auto add = [&](int pos) -> void {
        sum -= cnt[a[pos]] * cnt[a[pos]];
        cnt[a[pos]] ++;
        pos --;
        sum += 
    };
    for (int i = 1, l = 1, r = 0; i <= m; i ++) {

    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}