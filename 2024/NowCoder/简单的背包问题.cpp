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
  int n;
  cin >> n;
  int sum = 0;
  vector<int> w(n + 1), v(n + 1), dp(n + 1, INF);
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
    sum += v[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = sum; j >= v[i]; j--) {
      dp[i] = min(dp[i], dp[i - v[i]] + w[i]);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
  }
}

int32_t main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int h_h = 1;
  cin >> h_h;
  while (h_h--) solve();
  return 0;
}