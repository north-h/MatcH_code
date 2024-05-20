#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using PII=pair<ll,ll>;

const int N=2e6+10,M=210;
const int mod=1e9+7;
ll n;
ll a[N];
ll sum[N];
const int k=1e8;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	set<array<int, 2>> s;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = n + 1 - a[i];
		s.insert({b[i], i});
	}
	for (int i = 2; i < n; i++){
		while(!s.empty()){
			auto t = s.upper_bound({b[i] + 1, 0});      //找比bi大并且还可以取的值
			if (t == s.end()) break;
			auto [x, y] = *t;
			s.erase(t), s.erase({b[i], i});
			b[y] = b[i], b[i] = x;
			s.insert({b[y], y});
			i++;
			break;
		}
	}
	for (int i = 1; i <= n; i++) cout << b[i] << " ";
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int O_o=1;
//	cin >> O_o;
	while(O_o--) solve();
	return 0;
}
//make it count
//开ll plz
