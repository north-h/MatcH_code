#include<bits/stdc++.h>
using namespace std;

struct string_hash {
    const int base1 = 131, base2 = 13331;
    const int mod1 = 1e9 + 9, mod2 = 1e9 + 7;
    int n;
    vector<long long> h1, p1, h2, p2;
    string_hash() {};
    string_hash(const string &s) {
        n = s.size() - 1;
        h1.resize(n + 1), p1.resize(n + 1);
        h2.resize(n + 1), p2.resize(n + 1);
        p1[0] = p2[0] = 1;
        for (int i = 1; i <= n; i ++) {
            p1[i] = p1[i - 1] * base1 % mod1;
            p2[i] = p2[i - 1] * base2 % mod2;
        }
        for (int i = 1; i <= n; i ++) {
            h1[i] = (h1[i - 1] * base1 % mod1 + s[i]) % mod1;
            h2[i] = (h2[i - 1] * base2 % mod2 + s[i]) % mod2;
        }
    }
    pair<int, int> get(int l, int r) {
        int res1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
        int res2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % mod2 + mod2) % mod2;
        return {res1, res2};
    }
};