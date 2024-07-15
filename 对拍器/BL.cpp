#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using PII=pair<ll,ll>;

const int N=3e5+10,M=210;
const int mod=1e9+7;
ll n;
ll con(int a,int b,ll x){
	ll res=0;
	vector<int>ve;
	while(x) ve.push_back(x%10),x/=10;
	ve.push_back(0);
	reverse(ve.begin(),ve.end());
	bool if1=0;
	if(ve[1]>b) return LLONG_MAX;
	for(int i=1,sz=ve.size();i<sz;i++){
		if(if1){res=res*10+a; continue;}
		int num=ve[i];
		if(num<a) res=res*10+a,if1=1;
		else{
			if(i<sz-1 && ve[i+1]>b){
				if(num<b) res=res*10+num+1,if1=1;
				else return LLONG_MAX;
			}else res=res*10+num;
		}
	}
	return res;
}
void solve(){
	ll l,r; cin >> l >> r;
	ll ans=0,di=10;
	for(int i=0;i<=9;i++){
		for(int j=i;j<=9;j++){
			ll res=con(i,j,l);
			if(res<=r && j-i<di) di=j-i,ans=res;
//			cout << i << " " << j << " " << res << "\n";
		}
	}
//	if(ans==22252554622222222){cout << 22252555555555555 << "\n"; return ;}
	cout << ans << "\n";
//	cout << di;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int O_o=1;
	// cin >> O_o;
	while(O_o--) solve();
	return 0;
}
//make it count
//开ll plz