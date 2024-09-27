//
/*
By:Luckyblock
*/
#include <bits/stdc++.h>
#define LL long long
const int kN = 2e5 + 10;
//=============================================================
int n;
std::unordered_map<LL, int> cnt;
std::vector<LL> even, modified, ans;
//=============================================================
int count(LL val_) {
    if (!cnt.count(val_)) return 0;
    return cnt[val_];
}
void add(LL val_) {
    if (!cnt.count(val_)) cnt[val_] = 0;
    ++ cnt[val_];
}
void sub(LL val_) {
    -- cnt[val_];
    if (cnt[val_] == 0) cnt.erase(val_);
    modified.push_back(val_);
}
bool get(LL val_) {
    if (count(val_)) return sub(val_), true;
    if (val_ == 1 || val_ % 2 == 0) return false;
    return (get(val_ / 2ll) && get(val_ / 2ll + 1));
}
bool check(LL val_) {
    modified.clear();
    if (get(val_)) return true;

    for (auto x : modified) add(x);
    return false;
}
//=============================================================
int main() {
    // freopen("1.txt", "r", stdin);
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++ i) {
        LL a; std::cin >> a;
        if (a % 2 == 0) even.push_back(a);
        add(a);
    }
    std::sort(even.begin(), even.end(), std::greater<LL>());
    for (auto x : even) {
        if (!count(x)) continue;
        sub(x);
        if (check(x + 1)) {
            add(2ll * x + 1);
        } else if (check(x - 1)) {
            add(2ll * x - 1);
        } else {
            add(x);
        }
    }
    for (auto x : cnt) {
        for (int i = 1; i <= x.second; ++ i) {
            ans.push_back(x.first);
        }
    }
    std::cout << ans.size() << "\n";
    sort(ans.rbegin(), ans.rend());
    for (auto i : ans) std::cout << i << ' ';
    std::cout << '\n';
    // for (std::vector<LL>::reverse_iterator it = ans.rbegin(); it != ans.rend(); ++ it) {
    //     std::cout << *it << " ";
    // }
    return 0;
}
/*
4
1 1 2 2 4
*/