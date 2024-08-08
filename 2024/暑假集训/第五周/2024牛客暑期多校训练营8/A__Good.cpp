// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

int vis[N];

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    set<int> st;
    for (int i = 1, x; i <= n; i ++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    int cnt = 0, m = 1000;
    while (m --) {
        for (auto i : st) {
            bool ok = false;
            for (auto j : st) {
                int gc = __gcd(i, j);
                if (!st.count(gc)) {
                    cnt ++;
                    st.insert(gc);
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
    }
    cout << cnt << '\n';
    // if (cnt & 1) cout << "dXqwq\n";
    // else cout << "Haitang\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}