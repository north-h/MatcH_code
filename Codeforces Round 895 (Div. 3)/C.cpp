// Author:  north_h
// Time:    2023-09-08 13:50:22
// Problem: C. Non-coprime Split
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL:     https://codeforces.com/contest/1872/problem/C
// MemoryL: 256 MB
// TimeL:   1000 ms

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
  int l, r;
  cin >> l >> r;
  for (int i = l; i <= r; i++) {
    int x = i;
    for (int j = 2; j <= x / j; j++) {
      if (x % j == 0) {
        cout << j << ' ' << i - j << endl;
        return;
      }
    }
  }
  cout << -1 << endl;
}

int32_t main() {
  IOS;
  int h_h = 1;
  cin >> h_h;
  while (h_h--) solve();
  return 0;
}