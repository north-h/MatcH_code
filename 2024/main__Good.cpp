#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

//int k,n,w;
//void solve(){       //A
//    cin>>k>>n>>w;  //买w根,有n元,第一根为k
//    int cost=0;
//    for(int i=1;i<=w;i++) cost+=i*k;
//    if(n>=cost) cout<<"0";
//    else cout<<cost-n;
//}

//int n,r,b;
//void solve(){       //B  模拟,改了有一会--三目运算领域大神
//    cin>>n>>r>>b;
//    if(r>b){
//        int k=r/(b+1);
//        int cnt=0,cc=1,cc2=1;
//        int left=r%(b+1);
//        for(int i=1;i<=n;i++){
//            if(cc) cout<<"R",cnt++;
//            else left&&cc2?cout<<"R",left--,cc2=false:(cout<<"B",cc^=1,cc2=true);
//            if(cnt==k) cc^=1,cnt=0;
//        }
//    }
//    else if(r==b){
//        for(int i=1;i<=n;i++) i&1?cout<<"R":cout<<"B";
//        cout<<endl;
//    }
//    else if(r<b){
//        int k=b/(r+1);
//        int cnt=0,cc=1,cc2=1;
//        int left=b%(r+1);
//        for(int i=1;i<=n;i++){
//            if(cc) cout<<"B",cnt++;
//            else left&&cc2?cout<<"B",left--,cc2=false:(cout<<"R",cc^=1,cc2=true);
//            if(cnt==k) cc^=1,cnt=0;
//        }
//    }
//    cout<<endl;
//}

//int n;
//char maze[205][205];
//int dx[4]={-1,1,0,0};
//int dy[4]={0,0,-1,1};
//bool vis[205][205];
//bool toEnd(int x0,int y0){
//    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) vis[i][j]=0;
//    queue<pair<int,int>> que;
//    que.emplace(x0,y0);
//    vis[x0][y0]=1;
//    while(que.size()){
//        int xx0=que.front().first;
//        int yy0=que.front().second;
//        que.pop();
//        if(xx0==n&&yy0==n) return true;
//        for(int i=0;i<4;i++){  ////写成了i<n..  cao了，白wa两发
//            int x=xx0+dx[i];
//            int y=yy0+dy[i];
//            if(x>=1&&x<=n&&y>=1&&y<=n&&!vis[x][y]&&(maze[xx0][yy0]=='S'||maze[xx0][yy0]==maze[x][y]||maze[x][y]=='F')){
//                que.emplace(x,y);
//                vis[x][y]=1;
//            }
//        }
//    }
//    return false;
//}
//void re(int x,int y){ maze[x][y]=='0'?maze[x][y]='1':maze[x][y]='0'; }
//void solve(){       //C  枚举封源头/终点
//    cin>>n;
//    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>maze[i][j];
//    if(!toEnd(1,1)) { cout<<"0"<<endl; return; }
//
//    re(1,2);
//    if(!toEnd(1,1)) { cout<<"1"<<endl<<"1 2"<<endl; return; }
//
//    re(1,2),re(2,1);
//    if(!toEnd(1,1)) { cout<<"1"<<endl<<"2 1"<<endl; return; }
//
//    re(2,1),re(n-1,n);
//    if(!toEnd(1,1)) { cout<<"1"<<endl<<n-1<<" "<<n<<endl; return; }
//
//    re(n-1,n),re(n,n-1);
//    if(!toEnd(1,1)) { cout<<"1"<<endl<<n<<" "<<n-1<<endl; return; }
//
//    re(n,n-1),re(1,2),re(2,1);
//    if(!toEnd(1,1)) { cout<<"2"<<endl<<"1 2"<<endl<<"2 1"<<endl; return; }
//
//    re(2,1),re(n-1,n);
//    if(!toEnd(1,1)) { cout<<"2"<<endl<<"1 2"<<endl<<n-1<<" "<<n<<endl; return; }
//
//    re(n-1,n),re(n,n-1);
//    if(!toEnd(1,1)) { cout<<"2"<<endl<<"1 2"<<endl<<n<<" "<<n-1<<endl; return; }
//
//    re(n,n-1),re(1,2),re(2,1),re(n-1,n);
//    if(!toEnd(1,1)) { cout<<"2"<<endl<<"2 1"<<endl<<n-1<<" "<<n<<endl; return; }
//
//    re(n-1,n),re(n,n-1);
//    if(!toEnd(1,1)) { cout<<"2"<<endl<<"2 1"<<endl<<n<<" "<<n-1<<endl; return; }
//
//    re(n,n-1),re(2,1),re(n-1,n),re(n,n-1);
//    if(!toEnd(1,1)) { cout<<"2"<<endl<<n-1<<" "<<n<<endl<<n<<" "<<n-1<<endl; return; }
//}

//int x;
//void solve(){       //D  简单位运算
//    cin>>x;
//    unordered_map<int,bool> mark;
//    for(int j=0;j<=20;j++) mark[(1ll<<j)-1]=true;
//    if(mark[x]){ cout<<"0"; return; }
//    vector<int> ans;
//    if(!(x%2)) ans.emplace_back(0),x++;  ////这里忘了cnt++.. cao  直接输出ans.size()*2就完事了. 白wa一发.
//    while(!mark[x]){
//        int high=0;
//        for(int j=20;j>=0;j--){
//            if((1ll<<j)<x&&!((x>>j)&1)){
//                high=j;
//                break;
//            }
//        }
//        high++;
//        ans.emplace_back(high);
//        x^=((1ll<<high)-1),x++;
//    }
//    cout<<ans.size()*2<<endl;
//    for(auto a:ans) cout<<a<<" ";
//}

//int n,m;
//int b[100005];
//int g[100005];
//void solve(){       //E  贪心  精准
//    cin>>n>>m;
//    int ans=0;
//    bool check=false;
//    int mx=0;
//    for(int i=1;i<=n;i++) cin>>b[i],mx=max(mx,b[i]);
//    for(int i=1;i<=m;i++) cin>>g[i],g[i]<mx?check=true:0;
//    if(check){ cout<<"-1"; return; }
//    sort(b+1,b+n+1,greater<int>());
//    sort(g+1,g+m+1,greater<int>());
//    int idxG=1;
//    for(int i=1;i<=n;i++){
//        int cnt=0;
//        while(idxG<=m&&b[i]<=g[idxG]&&cnt<m-1){
//            ans+=g[idxG];
//            idxG++,cnt++;
//        }
//        if(idxG<=m&&b[i]==g[idxG]) ans+=g[idxG],idxG++,cnt++;
//        ans+=b[i]*(m-cnt);
//    }
//    cout<<ans;
//}

int n, k;
int box[100005];
int dp[100005][35];  ////定义dp[i][j]:为到达第i个箱子,"前面已经使用"了j次破钥匙,可以得到最大的金币数量.
////容易发现,使用破钥匙的次数达到30次之后,剩下全部金币都为0.
void solve() {      //F
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> box[i];
    for (int i = 1; i <= n; i++) for (int j = 0; j <= 31; j++) dp[i][j] = LONG_LONG_MIN;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(30ll, i - 1); j++) {
            int num = box[i];
            num >>= j;
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + num - k);
            dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + num / 2);
            ////写代码就应该多多冗余,在中间取ans是完全没问题的
            ////所有出现过的值都是合法可取的,只要后面一直使用破钥匙,完全可以保留这个值,但是不知道为什么没有转移下去..
            ans = max(ans, dp[i][j]);
            ans = max(ans, dp[i][j + 1]);
        }
    }
    ////明明一直在转移,为什么没有转移下去??无语了
//    for(int j=0;j<=31;j++) ans=max(ans,dp[n][j]);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
