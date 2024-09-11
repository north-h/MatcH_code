<<<<<<< HEAD
/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-11 21:04:53
 *
 * Problem: D. Journey to Un'Goro
 * Contest: Codeforces - SMU 2024 ICPC 网络赛选拔赛2
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/548717/problem/D
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

=======
<<<<<<< HEAD
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define ll long long
using namespace std;
const int N = 109;
const int mod = 998244353;
int dp[N][N][N], n, m;
string S, T;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> S >> T;
    n = S.length();
    m = T.length();
    S = ' ' + S;
    T = ' ' + T;
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= m + 1; j++)
            for (int t = 0; t < j; t++)
                dp[i][j][t] = 1;
    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= m; l++)
            for (int r = l; r <= m; r++) {
                for (int k = l - 1; k <= r; k++)
                    dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l][k] * dp[i - 1][k + 1][r]) % mod;
                for (int k = l - 1; k < r; k++)
                    if (S[i] == T[k + 1])
                        dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l][k] * dp[i - 1][k + 2][r]) % mod;
            }
    }
    cout << dp[n][1][m] << '\n';
    //system("pause");  // 交之前记得注释一下，关流的时候不会显示输出
=======
//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
>>>>>>> f0041448c76ace52419c36645dfccc7992face6e
using namespace std;

void solve() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i += 2) ans += (n - i + 1);
    int lt = (n + 2) / 2;
    // debug2(lt0, lt1);
    string s;
    bool ok = false;
    int res = 0;
    auto dfs = [&](auto dfs, int v1, int v0, int p, int f) -> void {
        if (ok) return ;
        if (v1 > lt || v0 > lt) {
            return ;
        }
        if (p == n) {
            cout << s << '\n';
            res ++;
            if (res == 100) ok = true;
            return ;
        }
        s .append("b");
        dfs(dfs, v1 + f, v0 + !f, p + 1, f);
        s.pop_back();
        f ^= 1;
        s .append("r");
        dfs(dfs, v1 + f, v0 + !f, p + 1, f);
        s.pop_back();
    };
    cout << ans << '\n';
    dfs(dfs, 0, 1, 0, 0);
}

<<<<<<< HEAD
int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
=======
        ////再更新
        string str = "";
        int curcnt = 1;
        for (int i = 1; i <= lenT - 1; i++) {
            curcnt *= cnt[t[i] - 'a'], curcnt %= mod;
            str += char(t[i]);
            pre[str] = curcnt;
        }
        for (auto p : pret) pre[p + char(s[idx])] += pre[p];
        str = "", curcnt = 1;
        for (int i = lenT; i >= 2; i--) {
            curcnt *= cnt[t[i] - 'a'], curcnt %= mod;
            str = char(t[i]) + str;
            suf[str] = curcnt;
        }
        for (auto p : suft) suf[char(s[idx]) + p] += suf[p];
        ////再更新
        for (int i = 0; i < 26; i++) cnt[i] *= 2, cnt[i] %= mod;
        cnt[s[idx] - 'a']++, cnt[s[idx] - 'a'] %= mod;
        string ss = "";
        ss += s[idx];
//      cout << "ss:" << ss << '\n';
        if (idx == 1) pre[ss]++, suf[ss]++;
        cout << "curans:" << curans << '\n';
    }
    cout << curans;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(0));
    int O_o = 1;
//  cin >> O_o;
    while (O_o--) solve();
>>>>>>> 69208ea7c5d2fe657913baff6f3b1d58a523f144
>>>>>>> f0041448c76ace52419c36645dfccc7992face6e
    return 0;
}