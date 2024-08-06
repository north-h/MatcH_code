#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using PII = pair<ll, ll>;

const int N = 2e6 + 10, M = 210;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
ll n;
inline bool check(ll x, ll m, ll k, ll h) {
    ll res = x;
//  while(x>=m){
//      res+=x/m*m;
//      x=x%m+x/m*k;
//      if(res>=h) return 1;
//  }
//  res+=x;
////    cout << res << "\n";
//  return res>=h;
    if (x >= m) {
        ll dif = m - k;
        res += (x - m) / dif * k;
        ll left = (x - m) % dif;
        res += k;
        if (left + m - dif >= m) res += k;
    } else return x >= h;
//  cout<<res;
    return res >= h;
}
void solve() {
    ll m, k, h; cin >> m >> k >> h;
    if (!h) {cout << "0\n"; return ;}
    if (k == m) {cout << m << "\n"; return ;}
//  cout << h-(h-k)/m << "\n";
    ll ans = h - h / m * k;
//  while(!check(ans,m,k,h)) ans++;
    for (ll i = ans; i <= ans + 10; i++)
        if (check(i, m, k, h)) {cout << i << "\n"; return ;}
    ans += 11;
    ll l = ans, r = h;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (check(mid, m, k, h)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << "\n";
//  check(5,3,2,111);
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