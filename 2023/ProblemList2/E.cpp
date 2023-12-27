//
//  Author : north_h
//  File : E.cpp
//  Time : 2023/7/19/11:06
//                  _   _         _     
// _ __   ___  _ __| |_| |__     | |__  
//| '_ \ / _ \| '__| __| '_ \    | '_ \ 
//| | | | (_) | |  | |_| | | |   | | | |
//|_| |_|\___/|_|   \__|_| |_|___|_| |_|
//                          |_____|     

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define mst_0(a) memset(a,0,sizeof a)
#define mst_1(a) memset(a,-1,sizeof a)
#define mst_x(a) memset(a,0x3f,sizeof a)
#define mcy(a, b) memcpy(a,b,sizeof b)
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

inline int read() {
    int x = 0, f = 1, ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x * f;
}

int n, m;
char g[N][N];
char backup[N][N];
int dx[]{0,1,0,-1,0};
int dy[]{1,0,-1,0,0};

void press(int x,int y) {
    for (int i = 0; i < 5; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && yy >= 0 && xx < n && yy < m) {
            g[xx][yy] ^= 1;
        }
    }
}

int oprate(int x,char a) {
    int ans = INT_MAX;
    bool ok = false;
    for (int op = 0; op < (1 << m); op++) {
        int step = 0;
        mcy(backup, g);
        for (int i = 0; i < m; i++) {
            if ((op >> i & 1)) {
                press(0, i);
                step++;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == a) {
                    press(i + 1, j);
                    step++;
                }
            }
        }
        bool f = true;
        for (int j = 0; j < m; j++) {
            if (g[n - 1][j] == a) {
                f = false;
                break;
            }
        }

        if (f) {
            ok = true;
            ans = min(ans, step);
        }
        mcy(g, backup);
    }
    if (ok)return ans;
    else return -1;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> g[i];
    if (oprate(1, '1') == -1 && oprate(0, '0') == -1)cout << "Impossible";
    else cout << min(oprate(1, '1'), oprate(0, '0')) << endl;
}

int main() {
    IOS;
    int h_h = 1;
    //cin >> h_h;
    while (h_h--)solve();
    return 0;
}
