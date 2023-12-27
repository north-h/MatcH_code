/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-15 13:25:27
 *
 * Problem: D. Corrupted Array
 * Contest: Codeforces - Codeforces Round 713 (Div. 3)
 * URL:     https://codeforces.com/contest/1512/problem/D
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
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
#define endl '\n'
#define debug(a, b) cout<<(string)a<<'='<<b<<endl;
const int N = 200010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int a[N], s[N];

void solve() {
    int n;
    cin >> n;
    n += 2;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    // for(int i = 1; i <= n; i++)cout << a[i] << ' ';
    // cout << endl;
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
        // cout << s[i] << ' ';
    }
    // cout << endl;
    int ans = -1;
    for(int i = 1; i < n; i++) {
        int res = s[n - 1] - s[i] + s[i - 1];
        // cout << i << ' ' << res << endl;
        if(res == a[n]) {
            ans = i;
            break;
        }
    }
    if(ans != -1) {
        for(int j = 1; j < n; j++) {
            if(j != ans)cout << a[j] << ' ';
        }
        cout << endl;
        return ;
    }
    if(a[n - 1] == s[n - 2]) {
        for(int j = 1; j <= n - 2; j++)cout << a[j] << ' ';
        cout << endl;
        return ;
    }
    cout << -1 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}