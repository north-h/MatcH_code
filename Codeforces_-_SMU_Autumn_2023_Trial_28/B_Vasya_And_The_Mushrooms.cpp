/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-02 15:38:01
 *
 * Problem: B. Vasya And The Mushrooms
 * Contest: Codeforces - SMU Autumn 2023 Trial 28
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/483558/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ===========================================================================
 */
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define int long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PDD pair<double,double>
#define PCI pair<char,int>
#define PSI pair<string,int>
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()
#define int128 __int128
#define PI acos(-1)
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(3, vector<int>(n + 2));
    vector<int> s1;
    vector<int> s2(n + 1), s3(n + 1);
    s1.push_back(0);
    // s2.push_back(0);
    // s3.push_back(0);
    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int x = 0 * a[1][1] + 1 * a[2][1];
    int cnt = 1;
    for(int i = 2; i <= n; i++) {
        cnt++;
        x += a[2][i] * cnt;
    }
    for(int i = n; i >= 2; i--) {
        cnt++;
        x += a[1][i] * cnt;
    }
    // debug1(x);
    int ans = x, res = 0;;
    bool ok = true;
    for(int j = 1; j <= n; j++) {
        if(ok) {
            ok = false;
            for(int i = 1; i <= 2; i++) {
                s1.push_back(a[i][j]);
            }
        } else {
            ok = true;
            for(int i = 2; i >= 1; i--) {
                s1.push_back(a[i][j]);
            }
        }
    }
    for(int i = 1; i < s1.size(); i++) {
        s1[i] *= (i - 1);
    }
    for(int i = 1; i < s1.size(); i++) {
        s1[i] += s1[i - 1];
    }
    ans = max(ans, s1[n * 2]);
    // for(int j = 1; j <= n; j++)s2.push_back(a[1][j]);
    // for(int j = n; j >= 1; j--)s2.push_back(a[2][j]);
    // vector<int> ss2(n+1);
    for(int i = n, k = n; i >= 1; i--) {
        if(k == n)s2[k] = a[1][i] * 0 + a[2][i] * 1;
        else s2[k] = s2[k - 1] + a[1][i] * 0 + a[2][i] * 1;
    }
    for(int i = n, k = n; i >= 1; i--) {
        if(k == n)s2[k] = a[1][i] * 1 + a[2][i] * 0;
        else s2[k] = s2[k - 1] + a[1][i] * 1 + a[2][i] * 0;
    }
    // for(auto i : s2)cout << i << ' ';
    // cout << endl;
    // for(int i = 1; i < s2.size(); i++) {
    //     s2[i] *= (i - 1);
    // }
    // for(int i = 1; i < s2.size(); i++) {
    //     s2[i] += s2[i - 1];
    // }
    // for(auto i : s2)cout << i << ' ';
    // cout << endl;
    // ans = max(ans, s2[n * 2]);
    // for(int j = 1; j <= n; j++)s3.push_back(a[2][j]);
    // for(int j = n; j >= 1; j--)s3.push_back(a[1][j]);
    // for(int i = 1; i < s3.size(); i++) {
    //     s3[i] *= (i - 1);
    // }
    // for(int i = 1; i < s3.size(); i++) {
    //     s3[i] += s3[i - 1];
    // }
    // for(auto i : s3)cout << i << ' ';
    // cout << endl;
    // ans = max(ans, s2[n * 2]);
    for(int i = 1; i < n; i += 2) {
        res = s1[(i + 1) * 2] + s2[i * 2 + 1];
        ans = max(ans, res);
    }
    for(int i = 2; i < n; i += 2) {
        res = s1[(i + 1) * 2] + s3[i * 2 + 1];
        ans = max(ans, res);
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}