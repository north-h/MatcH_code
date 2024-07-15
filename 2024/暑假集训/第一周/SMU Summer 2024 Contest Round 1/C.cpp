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
    vector<int> a(n + 1), c(n + 1);
    vector<vector<int>> b(n + 1);
    multiset<int> st;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (st.size() == 0) st.insert(a[i]);
        else {
            auto p = st.lower_bound(a[i]);
            if (p == st.begin()) st.insert(a[i]);
            else {
                p = prev(p);
                st.erase(p);
                st.insert(a[i]);
            }
        }
    }
    cout << st.size() << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}