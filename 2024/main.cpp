#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define PII pair<int,int>
#define PIII pair<PII,int>
#define double long double
#define endl '\n'
#pragma GCC optimize(3,"Ofast","inline")

using namespace std;

const int N = 2e5 + 5, SZ = N << 2;

int a[N], vis[N];
int c[N], fa[N];
vector<int>g[N];
int s1, s2;
int mn = 0, ss1, ss2;
int n, k, m;
int t[10004], cnt[10004];
set<PII>qqq;
int qpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1)ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}
vector<int>ans;

int find(int x) {
    return fa[x] == x ? x : find(fa[x]);
}

void join(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry)
        fa[rx] = ry;
}

void solve() {
    cin >> n;
    int mx = 0, s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (!c[i]) {
            ans.clear();
            int t = i;
            while (!vis[t] && !c[t]) {
                vis[t] = 1;
                ans.emplace_back(t);
                t = a[t];
            }

            reverse(ans.begin(), ans.end());
            if (c[t]) {
                vis[t] = 0;
                for (int j = 0; j < ans.size(); j++) {
                    vis[ans[j]] = 0;
                    c[ans[j]] = c[t] + j + 1;
                }
            } else {
                for (int i = 0; i < ans.size(); i++) {
                    if (ans[i] == t) {
                        for (int j = 0; j <= i; j++) {
                            vis[j] = 0;
                            c[ans[j]] = i + 1;
                        }
                        for (int j = i + 1; j < ans.size(); j++) {
                            vis[j] = 0;
                            c[ans[j]] = j + 1;
                        }
                        break;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        mx = max(c[i], mx);
//      cout<<c[i]<<" \n"[i==n];
    }
    cout << mx << endl;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
