#include<bits/stdc++.h>
using namespace std;

struct string_hash {
    const int base = 131;
    const int mod = 1e9 + 9;
    int n;
    vector<long long> h, p;
    string_hash() {};
    string_hash(const string &s) {
        n = s.size() - 1;
        h.resize(n + 1), p.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i ++) {
            p[i] = p[i - 1] * base % mod;
        }
        for (int i = 1; i <= n; i ++) {
            h[i] = (h[i - 1] * base % mod + s[i]) % mod;
        }
    }
    int get_hash(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
};