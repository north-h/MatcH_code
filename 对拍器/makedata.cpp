#include<bits/stdc++.h>
#include<windows.h>

#define int long long

using namespace std;

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());
int rng(int l, int r) { // [l, r]
    return rnd() % (r - l + 1) + l;
}
void array(int n) { // Generates an array with n elements
    int m = 1E9;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rng(0, m);
        cout << a[i] << " \n"[i == n - 1];
    }
}
void cand(int m, int n) { // Generate m cands from 1 to n
    for (int i = 0; i < m; i++) {
        int l = rng(1, n);
        int r = rng(1, n);
        if (l > r) {
            swap(l, r);
        }
        cout << l << " " << r << "\n";
    }
}
void tree(int n) { // Generate a tree with n vertices
    int m = 1E9;
    for (int i = 1; i < n; i++) {
        int p = rng(0, i - 1);
        int v = rng(1, m);
        cout << p + 1 << " " << i + 1 << " " << v << "\n";
    }
}
void graph(int n, int m) {
// Generate an undirected graph with n vertices and m edges. There are no double edges or self-rings in the graph, and must be connected.
    vector<pair<int, int>> e;
    map<pair<int, int>, bool> f;
    cout << n << " " << m << "\n";
    for (int i = 1; i < n; i++) {
        int p = rng(0, i - 1);
        e.push_back(make_pair(p, i));
        f[make_pair(p, i)] = f[make_pair(i, p)] = true;
    }
    // debug(f);
    for (int i = n; i <= m; i++) {
        int x, y;
        do {
            x = rng(0, n - 1);
            y = rng(0, n - 1);
        } while (x == y || f.count(make_pair(x, y)));
        e.push_back(make_pair(x, y));
        f[make_pair(x, y)] = f[make_pair(y, x)] = true;
    }
    shuffle(e.begin(), e.end(), rnd);
    for (auto [x, y] : e) {
        cout << x + 1 << " " << y + 1 << "\n";
    }
}

void makedata() {
    ofstream fout("input.txt");
    int n = rng(1, 10), m = rng(1, 10);
    fout << n << ' ' << m << '\n';
    for (int i = 1; i <= m; i ++) {
        cout << rng(1, n) << ' ' << rng(1, 6) << ' ' << rng(1, 10) << '\n';
    }
    
}

int32_t main() {
    int ans = 0;
    int n = 10000;
    for (int i = 1; i <= n; i++) {
        printf("Test#%lld\n", i);
        makedata();
        system("ZJ.exe < input.txt > ZJ_output.txt");
        system("BL.exe < input.txt > BL_output.txt");

        if (system("fc ZJ_output.txt BL_output.txt")) {
            cout << "Wrong Answer!" << endl << endl << endl;
            break;
        } else {
            cout << "Accepted!" << endl << endl << endl;
            ans ++;
        }
    }
    cout << "通过率：" << ans * 1.0 / n * 100 << "%" << endl;
    return 0;
}
