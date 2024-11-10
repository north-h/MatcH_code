// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m, k, t; cin >> n >> m >> k >> t;
    vector<int> a(k + 1);
    for (int i = 1; i <= k; i ++) cin >> a[i];
    vector<int> wg(10, -1), cnt(m + 1);
    
    int id = 0, cc = n;

    auto check = [&]() -> array<int, 3> {
        if (wg[2] == wg[1] && wg[9] == wg[1] && wg[1] != -1) return {2, 1, 9};
        if (wg[2] == wg[3] && wg[4] == wg[3] && wg[3] != -1) return {2, 3, 4};
        if (wg[2] == wg[5] && wg[7] == wg[5] && wg[5] != -1) return {2, 5, 7};
        if (wg[3] == wg[1] && wg[8] == wg[1] && wg[1] != -1) return {3, 1, 8};
        if (wg[4] == wg[1] && wg[7] == wg[1] && wg[1] != -1) return {4, 1, 7};
        if (wg[4] == wg[6] && wg[9] == wg[6] && wg[6] != -1) return {4, 6, 9};
        if (wg[5] == wg[1] && wg[6] == wg[1] && wg[1] != -1) return {5, 1, 6};
        if (wg[7] == wg[8] && wg[9] == wg[8] && wg[8] != -1) return {7, 8, 9};
        return {-1, -1, -1};
    };

    auto check1 = [&]() -> array<int, 2> {
        for (int i = 1; i <= 9; i ++) {
            for (int j = i + 1; j <= 9; j ++) {
                if (wg[i] == wg[j] && wg[j] != -1) return {i, j};
            }
        }
        return {-1, -1};
    };

    while (true) {
        bool f = false, fg = false;
        // debug2(id, cc);
        //1
        for (int i = 1; i <= 9; i ++) {
            if (id >= k || id >= cc) break;
            if (wg[i] != -1) continue;
            fg = true;
            wg[i] = a[++ id];
            if (a[id] == t) {
                cc ++;
            } else if (a[id] == 0) {
                cc ++;
                cnt[0] ++;
                wg[i] = -1;
                i --;
                continue;
            }
        }


        // cout << wg[2] << ' ' << wg[3] << ' ' << wg[4] << '\n';
        // cout << wg[5] << ' ' << wg[1] << ' ' << wg[6] << '\n';
        // cout << wg[7] << ' ' << wg[8] << ' ' << wg[9] << '\n';
        // cout << '\n';


        // 2
        set<int> st;
        for (int i = 1; i <= 9; i ++) {
            if (wg[i] != -1) st.insert(wg[i]); 
        }
        if ((int)st.size() == 9) {
            cnt[wg[1]] ++;
            wg[1] = -1;
            fg = true;
            continue;
        }

        // cout << wg[2] << ' ' << wg[3] << ' ' << wg[4] << '\n';
        // cout << wg[5] << ' ' << wg[1] << ' ' << wg[6] << '\n';
        // cout << wg[7] << ' ' << wg[8] << ' ' << wg[9] << '\n';
        // cout << '\n';

        // debug1(cc);

        // 3
        while (true) {
            auto [x, y, z] = check();
            if (x == -1) break;
            if (x == 1 || y == 1 || z == 1) f = true;
            if (x != 1) cnt[wg[x]] ++, wg[x] = -1;
            if (y != 1) cnt[wg[y]] ++, wg[y] = -1;
            if (z != 1) cnt[wg[z]] ++, wg[z] = -1;
            cc += 5;
            fg = true;
        }

        // cout << wg[2] << ' ' << wg[3] << ' ' << wg[4] << '\n';
        // cout << wg[5] << ' ' << wg[1] << ' ' << wg[6] << '\n';
        // cout << wg[7] << ' ' << wg[8] << ' ' << wg[9] << '\n';
        // cout << '\n';


        // 4
        while (true) {
            auto [x, y] = check1();
            // cout << x << ' ' << y << '\n';
            if (x == -1) break;
            if (x == 1 || y == 1) f = true;
            if (x != 1) cnt[wg[x]] ++, wg[x] = -1;
            if (y != 1) cnt[wg[y]] ++, wg[y] = -1;
            cc ++;
            fg = true;
        }

            // return ;

        // cout << wg[2] << ' ' << wg[3] << ' ' << wg[4] << '\n';
        // cout << wg[5] << ' ' << wg[1] << ' ' << wg[6] << '\n';
        // cout << wg[7] << ' ' << wg[8] << ' ' << wg[9] << '\n';
        // cout << '\n';

        // 5
        if (f) cnt[wg[1]] ++, wg[1] = -1;

        // cout << wg[2] << ' ' << wg[3] << ' ' << wg[4] << '\n';
        // cout << wg[5] << ' ' << wg[1] << ' ' << wg[6] << '\n';
        // cout << wg[7] << ' ' << wg[8] << ' ' << wg[9] << '\n';
        // cout << '\n';


        // 6
        if (!fg) {
            for (int i = 1; i <= 9; i ++) {
                if (wg[i] != -1) cnt[wg[i]] ++; 
            }
            break;
        } else {
            bool tp = false;
            for (int i = 1; i <= 9; i ++) {
                if (wg[i] != -1) tp = true;
            }
            if (!tp) cc += 10;
        }

        // cout << wg[2] << ' ' << wg[3] << ' ' << wg[4] << '\n';
        // cout << wg[5] << ' ' << wg[1] << ' ' << wg[6] << '\n';
        // cout << wg[7] << ' ' << wg[8] << ' ' << wg[9] << '\n';
        // cout << '\n';


        // for (int i = 0; i <= m; i ++) cout << cnt[i] << ' ';
        // cout << '\n';
        // cout << "----------------\n";
    }
    int ans = cc - k;
    // debug2(cc, k);
    if (ans > 0) {
        for (int i = 0; i <= m; i ++) cout << cnt[i] << ' ';
        cout << '\n';
        // cout << "Unhappy!" << ' ' << ans << '\n';
    } else {
        for (int i = 0; i <= m; i ++) cout << cnt[i] << ' ';
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}
