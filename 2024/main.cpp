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
ll a[N];

int value(int x, int y) {
    int ans = 0;
    for (int i = n, j = 1; i >= 1 && j <= n;) {
        cout << '?' << ' ' << i << ' ' << j << endl;
        int c; cin >> c;
        if (c) ans += i, j ++;
        else i ++;
    }
    return ans ;
}

void solve() {
    int n, k; cin >> n >> k;
    
    int l = 1, r = n * n, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;

    }
    cout << '!' << ' ' << ans << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int O_o = 1;
//  cin >> O_o;
    while (O_o--) solve();
    return 0;
}
//make it count
//开ll plz