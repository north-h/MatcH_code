// Author:  north_h
// Problem: A. Prime Deletion
// Contest: Codeforces - Educational Codeforces Round 154 (Rated for Div. 2)
// URL:     https://codeforces.com/contest/1861/problem/A
// MemoryL: 512 MB
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

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

void solve() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '3') {
      cout << 37 << endl;
      return;
    }
    if (s[i] == '7') {
      cout << 73 << endl;
      return;
    }
  }
}

int32_t main() {
  IOS;
  int h_h = 1;
  cin >> h_h;
  while (h_h--) solve();
  return 0;
}