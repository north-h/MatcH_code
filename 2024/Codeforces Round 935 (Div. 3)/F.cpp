// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

template <class T>
struct BIT {
    vector<T> sum1, sum2;
    int n;
    BIT() {}
    void init(int N) {
        n = N;
        sum1.resize(n);
        sum2.resize(n);
    }
    void add(int x, T k) {
        for(int i = x; i < n; i += (i & -i))
            sum1[i] += k, sum2[i] += x * k;
    }
    void add(int l, int r, T x) {
        add(l, x), add(r + 1, -x);
    }
    T query(int x) {
        T res = 0;
        for(int i = x; i > 0; i -= (i & -i))
            res += (x + 1) * sum1[i] - sum2[i];
        return res;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }

    int kth(int k) {
        int l = 1, r = n, ans;
        while (l <= r ) {
            int mid = l + r >> 1;
            if (query(mid, n) <= k) r = mid + 1, ans = mid;
            else l = mid + 1;
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
<<<<<<< HEAD
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1, x; i <= n; i ++) {
       cin >> x;
       b[i] = a[x];
    }
    priority_queue<int, vector<int> , greater<int>> pq;
    int ans = 0, sum = 0;
    for (int i = n; i >= 1; i --) {
        pq.push(b[i]);
        if (n - (i - 1) < i) continue;
        while ((int)pq.size() > i) pq.pop();
        if (ans <= pq.top() * i) {
            ans = pq.top() * i;
            sum = i;
        }
=======
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    set<PII> st;
    int ans = 0, sum = 1;
    for (int i = 0; i < n; i ++) {
        st.insert({a[i], b[i]});
        ans = max(ans, a[i]);
    }
    for (int i = 0; i < n; i ++) {
        // debug2(mp[b[i]], b[i]);
        auto it = *st.lower_bound({a[i], b[i]});
        st.erase(it);
        // for (auto [x, y] : st) debug2(x, y);
        if ((int)st.size() >= i + 2) {
            vector<int> T;
            for (auto [x, y] : st) T.push_back(x);
            sort(T.rbegin(), T.rend());
            // for (auto i : T) cout << i << ' ';
            // cout << endl;
            if (ans < T[i + 1] * (i + 2)) {
                ans = T[i + 1] * (i + 2);
                sum = i + 2;
            }
        } else break;
>>>>>>> 248acb2c9bb3c3b4f1145ee6e4127652d83795bd
    }
    cout << ans << ' ' << sum << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}