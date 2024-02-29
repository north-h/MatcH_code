// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

struct S{
    int a, b, c;
    bool operator< (const S &C)const {
        return c < C.c;
    }
}a[N];
int fa[N];
int n, m;

int find(int x) {
    if (fa[x] != x)fa[x] = find(fa[x]);
    return fa[x];
}

int kruskal() {
    sort(a + 1, a + m + 1);
    //for(int i=1;i<=m;i++)cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<endl;
    for (int i = 1; i <= n; i++)fa[i] = i;
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int pa = find(a[i].a);
        int pb = find(a[i].b);
        if (pa != pb) {
            fa[pa] = pb;
            ans += a[i].c;
            cnt++;
        }
    }
    if (cnt < n - 1)return INF;
    else return ans;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].a >> a[i].b >> a[i].c;
    }
    int t = kruskal();
    if (t == INF)cout << -1 << endl;
    else cout << t << endl;
}


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}