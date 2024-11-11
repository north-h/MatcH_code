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
        debug2(id, cc);
        cout << "-------------------" << '\n';
        bool f = false, fg = false, yc = false;
        //1
        for (int i = 1; i <= 9 && id < min(k, cc); i ++) {
            if (wg[i] != -1) continue;
            fg = true;
            wg[i] = a[++ id];
            if (a[id] == t) {
                cc ++;
            } else if (a[id] == 0) {
                cc ++;
                cnt[0] ++;
                wg[i] = -1;
                yc = true;
                break;
            }
        }

        if (yc) continue;


        cout << wg[2] << ' ' << wg[3] << ' ' << wg[4] << '\n';
        cout << wg[5] << ' ' << wg[1] << ' ' << wg[6] << '\n';
        cout << wg[7] << ' ' << wg[8] << ' ' << wg[9] << '\n';
        cout << '\n';


        // 2
        set<int> st;
        bool ok = false;
        for (int i = 1; i <= 9; i ++) {
            if (wg[i] != -1) st.insert(wg[i]);
            else ok = true; 
        }
        if ((int)st.size() == 9 && !ok) {
            cnt[wg[1]] ++;
            wg[1] = -1;
            fg = true;
            continue;
        }

        cout << wg[2] << ' ' << wg[3] << ' ' << wg[4] << '\n';
        cout << wg[5] << ' ' << wg[1] << ' ' << wg[6] << '\n';
        cout << wg[7] << ' ' << wg[8] << ' ' << wg[9] << '\n';
        cout << '\n';

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

        cout << wg[2] << ' ' << wg[3] << ' ' << wg[4] << '\n';
        cout << wg[5] << ' ' << wg[1] << ' ' << wg[6] << '\n';
        cout << wg[7] << ' ' << wg[8] << ' ' << wg[9] << '\n';
        cout << '\n';



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

        cout << wg[2] << ' ' << wg[3] << ' ' << wg[4] << '\n';
        cout << wg[5] << ' ' << wg[1] << ' ' << wg[6] << '\n';
        cout << wg[7] << ' ' << wg[8] << ' ' << wg[9] << '\n';
        cout << '\n';

        // 5
        if (f) cnt[wg[1]] ++, wg[1] = -1, fg = true;

        cout << wg[2] << ' ' << wg[3] << ' ' << wg[4] << '\n';
        cout << wg[5] << ' ' << wg[1] << ' ' << wg[6] << '\n';
        cout << wg[7] << ' ' << wg[8] << ' ' << wg[9] << '\n';
        cout << '\n';


        // 6
        if (!fg) break;

        bool tp = false;
        for (int i = 1; i <= 9; i ++) {
            if (wg[i] != -1) tp = true;
        }
        if (!tp) cc += 10;

        cout << wg[2] << ' ' << wg[3] << ' ' << wg[4] << '\n';
        cout << wg[5] << ' ' << wg[1] << ' ' << wg[6] << '\n';
        cout << wg[7] << ' ' << wg[8] << ' ' << wg[9] << '\n';
        cout << '\n';


        for (int i = 0; i <= m; i ++) cout << cnt[i] << ' ';
        cout << '\n';
    }
    for (int i = 1; i <= 9; i ++) {
        if (wg[i] != -1) cnt[wg[i]] ++; 
    }
    int ans = cc - k;
    // debug2(cc, k);
        for (int i = 0; i <= m; i ++) cout << cnt[i] << ' ';
        cout << '\n';
    if (ans > 0) {
        cout << "Unhappy!" << ' ' << ans << '\n';
    } 
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}


// 0 1 5 4 1 2 5 1 0 
// 4 3 3 2 0 2 5 4 5 
// 3/ 2 0 2 2 3 1 0 4 
// 0 0 4 0 0 0 2 2 1 
// 5 5 1 5 5 0 2 5 1 
// 2 0 1 5 4 2 4 5 5 
// 0 4 4 5 4 5 1 0 5 
// 1 2 0 2 3 2 0 5 5 
// 2 4 2 1 5 0 4 3 3 
// 5 0 4 5 0 0 3 0 0 
// 1 4 2 2 3 3 2 1 3 
// 4 3 1 1 5 4 4 2 5 
// 1 0 4 4 4 0 0 4 4 
// 1 4 4 2 0 0 5 1 1 
// 1 5 4 4 0 1 0 3 4 
// 4 0 5 3 4 1 4 1 2 
// 0 2 3 3 5 3 3 4 4 
// 0 2 0 2 1 1 3 4 4 
// 5 5 5 1 3 1 3 1 5 
// 3 4 3 5 2 2 4 3 2 
// 0 1 1 2 3 5 2 5 3 
// 3 3 1 0 3 3 0 2 1 
// 1 2 3 3 3 3 3 1 5 
// 3 3 0 2 4 3 2 1 1 
// 1 4 1 5 4 3 3 5 0 
// 3 4 4 2 1 0 3 2 3 
// 3 5 5 2 0 3 1 2 5 
// 5 4 0 0 1 3 4 3 0 
// 4 4 5 5 0 0 1 4 4 
// 0 0 5 3 0 0 1 1 5 
// 1 0 5 0 5 0 5 1 5 
// 2 3 0 2 3 5 0 1 4 
// 4 2 3 2 0 5 4 1 0 
// 5 0 3 2 0 3 3 5 4 
// 5 0 2 4 2 1 5 5 0 
// 0 2 2 3 3 3 4 2 3 
// 0 2 5 0 3 0 2 1 4 
// 5 1 1 2 0 2 0 2 3 
// 2 4 4 1 1 2 5 1 4 
// 1 1 2 5 2 5 5 4 1 
// 4 0 2 4 0 4 5 3 1 
// 0 2 0 2 5 0 0 0 2 
// 3 3 2 1 3 3 5 2 0 
// 3 5 1 3 3 2 2 0 3 
// 3 4 3 3