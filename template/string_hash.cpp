const int base1 = 131, mod1 = 1e9 + 9;

struct string_hash {
    int n;
    vector<long long> h1, p1;
    string_hash() {};
    string_hash(const string &s) {
        n = s.size() - 1;
        h1.resize(n + 1), p1.resize(n + 1);
        p1[0] = 1;
        for (int i = 1; i <= n; i ++) {
            p1[i] = p1[i - 1] * base1 % mod1;
        }
        for (int i = 1; i <= n; i ++) {
            h1[i] = (h1[i - 1] * base1 % mod1 + s[i]) % mod1;
        }
    }
    int get_hash(int l, int r) {
        int res1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
        return res1;
    }
    int add(int aa, int bb) {
        int res1 = (aa + bb) % mod1;
        return res1;
    }
    int mul(int aa, int kk) {
        int res1 = aa * p1[kk] % mod1;
        return res1;
    }
    int pin(int l1, int r1, int l2, int r2) {
        return add(mul(get_hash(l2, r2), r1 - l1 + 1), get_hash(l1, r1));
    }
};