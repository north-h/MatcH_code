// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());
int rng(int l, int r) { // [l, r]
    return rnd() % (r - l + 1) + l;
}
void array(int n) { // Generates an array with n elements
    int m = 1E9;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rng(0, m);
        std::cout << a[i] << " \n"[i == n - 1];
    }
}
void cand(int m, int n) { // Generate m cands from 1 to n
    for (int i = 0; i < m; i++) {
        int l = rng(1, n);
        int r = rng(1, n);
        if (l > r) {
            std::swap(l, r);
        }
        std::cout << l << " " << r << "\n";
    }
}
void tree(int n) { // Generate a tree with n vertices
    int m = 1E9;
    for (int i = 1; i < n; i++) {
        int p = rng(0, i - 1);
        int v = rng(1, m);
        std::cout << p + 1 << " " << i + 1 << " " << v << "\n";
    }
}
void graph(int n, int m) {
// Generate an undirected graph with n vertices and m edges. There are no double edges or self-rings in the graph, and must be connected.
    std::vector<std::pair<int, int>> e;
    std::map<std::pair<int, int>, bool> f;
    std::cout << n << " " << m << "\n";
    for (int i = 1; i < n; i++) {
        int p = rng(0, i - 1);
        e.push_back(std::make_pair(p, i));
        f[std::make_pair(p, i)] = f[std::make_pair(i, p)] = true;
    }
    // debug(f);
    for (int i = n; i <= m; i++) {
        int x, y;
        do {
            x = rng(0, n - 1);
            y = rng(0, n - 1);
        } while (x == y || f.count(std::make_pair(x, y)));
        e.push_back(std::make_pair(x, y));
        f[std::make_pair(x, y)] = f[std::make_pair(y, x)] = true;
    }
    std::shuffle(e.begin(), e.end(), rnd);
    for (auto [x, y] : e) {
        std::cout << x + 1 << " " << y + 1 << "\n";
    }
}


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n = 12, q = rng(1, 10);
    cout << n << ' ' << q << '\n';
    vector<int> a(n + 1);
    int idx = 1, ix = 1;
    for (int i = 1; i <= 4; i ++) a[ix ++] = idx ++;
    idx = 1;
    for (int i = 1; i <= 4; i ++) a[ix ++] = idx ++;
    idx = 1;
    for (int i = 1; i <= 2; i ++) a[ix ++] = idx ++;
    idx = 1;
    for (int i = 1; i <= 2; i ++) a[ix ++] = idx ++;
    idx = 1;
    for (int i = 1; i <= n; i ++) cout << a[i] << ' ';
    cout << '\n';
    int b = 10;
    for (int i = 1; i <= q; i ++) {
        int p =  rng(1, n) , v = rng(1, 8);
        // b *= 10;
        cout << p << ' ' << a[p] + v << '\n';
    }
    return 0;
}