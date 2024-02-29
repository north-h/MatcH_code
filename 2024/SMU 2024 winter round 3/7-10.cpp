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
struct edge{
	int i,sum;
	double ts,mj;
};
vector<edge>ans;	
int n,self,father,mother,sum[100000], fa[100000],ts[100000],mj[100000];
bool vis[100000];
int find(int x){ 
    if (x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int a,int b){
	int pa=find(fa[a]),pb=find(fa[b]);
	if(pa==pb) return;
	if(pa>pb) swap(pa,pb);
	fa[pa]=pb;
	sum[pb]+=sum[pa];
	ts[pb]+=ts[pa];
	mj[pb]+=mj[pa];
}
int main(){
	for(int i=0;i<=9999;++i) fa[i]=i,sum[i]=1;
	cin >> n;
	for (int i = 1; i <= n; i ++){
        cin >> self >> father >> mother;
		vis[self]=vis[father]=vis[mother]=1;
        if (father != -1) {
		    merge(self,father);
        } 
        if (mother != -1) {
            merge(self,mother);
        }
		int k;
        cin >> k;
		for(int i=1, x;i<=k;++i){
            cin >> x;
			vis[x]=1;
			merge(self,x);
		}
		int t, m;
        cin >> t >> m;
		ts[find(self)] += t;
		mj[find(self)]+=m;
	}
	for(int i=0;i<=9999;++i)
		if(fa[i]==i && vis[i]){
			ans.push_back({i,sum[i],(ts[i] * 1.0)/(sum[i]),(mj[i] * 1.0)/(sum[i])});
		}
	sort(ans.begin(),ans.end(),[](edge x, edge y) {
        if(x.mj==y.mj) return x.i<y.i;
	    else return x.mj>y.mj;
    });
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();++i)
		printf("%04d %d %.3lf %.3lf\n",ans[i].i,ans[i].sum,ans[i].ts,ans[i].mj);	
	return 0;
}