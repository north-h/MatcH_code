/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-14 15:43:13
 *
 * Problem: 这是回文吗
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/72143/C
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * ===========================================================================
 */
// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PI acos(-1)
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 100010;
const int P = 131;

using namespace std;

ull h1[N], h2[N], h3[N], h4[N], p[N];

ull get(ull h[], int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

void solve() {
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b;
    a = " " + a;
    reverse(b.begin(), b.end());
    b = " " + b;
    // debug2(a, c);
    p[0] = 1;
    for(int i = 1, j = a.size() - 1; i < a.size(); i++, j--) {
        h1[i] = h1[i - 1] * P + a[i];
        h2[i] = h2[i - 1] * P + a[j];
        h3[i] = h3[i - 1] * P + b[i];
        h4[i] = h4[i - 1] * P + b[j];
        p[i] = p[i - 1] * P;
    }
    int pos = -1;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) {
            pos = i;
            break;
        }
    }
    int ans = (pos - 1) * 2;
    if(pos == -1) {
        cout << a.size() + b.size() - 2 << endl;
        return ;
    }
    int res1 = 0, res2 = 0;
    for(int i = a.size() - 1; i >= 0; i--) {
        if(get(h1, pos, i) == get(h2, n + 1 - i, n + 1 - pos)) {
            res1 = i - pos + 1;
            break;
        }
    }
    for(int i = b.size() - 1; i >= 0; i--) {
        if(get(h3, pos, i) == get(h4, n + 1 - i, n + 1 - pos)) {
            res2 = i - pos + 1;
            break;
        }
    }
    cout << ans + max(res1, res2) << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}