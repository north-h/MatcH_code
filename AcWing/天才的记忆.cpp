/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-15 01:30:39
 *
 * Problem: 天才的记忆
 * Contest: AcWing
 * URL:     https://www.acwing.com/problem/content/1275/
 * MemoryL: 64 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
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

struct RMQ {
    int n;

    std::vector<std::array<int, 30>> fmin, fmax;

    RMQ(std::vector<int> a) {
        n = a.size() - 1;
        fmin.resize(n + 1);
        fmax.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            fmin[i][0] = fmax[i][0] = a[i];
        }
        for (int i = 1; i < 30; i++) {
            // if (1 << i > n) break;
            for (int j = 1; j + (1 << i) - 1 <= n; j++) {
                fmin[j][i] = std::min(fmin[j][i - 1], fmin[j + (1 << i - 1)][i - 1]);
                fmax[j][i] = std::max(fmax[j][i - 1], fmax[j + (1 << i - 1)][i - 1]);
            }
        }
    }

    int max(int l, int r) {
        int k = log2(r - l + 1);
        return std::max(fmax[l][k], fmax[r - (1 << k) + 1][k]);
    }

    int min(int l, int r) {
        int k = log2(r - l + 1);
        return std::min(fmin[l][k], fmin[r - (1 << k) + 1][k]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    RMQ rmq(a);
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << rmq.max(l, r) << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}