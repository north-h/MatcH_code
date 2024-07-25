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
    int n, m; cin >> n >> m;
    map<int, vector<array<int, 2>>> mp;
    int ans = n;
    for (int i = 1; i <= m; i ++) {
        int l, r; cin >> l >> r;
        mp[r - l].push_back({l, r});
    }

    for (auto [x, y] : mp) {
        sort(y.begin(), y.end());
        cout << x << ':';
        for (auto j : y) cout << j[0] << ' ' << j[1] << '\n';
        cout << '\n';
    }

    if (!mp[1].size()) {
        cout << n << '\n';
        return ;
    }

    ans += mp[1].size();

    set<array<int, 2>> st;
    int l = mp[1][0][0], r = mp[1][0][1];


    for (int i = 1; i < mp[1].size(); i ++) {
        if (mp[1][i][0] == r) r = mp[1][i][1];
        else {
            st.insert({r, l});
            l = mp[1][i][0];
            r = mp[1][i][1];
        }
    }

    st.insert({r, l});

    // for (auto [x, y] : st) {
    //     debug2(y, x);
    // }

    // debug2(l, r);
    // debug1(ans);
    for (auto [x, y] : mp) {
        if (x == 1) continue;
        int TL = -1, TR = -1;
        set<array<int, 2>> sst;
        debug1(x);
        for (auto [r, l] : st) {
            debug2(l, r);
        }
        for (auto [li, ri] : y) {
            auto p = st.upper_bound({ri, li});
            if (p != st.begin()) p = prev(p);
            auto [tr, tl] = *p;
            // debug2(tl, tr);
            // debug2(li, ri);
            if (li >= tl && ri <= tr) {
                ans ++;
                if (TL == -1) TL = li, TR = ri;
                else if (li >= TL && li <= TR) {
                    TR = ri;
                } else {
                    sst.insert({TR, TL});
                    TL = li;
                    TR = ri;
                }
            }

            // debug2(TR, TL);
        }
        if (TL != -1 && TR != -1) sst.insert({TR, TL});
        st = sst;
        // for (auto [x, y] : sst) cout << x << ' ' << y << '\n';
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