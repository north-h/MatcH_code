/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-22 20:47:58
 * Problem : cf-849-F
 * =====================================
 *                   _   _         _
 *  _ __   ___  _ __| |_| |__     | |__
 * | '_ \ / _ \| '__| __| '_ \    | '_ \
 * | | | | (_) | |  | |_| | | |   | | | |
 * |_| |_|\___/|_|   \__|_| |_|___|_| |_|
 *                           |_____|
 */

#pragma GCC optimize(3)
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
const int N = 200010;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int tr[N];
int n, m ;

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i))tr[i] += k;
}

int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i))res += tr[i];
    return res;
}

int change(int x, int k) {
    int res = x;
    while(k--) {
        int temp = 0;
        while(res) {
            temp += res % 10;
            res /= 10;
        }
        res = temp;
        if(res < 10)return res;
    }
    return res;
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)tr[i] = 0;
    vector<int> a(n + 1, 0), b(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r;
            cin >> l >> r;
            add(l, 1);
            add(r + 1, -1);
        } else {
            int x;
            cin >> x;
            cout << change(b[x], query(x)) << endl;;
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}