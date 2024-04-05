/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-02 13:06:10 ms
 *
 * Problem: P8665 [蓝桥杯 2018 省 A] 航班时间
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8665?contestId=165469
 * MemoryL: 128 MB
 * TimeL:   1000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
// #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int hae, mae ,sae, has, mas, sas;
    hae = (a[0] - '0') * 10 + (a[1] - '0');
    mae = (a[3] - '0') * 10 + (a[4] - '0');
    sae = (a[6] - '0') * 10 + (a[7] - '0');
    has = (a[9] - '0') * 10 + (a[10] - '0');
    mas = (a[12] - '0') * 10 + (a[13] - '0');
    sas = (a[15] - '0') * 10 + (a[16] - '0');
    int hbe, mbe ,sbe, hbs, mbs, sbs;
    hbe = (b[0] - '0') * 10 + (b[1] - '0');
    mbe = (b[3] - '0') * 10 + (b[4] - '0');
    sbe = (b[6] - '0') * 10 + (b[7] - '0');
    hbs = (b[9] - '0') * 10 + (b[10] - '0');
    mbs = (b[12] - '0') * 10 + (b[13] - '0');
    sbs = (b[15] - '0') * 10 + (b[16] - '0');
    if (a.size() > 17) has += (a[20] - '0') * 24;
    if (b.size() > 17) hbs += (b[20] - '0') * 24;
    int ta = has * 3600 + mas * 60 + sas - (hae * 3600 + mae * 60 + sae);
    int tb = hbs * 3600 + mbs * 60 + sbs - (hbe * 3600 + mbe * 60 + sbe);
    int t = (ta + tb) / 2;
    int h = t / 3600;
    t %= 3600;
    int m = t / 60;
    t %= 60;
    int s = t;
    printf("%02d:%02d:%02d\n", h, m, t);
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    getchar();
    while (h_h--)solve();
    return 0;
}