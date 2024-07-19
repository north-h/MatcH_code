#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 1010;
const int dx[] = {0, -1, 0, 1};
const int dy[] = { -1, 0, 1, 0}; //方向数组
map<string, bool> mp; //用一个map来记录这种涂法是否出现过
char g[mxn][mxn];//地图
int n, k, ans;
void dfs(int res) {
    // string s = "";
    // for (int i = 0; i < n; i++)s += g[i]; //拼字符串
    // if (mp[s])return;//判重
    // mp[s] = 1;
    if (!res) {
        ans++;//这种涂法成立
        mp[s] ++
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '.') {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (g[nx][ny] == 'r' && nx >= 0 && nx < n && ny >= 0 && ny < n) { //条件一个不能少
                        g[i][j] = 'r';
                        dfs(res - 1);
                        g[i][j] = '.'; //回溯
                    }
                }
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)cin >> g[i]; //输入地图
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '.') {
                g[i][j] = 'r';
                dfs(k - 1);
                g[i][j] = '.'; //起点回溯
            }
        }
    }
    cout << mp.size();
    return 0;
}