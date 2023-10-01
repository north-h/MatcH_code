/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-30 22:35:46
 *
 * Problem: D. Jellyfish and Mex
 * Contest: Codeforces - Codeforces Round 901 (Div. 2)
 * URL:     https://codeforces.com/contest/1875/problem/D
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define int long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PDD pair<double,double>
#define PCI pair<char,int>
#define PSI pair<string,int>
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()
#define int128 __int128
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, int> mp;
	for (auto &i : a) {
		cin >> i;
		mp[i]++;
	}
	int mex = 0;
	while (mp.count(mex))mex++;
	vector<int> dp(mex + 1, LLONG_MAX);
	dp[mex] = 0;
	for (int i = mex; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			dp[j] = min(dp[j], dp[i] + (mp[j] - 1) * i + j);
		}
	}
	cout << dp[0]<< endl;
}

int32_t main() {
	IOS;
	int h_h = 1;
	cin >> h_h;
	while (h_h--)solve();
	return 0;
}
