//#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef struct node{
    int u,v,w;
}node;
int n,m;
vector<node> edge;
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        edge.emplace_back(node{u,v,w});
    }
    int ans=0;
    for(int j=0;j<30;j++){
        vector<pair<int,int>> vct[n+5];
        for(int i=0;i<m;i++){
            int u=edge[i].u,v=edge[i].v,w=edge[i].w;
            if((w>>j)&1) vct[u].emplace_back(v,1),vct[v].emplace_back(u,1);
            else vct[u].emplace_back(v,0),vct[v].emplace_back(u,0);
        }
        vector<bool> vis0(n+5);
        vector<bool> vis1(n+5);
        vector<int> col0(n+5);
        vector<int> col1(n+5);
        int cnt0=0,cnt1=0;
        for(int i=1;i<=n;i++){
            if(!vis0[i]){
                vis0[i]=vis1[i]=true;
                col0[i]=0,col1[i]=1;
                queue<int> que1;
                que1.emplace(i);
                cnt1++;
                while(!que1.empty()){
                    int from=que1.front();
                    int color=col1[from];
                    que1.pop();
                    for(auto v:vct[from]){
                        if(!vis1[v.first]){
                            if(v.second==1){  //异色
                                que1.emplace(v.first);
                                if((color^1)==1) cnt1++;
                                col1[v.first]=color^1;
                                vis1[v.first]=true;
                            }
                            else{  //同色
                                que1.emplace(v.first);
                                if(color==1) cnt1++;
                                col1[v.first]=color;
                                vis1[v.first]=true;
                            }
                        }
                        else{
                            if(v.second==1&&col1[v.first]==color){ cout<<"-1"; return; }
                            else if(v.second==0&&col1[v.first]!=color){ cout<<"-1"; return; }
                        }
                    }
                }
                queue<int> que0;
                que0.emplace(i);
                while(!que0.empty()){
                    int from=que0.front();
                    int color=col0[from];
                    que0.pop();
                    for(auto v:vct[from]){
                        if(!vis0[v.first]){
                            if(v.second==1){  //异色
                                que0.emplace(v.first);
                                if((color^1)==1) cnt0++;
                                col0[v.first]=color^1;
                                vis0[v.first]=true;
                            }
                            else{  //同色
                                que0.emplace(v.first);
                                if(color==1) cnt0++;
                                col0[v.first]=color;
                                vis0[v.first]=true;
                            }
                        }
                        else{
                            if(v.second==1&&col0[v.first]==color){ cout<<"-1"; return; }
                            else if(v.second==0&&col0[v.first]!=color){ cout<<"-1"; return; }
                        }
                    }
                }
            }
        }
        ans+=min(cnt0*(1ll<<j),cnt1*(1ll<<j));
    }
    cout<<ans;
}

int32_t main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
