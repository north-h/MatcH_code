#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using PII = pair<ll, ll>;
mt19937_64 rnd(time(0));
inline ll rng(ll l, ll r) {return rnd() % (r - l + 1) + l;}

const int N = 2e6 + 10, M = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
ll n;
ll a[N], x[N], t[N];
vector<int>ve[N];
void solve() {
    ll m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ve[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> t[i];
        ve[t[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) reverse(ve[i].begin(), ve[i].end());
    priority_queue<PII, vector<PII>, greater<>>pq;
    for (int i = 1; i <= n; i++) {
        if (ve[i].empty()) pq.push({m + 1, a[i]});
        else pq.push({ve[i].back(), a[i]}), ve[i].pop_back();
    }
    for (int i = 1; i <= m; i++) {
        ll dis = x[i] - x[i - 1];
        while (dis && !pq.empty()) {
            auto [id, lef] = pq.top(); pq.pop();
            ll mi = min(dis, lef);
            dis -= mi, lef -= mi;
            if (lef) pq.push({id, lef});
        }
        if (dis) {cout << x[i] - dis << "\n"; return ;}
        if (!pq.empty()) {
            auto [id, lef] = pq.top(); pq.pop();
            if (id != i) {
                pq.push({id, lef});
                if (ve[t[i]].empty()) pq.push({m + 1, a[t[i]]});
                else pq.push({ve[t[i]].back(), a[t[i]]}), ve[t[i]].pop_back();
            } else {
                if (ve[t[id]].empty()) pq.push({m + 1, a[t[id]]});
                else pq.push({ve[t[id]].back(), a[t[id]]}), ve[t[id]].pop_back();
            }
        } else {
            if (ve[t[i]].empty()) pq.push({m + 1, a[t[i]]});
            else pq.push({ve[t[i]].back(), a[t[i]]}), ve[t[i]].pop_back();
        }
    }
    ll mo = 0;
    while (!pq.empty()) mo += pq.top().second, pq.pop();
    cout << x[m] + mo << "\n";
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