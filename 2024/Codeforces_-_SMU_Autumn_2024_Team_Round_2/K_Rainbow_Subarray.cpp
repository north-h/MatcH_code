/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-21 18:17:05
 *
 * Problem: K. Rainbow Subarray
 * Contest: Codeforces - SMU Autumn 2024 Team Round 2
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/551542/problem/K
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i], a[i] -= i;
    int ans = 0;
    multiset<int> L, R;
    int lsum = 0, rsum = 0, cv = 0, mid;
    auto adjust = [&]() -> void {
        while ((int)L.size() - (int)R.size() > 1) {
            auto lt = *L.rbegin();
            R.insert(lt);
            lsum -= lt;
            rsum += lt;
            L.erase((--L.end()));
        }
        while ((int)R.size() - (int)L.size() > 0) {
            auto rt = *R.begin();
            L.insert(rt);
            rsum -= rt;
            lsum += rt;
            R.erase(R.begin());
        }
    };
    for (int i = 1, j = 1; i <= n; i ++) {
        if (!L.size() || (*L.rbegin()) > a[i]) {
            L.insert(a[i]);
            lsum += a[i];
        } else {
            R.insert(a[i]);
            rsum += a[i];
        }
        adjust();
        while (j < i) {
            int mid = *L.rbegin();
            cv = (int)L.size() * mid - lsum;
            cv += rsum - (int)R.size() * mid;
            if (cv <= k) break;
            if (L.count(a[j])) {
                lsum -= a[j];
                L.erase(L.find(a[j]));
            } else {
                rsum -= a[j];
                R.erase(R.find(a[j]));
            }
            adjust();
            j ++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans << '\n';    
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}