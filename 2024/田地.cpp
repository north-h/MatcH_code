#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using PII=pair<ll,ll>;

const int N=2e6+10,M=210;
const int mod=1e9+7;
ll n;
ll a[N],b[N],mib[N],sum[N];
void solve(){
    int q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
        sum[i]=sum[i-1]+b[i];
        mib[i]=b[i];
    }
    for(int i=n-1;i;i--) mib[i]=min(b[i],mib[i+1]);
    
    while(q--){
        priority_queue<PII>pq;
        set<int>st;
        int k; cin >> k;
        ll tmp=0,ans=1e18;
        for(int i=1;i<=n;i++){
            pq.push({b[i],i});
            tmp+=b[i];
            st.insert(i);
            while((int)pq.size()>k){
                tmp-=pq.top().first,pq.pop();
//              cout << pq.top().first << "\n";
                pq.pop();
            }
//          for(auto i:st) cout << i << "\n";
            if((int)pq.size()==k) ans=min(tmp+a[*(st.rbegin())],ans);
        }
        cout << ans << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int O_o=1;
//  cin >> O_o;
    while(O_o--) solve();
    return 0;
}
//make it count
//开ll plz