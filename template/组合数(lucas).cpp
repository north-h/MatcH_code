const int nod = 1e6;
int ksm(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        k >>= 1;
    }
    return res;
}


int C(int a, int b) {
    int ans = 1;
    int j = a;
    for (int i = 1; i <= b; i++, j--) {
        ans = ans * j % mod;
        ans = ans * ksm(i, mod - 2) % mod;
    }
    return ans;
}

int lucas(int a, int b) {
    if (a < mod && b < mod) {
        return C(a, b);
    }
    return C(a % mod, b % mod) * lucas(a / mod, b / mod) % mod;

}