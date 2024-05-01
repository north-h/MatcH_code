#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 1e6 + 10;

int n, k;
int f[N];

void solve() {
    cin >> n >> k;

    f[0] = 1;
    std::vector<int> res;
    int i;
    for (i = 1; i * 2 - 1 < k; i *= 2) {
        res.emplace_back(i);
        for (int j = n; j >= i; j --)
            f[j] |= f[j - i];
    }
    if (k - i > 0) {
        res.emplace_back(k - i);
        for (int j = n; j >= k - i; j --)
            f[j] |= f[j - (k - i)];
    }

    for (i = k + 1; i <= n; i ++)
        if (!f[i]) {
            res.emplace_back(i);
            for (int j = n; j >= i; j --)
                f[j] |= f[j - i];
        }

    cout << res.size() << endl;
    for (auto v : res)
        cout << v << " ";
    cout << endl;
    for (int i = 0; i <= n; i ++)
        f[i] = 0;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int dt;
    
    cin >> dt;

    while (dt --)
        solve();

    return 0;
}