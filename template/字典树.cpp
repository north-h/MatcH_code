#include <bits/stdc++.h>
const int N = 3000010;
using namespace std;

int tr[N][65], cnt[N];

void insert(string s) {
    int p = 0;
    for (auto i : s) {
        int u = mp[i];
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
        cnt[p] ++;
    }
}

int query(string s) {
    int p = 0;
    for (auto i : s) {
        int u = mp[i];
        if (!tr[p][u]) return 0;
        p = tr[p][u];
    }
    return cnt[p];
}

