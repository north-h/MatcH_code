// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
  const int n = 13;
  array<array<ll, n>, n> arr;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  ll sum = 0, ans = 0;
  vector<int> vis(n);
  auto dfs = [&](auto &&self, int x, int y) -> void {
    if (x == n) {
      ans = max(ans, sum);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        sum += arr[x][i];
        vis[i] = true;
        self(self, x + 1, i);
        vis[i] = false;
        sum -= arr[x][i];
      }
    }
  };
  dfs(dfs, 0, 0);
  cout << ans << endl;
  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int h_h = 1;
  cin >> h_h;
  while (h_h--) solve();
  return 0;
}