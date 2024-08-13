// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
#define i128 __int128
const i128 N = 1e15;
const int INF = 0x3f3f3f3f;

using namespace std;

void write(i128 x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

int n;
string L, R;
i128 cnt1, cnt2, cnt3, cnt4, cnt5, cnt6;
i128 num1, num2, num3, num4;

i128 check1(i128 l, i128 r, i128 xx) {
    i128 res = 0, lg = l, rg = r;
    while (l <= r) {
        i128 mid = (l + r) / 2;
        if (mid * mid >= xx) {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return res;
}

i128 check2(i128 l, i128 r, i128 xx) {
    i128 res = 0, lg = l, rg = r;
    while (l <= r) {
        i128 mid = (l + r) / 2;
        i128 m = mid;
        if (mid * mid <= xx) {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}

void solve() {
<<<<<<< HEAD
    string s; cin  >> s;
    map<int, int> mp;
    for (auto i : ans) mp[i] ++;
    int mx = 0;
    for (auto [x, y] : mp) mx = max(y, mx);
    cout << s.size() - mx << '\n';
=======
    cin >> n >> L >> R;
    for (int i = 0; i < n / 2; i++) {
        num1 = num1 * 10 + L[i] - '0';
        num3 = num3 * 10 + R[i] - '0';
    }
    for (int i = n / 2; i < n; i++) {
        num2 = num2 * 10 + L[i] - '0';
        num4 = num4 * 10 + R[i] - '0';
    }

    i128 ans = 0;

    i128 l = 0, r = num3 - 1;
    r = min(r, N);
    cnt1 = check1(l, r, num1 + 1);
    cnt2 = check2(l, r, num3 - 1);
    r = 9;
    for (int i = 1; i < n / 2; i++) r = r * 10 + 9;
    i128 s9 = r;
    r = min(r, N);
    cnt3 = check2(l, r, s9); ////通用情况
    if (num3 - num1 > 1) {
        ans += (cnt2 - cnt1 + 1) * (cnt3 + 1);
    }

    l = 0, r = num1;
    r = min(r, N);
    i128 b = check2(l, r, num1);
    if (b * b == num1) {
        l = 0;
        if (num1 == num3) r = num4;
        else r = s9;
        r = min(r, N);
        cnt4 = check1(l, r, num2);
        if (num1 == num3) cnt5 = check2(l, r, num4);
        else cnt5 = check2(l, r, s9);
        ans += (cnt5 - cnt4 + 1);
    }    ////左固定

    l = 0, r = num3;
    r = min(r, N);
    i128 c = check2(l, r, num3);
    if (c * c == num3) {
        l = 0, r = num4;
        r = min(r, N);
        cnt6 = check2(l, r, num4);
        if (num1 != num3) ans += (cnt6 + 1);
    }    ////右固定
    write(ans);
>>>>>>> 2d23109194d3083facd43edbaffc5fe937408e74
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}