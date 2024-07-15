#include<bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    int n, m; cin >> n >> m;
    int c1 = 0, c2 = 0;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        if (x >= 35) {
            if (m != 4) c1 ++;
            else c2 ++;
        }
        m ++;
        if (m > 7) m = 1;
    }
    cout << c1 << ' ' << c2 << '\n';
    return 0;
}

