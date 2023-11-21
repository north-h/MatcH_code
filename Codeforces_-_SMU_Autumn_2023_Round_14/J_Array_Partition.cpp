/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-21 14:52:11
 *
 * Problem: J. Array Partition
 * Contest: Codeforces - SMU Autumn 2023 Round 14
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/487840/problem/J
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
#define ll long long
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
const int N = 200010;
const int M = 110;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int f[N][20], lg2[N];
int a[N];
int n;


// void init() {
//     // 数组下标从1开始

// }


int query(int l, int r) {
    int k = lg2[r - l + 1];
    // debug1(k);
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

void solve() {
    cin >> n;
    lg2[0] = -1;
    for(int i = 1; i <= n; i ++) lg2[i] = lg2[i >> 1] + 1;
    // for(int i = 1; i <= n; i++)cout << lg2[i] << ' ';
    // cout << endl;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)f[i][0] = a[i];
    // for(int i = 1; i <= n; i++) {
    //     cout << f[i][0] << ' ';
    // }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            // f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
            f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
        }
    }
    vector<int> pre(n + 1, 0), post(n + 1, 0);
    for(int i = 1; i <= n; i++)pre[i] = max(pre[i - 1], a[i]);
    post[n] = a[n];
    for(int i = n - 1; i >= 1; i--) post[i] = max(post[i + 1], a[i]);
    // for(int i = 1; i <= n; i++)cout << pre[i] << ' ';
    // cout << endl;
    // for(int i = 1; i <= n; i++)cout << post[i] << ' ';
    // cout << endl;
    reverse(post.begin() + 1, post.end());
    for(int i = 1; i < n - 1; i++) {
        int pos = lower_bound(post.begin() + 1, post.end(), pre[i]) - post.begin() + 1;
        int p=pos;
        // while(pos +1 < n && a[pos] > a[pos + 1]) pos ++;
        pos = n - pos + 1;
        while(i + 1 < p && a[p - 1] < a[p]) p --;
        // debug2(pos, i);
        // debug2(pre[i],post[pos]);
        if(i + 1 >= pos || pre[i] != post[p])continue;
        int val = query(i + 1, pos - 1);
        // debug1(val);
        if(pre[i] == val) {
            cout << "YES" << endl;
            cout << i << ' ' << pos - i - 1 << ' ' << n - pos + 1 << endl;
            return ;
        }
    }
    for(int i = n; i > 2; i--) {
        int pos = lower_bound(pre.begin() + 1, pre.end(), post[i]) - pre.begin() + 1;
        // pos = n - pos + 1;

        while(i > pos + 1 && a[pos] > a[pos + 1]) pos ++;
        // debug1(pos);
        if(i <= pos + 1 || pre[i] != post[pos])continue;
        int val = query(pos + 1, i - 1);
        // debug1(val);
        // debug2(pos + 1, i - 1);
        // debug1(query(pos + 1, i - 1));
        // debug1(query(7, 10));
        if(post[i] == val) {
            // debug2(pre[i], val);
            cout << "YES" << endl;
            cout << pos << ' ' << i - pos - 1 << ' ' << n - i + 1 << endl;
            return ;
        }
    }
    cout << "NO" << endl;
}
int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}