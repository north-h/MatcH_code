//
//  Author : north_h
//  File : F.cpp
//  Time : 2023/7/18/20:15
//                  _   _         _     
// _ __   ___  _ __| |_| |__     | |__  
//| '_ \ / _ \| '__| __| '_ \    | '_ \ 
//| | | | (_) | |  | |_| | | |   | | | |
//|_| |_|\___/|_|   \__|_| |_|___|_| |_|
//                          |_____|

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
#define endl '\n'
const int N = 1010;
const int M = 110;
const int MOD = 998244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int tr[N][N];
char g[N][N];
int n, m, q;

inline int lowbit(int x) {
    return x & (-x);
}

void add(int x,int y,int k) {
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= m; j += lowbit(j)) {
            tr[i][j] += k;
        }
    }
}

int query(int x,int y) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        for (int j = y; j; j -= lowbit(j)) {
            res += tr[i][j];
        }
    }
    return res;
}

int query(int x1,int y1,int x2,int y2){
    return query(x2,y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1);
}

void solve() {
    cin >> n >> m >> q;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '*') {
                sum++;
                add(i, j, 1);
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (g[x][y] == '*') {
            sum--;
            g[x][y] = '.';
            add(x, y, -1);
        } else {
            sum++;
            g[x][y] = '*';
            add(x, y, 1);
        }
        int col = sum / n;
        int cnt = sum % n;
        int t = 0;
        if (col)t += query(1, 1, n, col);
        if (cnt)t += query(1, col + 1, cnt, col + 1);
        cout << sum - t << endl;
    }
}

int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}

