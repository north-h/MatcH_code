<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 定义哈希基数和模数
const ll base1 = 911382629;
const ll mod1 = 1000000007;
const ll base2 = 357142857;
const ll mod2 = 1000000009;
const int MAXLEN = 400005;

// 全局幂数组
ll pow1_arr[MAXLEN], pow2_arr[MAXLEN];

// 预计算所有可能的幂
void precompute_powers() {
    pow1_arr[0] = 1;
    pow2_arr[0] = 1;
    for (int i = 1; i < MAXLEN; ++i) {
        pow1_arr[i] = (pow1_arr[i - 1] * base1) % mod1;
        pow2_arr[i] = (pow2_arr[i - 1] * base2) % mod2;
    }
}

// 获取子串的哈希值
pair<ll, ll> get_hash(int l, int r, const vector<ll> &prefix1, const vector<ll> &prefix2) {
    // l 和 r 是 0-based，且 [l, r)
    ll hash1 = (prefix1[r] - (prefix1[l] * pow1_arr[r - l]) % mod1 + mod1) % mod1;
    ll hash2 = (prefix2[r] - (prefix2[l] * pow2_arr[r - l]) % mod2 + mod2) % mod2;
    return {hash1, hash2};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precompute_powers();

    string t;
    // 读取所有测试用例，假设每个测试用例是一行
    while (cin >> t) {
        int len_t = t.length();
        // 计算前缀哈希
        vector<ll> prefix1(len_t + 1, 0), prefix2(len_t + 1, 0);
        for (int i = 1; i <= len_t; ++i) {
            prefix1[i] = (prefix1[i - 1] * base1 + (t[i - 1] - 'a' + 1)) % mod1;
            prefix2[i] = (prefix2[i - 1] * base2 + (t[i - 1] - 'a' + 1)) % mod2;
        }

        // 计算 |s|的范围
        // ceil((len_t +1)/2)
        int start_s = (len_t + 1) / 2 + ((len_t + 1) % 2 != 0 ? 0 : 0); // ceil((len_t +1)/2)
        // 在C++中 (len_t +1 +1)/2 is ceil((len_t +1)/2)
        // But (len_t +1)/2 already gives ceil for integer division when len_t is odd
        start_s = (len_t + 1) / 2;

        bool found = false;
        string s_candidate = "";

        for (int s_len = start_s; s_len < len_t; ++s_len) {
            int l = 2 * s_len - len_t;
            if (l < 1 || l >= s_len) continue;
            // Check if t[s_len : len_t} == t[l : s_len}
            // In 0-based indexing
            // t[s_len : len_t} is [s_len, len_t)
            // t[l : s_len} is [l, s_len)
            if (s_len + (s_len - l) != len_t) {
                // From t = s + s[l:], |t| = 2*s_len - l
                // So s_len + (s_len - l) == len_t
                // Already satisfied since l =2*s_len - len_t
                // So no need to check
            }
            pair<ll, ll> hash_t_part = get_hash(s_len, len_t, prefix1, prefix2);
            pair<ll, ll> hash_s_part = get_hash(l, s_len, prefix1, prefix2);
            if (hash_t_part == hash_s_part) {
                // Found a valid s
                s_candidate = t.substr(0, s_len);
                found = true;
                break;
            }
        }

        if (found) {
            cout << "YES\n" << s_candidate << "\n";
        }
        else {
            cout << "NO\n";
        }
    }
=======
//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int mod = 1e9 + 7;
int quickpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a, res %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return res;
>>>>>>> 8bcebc9c641649f9654c58342a314bbd48a63c37
}
int n, m;
vector<int> a(100005, 0);
int s1[100005], s2[100005];    //s1[i]定义为,用了i次时的ans
void solve() {
    cin >> n >> m;
    int suma = 0, ansa = 0, sumb = 0, ansb = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], suma += a[i], suma %= mod, ansa += suma, ansa %= mod;
    auto b = a;
    reverse(b.begin() + 1, b.begin() + n + 1);
    for (int i = 1; i <= n; i++) sumb += b[i], sumb %= mod, ansb += sumb, ansb %= mod;
    int q = quickpow(2, mod - 2);
    s1[0] = ansa, s2[0] = ansb;
    for (int i = 1; i <= m; i++) {
        s1[i] = (quickpow(2, i) - 1 + mod) % mod * (n + n * ((quickpow(2, i) - 1 + mod) % mod) % mod) % mod * q % mod * suma % mod + quickpow(2, i) * ansa % mod, s1[i] %= mod;
        s2[i] = (quickpow(2, i) - 1 + mod) % mod * (n + n * ((quickpow(2, i) - 1 + mod) % mod) % mod) % mod * q % mod * sumb % mod + quickpow(2, i) * ansb % mod, s2[i] %= mod;
    }
    int ans = s1[m];
    for (int i = 0; i < m; i++) { //使用i次1操作之后,使用了reverse.
        int sum = suma * quickpow(2, i + 1) % mod;
        int nn = n * quickpow(2, i + 1) % mod;
        int ans0 = (s1[i] + s2[i]) % mod + nn * q % mod * sum % mod * q % mod;
        ans0 %= mod;
        int move = m - i - 1, res = 0;
        res = (quickpow(2, move) - 1 + mod) % mod * (nn + nn * ((quickpow(2, move) - 1 + mod) % mod) % mod) % mod * q % mod * sum % mod + quickpow(2, move) * ans0 % mod, res %= mod;
        ans = max(ans, res);
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
//    cin>>t;
    while (t--) solve();
    return 0;
}