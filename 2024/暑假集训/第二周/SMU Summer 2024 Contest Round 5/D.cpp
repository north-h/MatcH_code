#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int Q; cin >> Q;
    int n = (1 << 20);
    set<int> st;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        st.insert(i);
        a[i] = -1;
    }
    while (Q --) {
        int op, x; cin >> op >> x;
        int y = x % n;
        if (op == 1) {
            auto p = st.lower_bound(y);
            if (p == st.end()) p = st.begin();
            a[*p] = x;
            st.erase(p);
        } else {
            cout << a[y] << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}