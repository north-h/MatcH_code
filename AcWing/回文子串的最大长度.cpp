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
// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define PI acos(-1)
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 100010;
const int M = 110, base = 131, mod = 1e9 + 7;

using namespace std;

int hl[N], hr[N], p[N];
int T = 1;

int get(int h[], int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

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
        debug1(str);
        for(int i = 1, j = n; i <= n; i++, j--) {
            hl[i] = (hl[i - 1] * base + (str[i] - 'a')) % mod;
            hr[i] = (hr[i - 1] * base + (str[j] - 'a')) % mod;
            p[i] = p[i - 1] * base % mod;
        }
        for(int i = 1; i <= n; i++)cout << hl[i] << ' ';
        cout << endl;
        for(int i = 1; i <= n; i++)cout << hr[i] << ' ';
        cout << endl;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int l = 0, r = min(i - 1, n - i), res;
            while(l <= r) {
                int mid = l + r >> 1;
                if(get(hl, i - mid, i - 1) == get(hr, n + 1 - (i - mid), n + 1 - (i + 1)))l = mid + 1, res = mid;
                else r = mid - 1;
            }
            // debug1(res);
            ans = max(ans, res - 1);
        }
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}