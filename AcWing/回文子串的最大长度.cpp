/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-13 17:08:28
 *
 * Problem: 回文子串的最大长度
 * Contest: AcWing
 * URL:     https://www.acwing.com/problem/content/141/
 * MemoryL: 64 MB
 * TimeL:   1000 ms
 * ===========================================================================
 */
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PI acos(-1)
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 2000010;
const int M = 110, base = 131, mod = 1e9 + 7;

using namespace std;

ull hl[N], hr[N], p[N];

ull get(ull h[], int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

bool query(int l, int r, int n) {
    ull x = get(hl, l, r);
    ull y = get(hr, n + 1 - r, n + 1 - l);
    if(x == y)return true;
    return false;
}

int T = 1;

void solve() {
    string s;
    while(true) {
        cin >> s;
        if(s == "END")return ;
        string str = "$#";
        for(auto i : s) {
            str += i;
            str += "#";
        }
        int n = str.size() - 1;
        p[0] = 1;
        for(int i = 1, j = n; i <= n; i++, j--) {
            hl[i] = (hl[i - 1] * base  + str[i]);
            hr[i] = (hr[i - 1] * base  + str[j]);
            p[i] = p[i - 1] * base;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int l = 0, r = min(i - 1, n - i), res = -1;
            while(l <= r) {
                int mid = l + r >> 1;
                if(query(i - mid, i + mid, n))l = mid + 1, res = mid;
                else r = mid - 1;
            }
            ans = max(ans, res);
        }
        cout << "Case " << T++ << ": " << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}