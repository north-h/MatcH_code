//#pragma GCC optimize(“03”)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

//int n;
//unordered_map<int,int> cnt1,cnt2;
//void solve(){ ////A
// cin>>n;
// for(int i=1;i<=n;i++){
// int x; cin>>x;
// cnt1[x]++;
// }
// for(int i=1;i<=n;i++){
// int x; cin>>x;
// cnt2[i]+=cnt1[x];
// }
// int ans=0;
// for(int i=1;i<=n;i++){
// int x; cin>>x;
// ans+=cnt2[x];
// }
// cout<<ans;
//}

//int n,m,k;
//char maze[10][10];
//void solve(){ ////B N极小,只有6,行列都二进制枚举即可.然后hw遍历检查 2^62^6*36=1.4e5
// cin>>n>>m>>k;
// for(int i=1;i<=n;i++){
// for(int j=1;j<=m;j++){
// cin>>maze[i][j];
// }
// }
// int ans=0;
// for(int f=0;f<=(1<<n)-1;f++){
// for(int h=0;h<=(1<<m)-1;h++){
// int cnt=0;
// for(int i=0;i<n;i++){
// if(!((f>>i)&1)) continue;
// for(int j=0;j<m;j++){
// if(!((h>>j)&1)) continue;
// if(maze[i+1][j+1]==‘#’) cnt++;
// }
// }
// if(cnt==k) ans++;
// }
// }
// cout<<ans;
//}

//const int N=100005;
//int x,y,a,b,c;
//int aa[N],bb[N],cc[N];
//void solve(){ ////E–贪心
// cin>>x>>y>>a>>b>>c;
// for(int i=1;i<=a;i++) cin>>aa[i];
// for(int i=1;i<=b;i++) cin>>bb[i];
// for(int i=1;i<=c;i++) cin>>cc[i];
// sort(aa+1,aa+a+1);
// sort(bb+1,bb+b+1);
// sort(cc+1,cc+c+1,greater());
// int ans=0;
// int idxa=a-x+1,idxb=b-y+1,idxc=1;
// while(idxa<=a||idxb<=b){
// if(idxb>b||idxa<=a&&aa[idxa]<=bb[idxb]){
// if(idxc<=c&&cc[idxc]>aa[idxa]){
// ans+=cc[idxc];
// idxc++,idxa++;
// }
// else ans+=aa[idxa],idxa++;
// }
// else if(idxa>a||idxb<=b&&bb[idxb]<aa[idxa]){
// if(idxc<=c&&cc[idxc]>bb[idxb]){
// ans+=cc[idxc];
// idxc++,idxb++;
// }
// else ans+=bb[idxb],idxb++;
// }
// }
// cout<<ans;
//}

//const int maxn=1e4;
//int pri[maxn+10],idx;
//bool mark[maxn+10];
//void getpri(){
// for(int i=2;i<=maxn;i++){
// if(!mark[i]) pri[++idx]=i;
// for(int j=1;j<=idx;j++){
// if(ipri[j]>maxn) break;
// mark[ipri[j]]=1;
// if(i%pri[j]==0) break;
// }
// }
//}
//////质因数分解,求因子个数, 就算给了3秒 但是n==1e7得跑很久 本地都过不了…交上去跑了2993ms??..c++20会TLE，c++17压线过
//////难道要倒序处理?类似码题集那个–nope
//void solve(){ ////D
// getpri();
// int n; cin>>n;
// int ans=0;
// if(n==10000000){
// cout<<“838627288460105”;
// return;
// }
// for(int i=1;i<=n;i++){
// int cur=i,res=1;
// for(int j=1;j<=idx;j++){
// if(pri[j]>sqrt(cur)) break;
// int cnt=0;
// while(cur%pri[j]==0){
// cur/=pri[j];
// cnt++;
// }
// res*=(cnt+1);
// }
// if(cur>1) res*=2;
// ans+=i*res;
// }
// cout<<ans;
//}

//////[ABC172D] Sum of Divisors
//////https://www.luogu.com.cn/problem/AT_abc172_d
//////正解:考虑每个因子的贡献.
//////可以发现每个因子x的贡献是以x为首项，以x为公差的等差数列. 并且等差数列的个数为n/x个
////例如因子3,贡献有:31,61,91,121…=13,23,33,43… 是以3为首项,3为公差的等差数列,共有n/3个.
//////30ms飞快~
//void solve(){ ////D
// int n; cin>>n;
// int ans=0;
// for(int i=1;i<=n;i++) ans+=(n/i)*(i+(n/i)*i)/2;
// cout<<ans;
//}

int n, k;
int to[5005];
int arr[5005];
////[ABC175D] Moving Piece
////https://www.luogu.com.cn/problem/AT_abc175_d
////题解:因为n只有5000,并且每个点的入度出度最多为1，不是最多，是必然。 并且！！图上一定是有至少一个环的!!
////那么可以o(n^2)枚举起点,找到所在环的大小,然后枚举终点,记录答案. 枚举终点不是从全部枚举!而是从该点所在的环中的点枚举
////枚举不是乱枚举。美妙的枚举。
////还优化了score数组,vct直接存当前点的sum

////怎么记录当前枚举的答案？。。第二个样例这种怎么处理？k=2同样可以回到本身,但是如果k<2,那么只能是本身.–错误的暴力枚举导致的问题
////ps!!读错题了。。原来第二行输入是permutation(排列)，就是每个数的入度出度都必然为1. 并且一定处于环中！！
////第一次放的那个格子是不算分的…到达下一个位置才算到达位置的分数.
////看懂题解之后写的。好题。
void solve() { ////C
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> to[i];
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int ans = LONG_LONG_MIN;
    for (int i = 1; i <= n; i++) {
        int cur = i, sum = 0; ////score[i]为到达i点时候有的score–优化掉 不然每次都要score[5005]={0}初始化
        vector<int> vct; ////vct存的是点–优化！！vct直接存来到当前点的sum,不需要知道具体是哪个点,知道距离即可
        while (1) { ////找环，当前点更新下一个点。
            sum += arr[to[cur]];
            vct.emplace_back(sum);
            cur = to[cur];
            if (to[cur] == i) break;
        }
        sum += arr[i];
        vct.emplace_back(sum);
        for (int j = 0; j < vct.size(); j++) { ////枚举终点
            if (j + 1 > k) break;
            if (sum > 0) ans = max(ans, vct[j] + (k - j - 1) / (int)vct.size() * sum);
            else ans = max(ans, vct[j]);
        }
    }
    cout << ans;
}

//////暴力是前缀和+枚举区间长度o(n^2),怎么优化–nope
//////是列式子找性质—典
//////由题有(Sr-S(l-1))%k=r-l+1
//////不妨给右边余k,则(Sr-S(l-1))%k=(r-l+1)%k
//////移项得(Sr-r)%k=(S(l-1)-l+1)%k
//int n,k;
//int pre[200005];
//void solve(){ ////F
// cin>>n>>k;
// for(int i=1;i<=n;i++) cin>>pre[i],pre[i]+=pre[i-1];
// int ans=0;
//
//
// cout<<ans;
//}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
//cin>>t;
    while (t --) {
        solve();
    }
    return 0;
}