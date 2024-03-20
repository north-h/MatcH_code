#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=2e5+5;
typedef long long ll;

int T,n;
int t[maxn],a[maxn];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>t[i];
		for(int i=1,id;i<=n;i++){
			cin>>id;
			a[i]=t[id];
		}
		
		priority_queue<int,vector<int>,greater<int> > h2;
		ll ans=0,tot;
		for(int i=1;i<=n;i++){//前i-1个被删掉了 
			h2.push(a[i]);
			if(n-i+1<i)continue;
			while(h2.size()>i)h2.pop();
			
			if(ans<=1ll*i*h2.top()){
				ans=1ll*i*h2.top();
				tot=h2.size();
			}
		}
		cout<<ans<<" "<<tot<<endl;
	}
	return 0;
}
