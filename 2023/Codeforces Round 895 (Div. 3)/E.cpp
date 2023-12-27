// Author:  north_h
// Time:    2023-09-08 13:50:31
// Problem: E. Data Structures Fan
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL:     https://codeforces.com/contest/1872/problem/E
// MemoryL: 256 MB
// TimeL:   2000 ms

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a, 0, sizeof a)
#define met_1(a) memset(a, -1, sizeof a)
#define met_x(a) memset(a, 0x3f, sizeof a)
#define mpy(a, b) memcopy(a, sizeof b, b)
#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int, int>
#define PDD pair<double, double>
#define PCI pair<char, int>
#define PSI pair<string, int>
#define ALL(a) a.begin(), a.end()
#define rALL(a) a.rbegin(), a.rend()
#define int128 __int128
#define endl '\n'
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), s0(n + 1), s1(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  s = ' ' + s;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      s0[i] = s0[i - 1] ^ a[i];
      s1[i] = s1[i - 1];
    } else {
      s1[i] = s1[i - 1] ^ a[i];
      s0[i] = s0[i - 1];
    }
  }
  int ans0 = s0[n] ^ s0[0];
  int ans1 = s1[n] ^ s1[0];
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r;
      cin >> l >> r;
      ans0 = ans0 ^ (s0[r] ^ s0[l - 1]) ^ (s1[r] ^ s1[l - 1]);
      ans1 = ans1 ^ (s1[r] ^ s1[l - 1]) ^ (s0[r] ^ s0[l - 1]);
    } else {
      int x;
      cin >> x;
      if (x == 0)
        cout << ans0 << ' ';
      else
        cout << ans1 << ' ';
    }
  }
  cout << endl;
}

int32_t main() {
  IOS;
  int h_h = 1;
  cin >> h_h;
  while (h_h--) solve();
  return 0;
}