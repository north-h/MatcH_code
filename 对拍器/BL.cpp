#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

string mul(string a, int b) {
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i] * b;
        B.push_back(t % 10);
        t /= 10;
    }
    while (t)B.push_back(t % 10), t /= 10;
    while (B.size() > 1 && B.back() == 0)B.pop_back();
    string s1;
    char op;
    for (int i = B.size() - 1; i >= 0; i--)s1 += (B[i] + '0');
    return s1;
}

void solve() {
    string a, b; cin >> a >> b;
    string c = mul(a, b[0] - '0');
    int an = a.size(), cn = c.size(), bn = b.size();
    vector<int> pre(cn + 1);
    int len = cn + bn - 1;
    // debug1(c);
    for (int i = 1; i <= cn; i ++) {
        pre[i] = pre[i - 1] + (c[i - 1] - '0');
    }
    // for (int i = 1; i <= cn; i ++) {
    //     cout << pre[i] << ' ';
    // }
    // cout << '\n';
    int jw = 0;
    string ans;
    // debug1(len);
    for (int i = len; i >= 1; i --) {
        int l = max(1ll, cn - i + 1);
        int r = min(cn, cn - i + bn);
        l = cn - l + 1;
        r = cn - r + 1;
        swap(l, r);
        // debug2(l, r);
        int x = pre[r] - pre[l - 1] + jw;
        // debug2(x, jw);
        jw = x / 10;
        ans += ((x % 10) + '0');
    }
    while (jw) ans += (jw % 10 + '0'), jw /= 10;
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}