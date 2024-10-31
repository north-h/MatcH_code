#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

//int n,m,k;
//typedef struct node{
//    int star,id;
//    int sum=0;
//    vector<int> v;
//}node;
//bool cmp1(node a,node b){
//    if(a.star!=b.star) return a.star<b.star;
//    return a.sum<b.sum;
//}
//bool cmp2(node a,node b){ return a.id<b.id; }
//void solve(){
//    cin>>n>>m>>k;
//    vector<node> vct(n);
//    for(int i=0;i<n;i++){
//        cin>>vct[i].star;
//        vct[i].id=i;
//        for(int j=0;j<m;j++){
//            int x; cin>>x;
//            vct[i].v.emplace_back(x);
//            if(x!=-1) vct[i].sum+=x;
//        }
//    }
//    sort(vct.begin(),vct.end(),cmp1);
//    for(int j=0;j<m;j++) if(vct[0].v[j]==-1) vct[0].v[j]=0;
//    for(int i=1;i<n;i++){
//        if(vct[i].sum>vct[i-1].sum||vct[i].star==vct[i-1].star&&vct[i].sum==vct[i-1].sum){
//            for(int f=0;f<m;f++) {
//                if(vct[i].v[f]==-1) {
//                    vct[i].v[f]=0;
//                }
//            }
//        }
//            //wa:
//            //排序之后有:
//            //1 20
//            //2 10
//            //2 15  这个应该改成20,而不是21
//            //2 25
//        else if(vct[i].star==vct[i-1].star&&vct[i].sum<vct[i-1].sum){  ////这里要判断,改到相等即可!!
//            int dif=vct[i-1].sum-vct[i].sum;
//            for(int j=0;j<m;j++){
//                if(vct[i].v[j]==-1){
//                    if(dif==0) vct[i].v[j]=0;
//                    else if(dif<=k) vct[i].v[j]=dif,vct[i].sum+=dif,dif=0;
//                    else vct[i].v[j]=k,vct[i].sum+=k,dif-=k;
//                }
//            }
//            if(dif!=0){ cout<<"No"<<endl; return; }
//        }
//        else{
//            int dif=vct[i-1].sum-vct[i].sum;
//            for(int j=0;j<m;j++){
//                if(vct[i].v[j]==-1){
//                    if(dif==0) vct[i].v[j]=1,vct[i].sum++,dif--;
//                    else if(dif==-1) vct[i].v[j]=0;
//                    else if(dif+1<=k) vct[i].v[j]=dif+1,vct[i].sum+=dif+1,dif=-1;
//                    else vct[i].v[j]=k,vct[i].sum+=k,dif-=k;
//                }
//            }
//            if(dif!=-1){ cout<<"No"<<endl; return; }
//        }
//    }
//    cout<<"Yes"<<endl;
//    sort(vct.begin(),vct.end(),cmp2);
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            cout<<vct[i].v[j]<<" ";
//        }
//        cout<<endl;
//    }
//}

//typedef struct Point{
//    int x,y;
//}Point;
//Point point[2*100005];
//Point operator-(Point a,Point b){ return {a.x-b.x,a.y-b.y}; }
//__int128 operator^(Point a,Point b){
//    __int128 x1=a.x,y1=a.y,x2=b.x,y2=b.y;
//    return x1*y2-y1*x2;
//}
//__int128 cross(Point a,Point b,Point c){ return (b-a)^(c-a); }
//__int128 dist(Point a,Point b){ return  (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); }
//int n;
//__int128 ans=0;
//int x0,yy0,r;
//void rotating_calipers(){  //逆时针
//    __int128 sum=0;
//    for(int i=0,j=1;i<2*n;i++){
//        j=max(j,i+1);
//        while( j+1<2*n && cross(point[i],point[j+1],{x0,yy0})*cross(point[i],point[j+1],{x0,yy0})>=r*r*dist(point[i],point[j+1])
//               && (cross(point[i],point[i+1],{x0,yy0})>0)==(cross(point[i],point[j+1],{x0,yy0})>0) ){
//            ++j;
//            __int128 S=cross(point[i],point[j-1],point[j]);
//            sum+=S;
//        }
//        ans=max(ans,sum);
//        sum-=cross(point[i],point[i+1],point[j]);
//    }
//}
////警钟长鸣:全部都开__int128!!!然后可以通过平方避免开根号带来的小数,然后移项,避免除法带来的小数!!
////Italian Cuisine
////https://codeforces.com/gym/105386
//void write(__int128 x){
//    if(x>9) write(x/10);
//    putchar(x%10+'0');
//}
//void solve(){
//    cin>>n>>x0>>yy0>>r;
//    for(int i=0;i<n;i++) cin>>point[i].x>>point[i].y;
//    for(int i=n;i<2*n;i++) point[i]=point[i-n];
//    ans=0;
//    rotating_calipers();
//    write(ans);
//    puts("");
//}

//int n,k;
////得"发现"前缀gcd的种类数是不多的.2*3*4*5*6*7...增长的非常快.
////那么可以枚举gcd的种类,并且每种种类取最长的前缀.然后依次从后枚举改多少个,再维护一个后缀gcd来优化.
////Relearn through Review
////https://codeforces.com/gym/105386/problem/E
//void solve(){       //枚举+贪心
//    cin>>n>>k;
//    vector<int> arr(n+10);
//    vector<int> suf(n+10,0);
//    for(int i=1;i<=n;i++) cin>>arr[i];
//    for(int i=n;i>=1;i--) suf[i]=gcd(suf[i+1],arr[i]);
//    int ans=suf[1],gccd=0;
//    ////令人害怕的双重循环..但是实际上第二重循环执行的次数是不到20次的;
//    ////因为2*3*4*5*6*7...增长的非常快.gcd的种类数不多
//    for(int i=1;i<=n;i++){
//        if(gccd==gcd(gccd,arr[i])) continue;
//        //第一次是从头开始枚举修改.
//        int temp=gccd;
//        for(int j=i;j<=n;j++) temp=gcd(temp,arr[j]+k),ans=max(ans,gcd(temp,suf[j+1]));
//        gccd=gcd(gccd,arr[i]);
//    }
//    cout<<ans<<endl;
//}

typedef struct node1{
    int to,company,len;
}node1;
typedef struct node2{
    int id,len;
}node2;
typedef struct node3{
    int id,from,left;
    //wrong1:已经重载运算符了,不用再存负的了!!
    bool operator<(const node3 x) const{
        if(x.id!=id) return id>x.id;
        return left<x.left;
    }
}node3;
typedef struct node4{
    int id,company,left;
}node4;
int n,m,k;
vector<bool> ans(500005,false);
vector<node1> vct[500005];     //<to,company,len>
vector<node2> ticket[500005];  //<id,len>
vector<node4> dis(500005);  //<id,company,left>
//关键在于实现:o(logn)的复杂度在下标为[l,r]的,数字无序的区间找到第一个大于x的数字的位置,并且要维护5e5个不同这样的数组.
//完全想到了是最短路,按id为第一关键字,id相等的话剩下的路程为第二关键字.
//然后用st表+二分来维护.
//但是问题是怎么定义这个st表?按理来说是三维的st[500005][500005][22],其中第二维是动态的,但是怎么定义?
//定义一个结构体,然后用resize()...真晕了,定义出这个st数组.看了题解是用结构体和resize()定义出的.
typedef struct mySt{
    vector<vector<int>> f; //后两维定义在这里.
    int nn;
    void init(vector<node2> &ticket0){
        nn=(int)ticket0.size();//先给nn赋值!
        f.resize(nn+5,vector<int>(22,0));
        for(int i=0;i<nn;i++) f[i][0]=ticket0[i].len;
        for(int j=1;j<=20;j++){
            for(int i=0;i+(1ll<<j)-1<=nn-1;i++){  //wrong2:不是小于nn-1!! 得取等!!
                f[i][j]=max(f[i][j-1],f[i+(1ll<<j)][j-1]);
            }
        }
    }
    int query(int l,int r){
        int kk=log2(r-l+1);
        int res=max(f[l][kk],f[r-(1ll<<kk)+1][kk]);
        return res;
    }
}mySt;
mySt st[500005];
void myClear(){
    for(int i=1;i<=n;i++) {
        vct[i].clear(),ans[i]=false;
        dis[i]={INT_MAX,-1,-1};
    }
}
//The Quest for El Dorado
//https://codeforces.com/gym/105386/problem/J
void solve(){
//    cout<<5e5*(log2(5e5)+log2(5e5));
    cin>>n>>m>>k;
    myClear();
    for(int i=1;i<=m;i++){
        ticket[i].clear(); //clear
        int u,v,company,len;
        cin>>u>>v>>company>>len;
        vct[u].emplace_back(node1{v,company,len});
        vct[v].emplace_back(node1{u,company,len});
    }
    int len0=0,company0=0;
    for(int i=1;i<=k;i++){
        int company,len;
        cin>>company>>len;
        if(i==1) len0=len,company0=company;
        ticket[company].emplace_back(node2{i,len});
    }
    for(int i=1;i<=m;i++){    //初始化每个公司的st表.
        if(ticket[i].empty()) continue;
        st[i].init(ticket[i]);
    }
    priority_queue<node3> pq;   //node3<-id,from,left>
    dis[1]={1,company0,len0};
    pq.emplace(node3{1,1,len0});
    while(!pq.empty()){
        int from=pq.top().from;
        pq.pop();
        if(ans[from]) continue;
        ans[from]=true;
        int id0=dis[from].id,com0=dis[from].company,left0=dis[from].left;
        for(auto v:vct[from]){
            int to=v.to,company=v.company,len=v.len;
            if(id0==dis[to].id&&com0==company&&left0-len>=dis[to].left){
                dis[to].id=id0;
                dis[to].company=com0;
                dis[to].left=left0-len;
                pq.emplace(node3{dis[to].id,to,dis[to].left});
            }
            else if(id0<dis[to].id&&com0==company&&left0>=len){
                dis[to].id=id0;
                dis[to].company=com0;
                dis[to].left=left0-len;
                pq.emplace(node3{dis[to].id,to,dis[to].left});
            }
            else{
                int l=0,r=(int)ticket[company].size()-1,idx=-1;
                while(l<=r){       //在当前company中找到第一个大于当前id的位置
                    int mid=(l+r)>>1;
                    if(ticket[company][mid].id>id0){ //不能取等!!
                        idx=mid;
//                        finIdx=ticket[company][mid].id;//wrong3:finIdx不是在这里!!
                        r=mid-1;
                    }
                    else l=mid+1;
                }
                if(idx==-1) continue;
                int idx2=-1,len2=-1,finIdx=-1;
                l=idx,r=st[company].nn-1;    //在当前company中找到第一个大于等于当前len的位置.
                while(l<=r){
                    int mid=(l+r)>>1;
                    if(st[company].query(idx,mid)>=len){
                        idx2=mid;
                        finIdx=ticket[company][mid].id;//finIdx应该在这里!!
                        r=mid-1;
                    }
                    else l=mid+1;
                }
                if(idx2==-1) continue;
                len2=st[company].query(idx,idx2);
                if(finIdx<dis[to].id){
                    dis[to].id=finIdx;
                    dis[to].left=len2-len;
                    //wrong4:这里忘记更新company了!!...
                    //wrong5:这里不是com0,是company!!
                    dis[to].company=company;
                    pq.emplace(node3{dis[to].id,to,dis[to].left});
                }
                else if(finIdx==dis[to].id&&len2-len>=dis[to].left){
                    dis[to].left=len2-len;
                    //wrong4:这里忘记更新company了!!...
                    //wrong5:这里不是com0,是company!!
                    dis[to].company=company;
                    pq.emplace(node3{dis[to].id,to,dis[to].left});
                }
            }
        }
    }
    for(int i=1;i<=n;i++) ans[i]?cout<<"1":cout<<"0";
    cout<<endl;
}
//hack: expect:11111110  output:11111000
//1
//8 9 5
//1 5 2 40
//1 2 1 30
//2 3 1 20
//2 4 5 20
//3 4 3 20
//4 8 2 30
//4 6 3 50
//6 7 3 20
//5 6 2 15
//1 49
//2 55
//3 20
//5 20
//3 20

signed main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
