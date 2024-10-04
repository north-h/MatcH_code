//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using PII = pair<ll, ll>;
mt19937_64 rnd(time(0));

const int N = 2e6 + 10, M = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
ll n;

void solve() {
    ll k; cin >> n >> k;
    ll ma = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        ll a; cin >> a;
        ma = max(a, ma);
        sum += a;
    }
    int ans = n;
    while (ans > 1) {
        if (sum + k < ma * ans) {ans--; continue;}
        if (sum % ans == 0 && sum >= ma * ans) break;
        else if ((sum + k) / ans > sum / ans && (sum + k) / ans >= ma) break;
        ans--;
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int O_o = 1;
    // cin >> O_o;
    while (O_o--) solve();
    return 0;
}
//make it count
//开ll plz