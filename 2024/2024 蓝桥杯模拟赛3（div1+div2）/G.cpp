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
const int N = 10000010;
const int INF = 0x3f3f3f3f;

using namespace std;

int fa[N];

int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb) {
        fa[pa] = pb;
    }
}

void solve() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m * n; i ++) fa[i] = i;
    int k;
    cin >> k;
    while (k --) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    set<int> st;
    for (int i = 1; i <= m * n; i ++) {
        int pi = find(i);
        st.insert(pi);
    }
    cout << st.size() << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}