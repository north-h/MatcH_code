#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 2005;
int n, m, v, e, c[N], d[N];
double p[N], dis[N][N], f[N][N][2];

int main() {
    cin >> n >> m >> v >> e; //时段数n,可换m节,教室数量v,道路数量e
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]); //上课教室
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]); //同课教室
    for (int i = 1; i <= n; i++) scanf("%lf", &p[i]); //通过概率

    for (int i = 1; i <= v; i++)
        for (int j = 1; j < i; j++)
            dis[i][j] = dis[j][i] = 2e9;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            cout << dis[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= e; i++) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        dis[a][b] = dis[b][a] = min(dis[a][b], 1.0 * c); //连边
        // cout << dis[a][b] << ' ';
    }
    // cout << '\n';
    for (int k = 1; k <= v; k++)        //Floyd求最短路
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j < i; j++) {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
                // cout << dis[i][j] << ' ';
            }
            // cout << '\n';
        }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            f[i][j][0] = f[i][j][1] = 2e9;
    f[1][0][0] = f[1][1][1] = 0;
    for (int i = 2; i <= n; i ++) {
        for (int j = 0; j <= min(i, m); j ++) {
            f[i][j][0] = min(f[i - 1][j][0]
                             + dis[c[i - 1]][c[i]],
                             f[i - 1][j][1]
                             + dis[c[i - 1]][c[i]] * (1 - p[i - 1]))
                         + dis[d[i - 1]][c[i]] * p[i - 1];
            if (j) {
                f[i][j][1] = min(f[i - 1][j - 1][0]
                                 + dis[c[i - 1]][c[i]] * (1 - p[i])
                                 + dis[c[i - 1]][d[i]] * p[i],
                                 f[i - 1][j - 1][1]
                                 + dis[c[i - 1]][c[i]] * (1 - p[i]) * (1 - p[i - 1])
                                 + dis[c[i - 1]][d[i]] * (1 - p[i - 1]) * p[i]
                                 + dis[d[i - 1]][c[i]] * p[i - 1] * (1 - p[i])
                                 + dis[d[i - 1]][d[i]] * p[i - 1] * p[i]);
            }
            // cout << f[i][j][0] << ' ' << f[i][j][1] << '\n';
        }
    }
    double ans = 2e9;
    for (int i = 0; i <= m; i++)
        ans = min(ans, min(f[n][i][0], f[n][i][1]));
    printf("%.2lf", ans);
}