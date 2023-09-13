/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-12 13:14:35
 *
 * Problem: D. Program
 * Contest: Codeforces - SMU Autumn 2023 Round 3(Div.1)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/471657/problem/D
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
const int N = 200010;
const int M = 20;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

<<<<<<< HEAD
int f[N][M], g[N][M], log_2[N], a[N];
int n, m;
string s;


void init() {
    for(int i = 1; i <= n; i++)f[i][0] = g[i][0] = a[i];
    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 0; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            g[i][j] = min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
        }
=======
void solve() {
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    int sum = 0;
    set<int> st;
    st.insert(0);
    vector<int> a(n + 1, 0), s(n + 1, 0);
    for(int i = 0; i < n; i++) {
        if(str[i] == '-')sum--;         
        else sum++;
        st.insert(sum);
        a[i + 1] = st.size();
>>>>>>> 39c8f836599fc367f574831d93a57b1719b5155f
    }
}

int getMax(int l, int r) {
    if(l > r)return INT_MIN;
    int k = log_2[r - l + 1];
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int getMin(int l, int r) {
    if(l > r)return INT_MAX;
    int k = log_2[r - l + 1];
    return min(g[l][k], g[r - (1 << k) + 1][k]);
}

void solve() {
    cin >> n >> m >> s;
    vector<int> smax(n + 1), smin(n + 1), emax(n + 1), emin(n + 1);
    for(int i = 0; i < n; i++) {
        if(s[i] == '-')a[i + 1] = a[i] - 1;
        else a[i + 1] = a[i] + 1;
    }
    init();
    while(m--) {
        int l, r;
        cin >> l >> r;
        int res = a[r] - a[l - 1];
        int mx = max(getMax(0, l - 1), getMax(r + 1, n) - res);
        int mn = min(getMin(0, l - 1), getMin(r + 1, n) - res);
        cout << mx - mn + 1 << endl;
    }
}

int32_t main() {
    IOS;
    log_2[0] = -1;
    for(int i = 1; i < N; i++)log_2[i] = log_2[i >> 1] + 1;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}