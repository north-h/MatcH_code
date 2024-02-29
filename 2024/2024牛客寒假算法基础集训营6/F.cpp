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
const int N = 1000010;
const int INF = 0x3f3f3f3f;

using namespace std;

int fa[N];

int find(int x) {
    if (x != fa[x]) fa[x] = find(fa[x]);
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) fa[i] = i;
    vector<int> num(n + 1);
    map<int, vector<int>> zs;
    for (int i = 1; i <= n; i ++) {
        cin >> num[i];
        int x = num[i];
        for (int j = 2; j * j <= x; j ++) {
            if (x % j == 0) {
                while (x % j == 0) x /= j;
                zs[j].push_back(i);
            }
        }
        if (x > 1) zs[x].push_back(i);
    }
    for (auto [x, y] : zs) {
        for (int i = 1; i < y.size(); i ++) {
            merge(y[i - 1], y[i]);
        }
    }
    auto t = find(1);
    vector<int> a, b;
    for (int i = 1; i <= n; i ++) {
        if (find(i) == t) a.push_back(num[i]);
        else b.push_back(num[i]);
    }
    if (!b.size()) cout << "-1 -1" << endl;
    else {
        cout << a.size() << ' ' << b.size() << endl;
        for (auto i : a) cout << i << ' ';
        cout << endl;
        for (auto i : b) cout << i << ' ';
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}