#include <bits/stdc++.h>

using i64 = long long;

int luckiness(i64 x) {
    auto s = std::to_string(x);
    auto [pmin, pmax] = std::minmax_element(s.begin(), s.end());
    return *pmax - *pmin;
}

void solve() {
    i64 l, r;
    std::cin >> l >> r;
    
    i64 ans = l;
    i64 p = 1;
    for (int i = 0; i <= 18; i++) {
        for (int x = 0; x < 10; x++) {
            i64 v = l / p * p + (p - 1) / 9 * x;
            if (l <= v && v <= r && luckiness(v) < luckiness(ans)) {
                ans = v;
            }
            v = r / p * p + (p - 1) / 9 * x;
            if (l <= v && v <= r && luckiness(v) < luckiness(ans)) {
                ans = v;
            }
        }
        p *= 10;
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}