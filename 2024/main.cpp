#include <bits/stdc++.h>

using namespace std;
const int NR = 200001;
int n;
vector<pair<int, int> > e[NR];
int cnt[2][NR];
double f[2][NR];
void dfs1(int u, int fa, int m) {
    if (m > 0) {
        f[0][u] = 1.0 * cnt[0][u] / (1.0 * m);
        f[1][u] = 1.0 * cnt[1][u] / (1.0 * m);
    }
    if (m > 1) {
        f[0][u] = max(f[0][u], f[0][fa]);
        f[1][u] = min(f[1][u], f[1][fa]);
    }
    // cout << u << " " << f[0][u] << " " << f[1][u] << endl;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i].first, w = e[u][i].second;
        if (v != fa) {
            cnt[0][v] = cnt[0][u];
            cnt[1][v] = cnt[1][u];
            cnt[w][v]++;
            dfs1(v, u, m + 1);
        }
    }
}

void dfs2(int u, int fa, bool flag) {
    double maxn0 = -1, maxn1 = -1;
    int id = 0;
    bool leaf = true;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i].first;
        if (v != fa) {
            dfs2(v, u, (flag ^ 1));
            leaf = false;
            if (flag) {
                if (f[1][v] > maxn1) {
                    maxn1 = f[1][v];
                    maxn0 = f[0][v];
                }
            }
            else {
                if (f[0][v] > maxn0) {
                    maxn0 = f[0][v];
                    maxn1 = f[1][v];
                }
            }
        }
    }

    if (!leaf) {
        f[0][u] = maxn0;
        f[1][u] = maxn1;
    }

    // cout << u << " " << f[0][u] << " " << f[1][u] << endl;
}
void test() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        f[0][i] = f[1][i] = 0;
        cnt[0][i] = cnt[1][i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back(make_pair(v, w));
        e[v].push_back(make_pair(u, w));
    }
    dfs1(1, 0, 0);
    dfs2(1, 0, true);
    printf("%0.12lf\n", f[1][1]);
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        test();
    }
    return 0;
}