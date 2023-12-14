/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-10 00:07:17
 *
 * Problem: C. Array Game
 * Contest: Codeforces - Codeforces Round 914 (Div. 2)
 * URL:     https://codeforces.com/contest/1904/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define int long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 110;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(k >= 3) {
        cout << 0 << endl;
        return ;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)continue;
            b.push_back(abs(a[i] - a[j]));
        }
    }
    sort(b.begin(), b.end());
    auto t = b[0];
    int mn = *min_element(a.begin() + 1, a.end());
    sort(a.begin() + 1, a.end());
    if(k == 1) {
        cout << min(t, mn) << endl;
    } else {
        int ans = min(mn, t);
        for(auto x : b) {
            int l = 1, r = n, res = -1;
            while(l <= r) {
                int mid = l + r >> 1;
                if(a[mid] <= x)l = mid + 1, res = mid;
                else r = mid - 1;
            }
            if(res != -1) {
                ans = min(ans, abs(a[res] - x));
                if(res != n)ans = min(ans, abs(a[res + 1] - x));
            } else ans = min(ans, abs(a[1] - x));
        }
        cout << ans << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}
