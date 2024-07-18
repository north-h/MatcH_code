#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, x, y;
    std::cin >> n >> x >> y;
    
    std::string s;
    std::cin >> s;
    
    std::vector<std::array<int, 2>> a(n + 1);
    a[0] = {0, 0};
    for (int i = 0; i < n; i++) {
        a[i + 1] = a[i];
        if (s[i] == 'W') {
            a[i + 1][1]++;
        } else if (s[i] == 'A') {
            a[i + 1][0]--;
        } else if (s[i] == 'S') {
            a[i + 1][1]--;
        } else {
            a[i + 1][0]++;
        }
    }
    
    i64 ans = 0;
    std::map<std::array<int, 2>, int> idx;
    for (int i = n; i >= 0; i--) {
        idx[a[i]] = i;
        if (idx.count({a[i][0] + x, a[i][1] + y})) {
            int j = idx[{a[i][0] + x, a[i][1] + y}];
            j = std::max(j, i + 1);
            ans += n - j + 1;
        }
    }
    std::cout << ans << "\n";
    
    return 0;
}