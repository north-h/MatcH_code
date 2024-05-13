#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <set>
#include <bits/stdc++.h>
#define endl '\n'
#define x first
#define y second
#define falg flag
#define int long long
#define all(x) x.begin(),x.end()
#define dbug(x) cout << #x << '=' << x << endl;
#define Dbug(x,y) cout << #x << '=' << x << ',' << #y << '=' << y << endl;
#define SugarT ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = ((int)2e5) + 10;
const int M = ((int)5e2) + 10;
const int P = 1331;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
const double PI = acos(-1);

int n, m, X, Y;
string s;
map<char, int> mp;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
// UDLR
int q[210][210][210];
//int tp[110][110];
bool st[M][M];

void solve() {
    mp['U'] = 0; mp['D'] = 1; mp['L'] = 2; mp['R'] = 3;
    cin >> n >> m >> X >> Y;
    cin >> s;
    PII d = {100 - X, 100 - Y};
    X = 100; Y = 100; q[100][100][0] = 1;
    while (m--) {
        int a, b; cin >> a >> b;
        st[a + d.x][b + d.y] = true;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i <= 200; i++)
            for (int j = 0; j <= 200; j++)
                q[i][j][k] = q[i][j][k - 1];
        for (int i = 0; i <= 200; i++)
            for (int j = 0; j <= 200; j++) {
                int ex = i, ey = j;
                if (s[k] == 'L') ex --;
                if (s[k] == 'R') ex ++;
                if (s[k] == 'U') ey ++;
                if (s[k] == 'D') ey --;
                if (ex >= 0 && ex <= 200 && ey >= 0 && ey <= 200) {
                    if (!st[ex][ey])q[ex][ey][k] = (q[ex][ey][k] + q[i][j][k - 1]) % mod;
                    else q[i][j][k] = (q[i][j][k] + q[i][j][k - 1]) % mod;
                }
                // tp[i][j]=(tp[i][j]+q[i][j])%mod;
                // int op=mp[s[k]];
                // int ex=i+dx[op],ey=j+dy[op];
                // if(ex>=0 && ex<=100 && ey>=0 && ey<=100){
                //     if(!st[ex][ey])tp[ex][ey]=(tp[ex][ey]+q[i][j])%mod;
                //     else tp[i][j]=(tp[i][j]+q[i][j])%mod;
                // }
            }
        // for(int i=0;i<=100;i++)
        //     for(int j=0;j<=100;j++){
        //         q[i][j]=tp[i][j];
        //         tp[i][j]=0;
        //     }
    }
    cout << q[100][100][n];
}

signed main() {
    SugarT
    int Tcase = 1;
    //cin >> Tcase;
    while (Tcase--)
        solve();
    return 0;
}