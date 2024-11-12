#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define eb emplace_back
#define sz(x) (int)(x).size()

//int n,k;
//void solve(){
//    cin>>n>>k;
//    map<int, int> mp1, mp2;
//    vector<int> Lt, a(n + 1);
//    map<int, vector<int>> p;
//    mp2[-1] = 0;
//    Lt.push_back(-1);
//    for (int i = 1; i <= n; i ++) cin >> a[i], mp1[a[i]] ++;
//    for (int i = 1; i <= k; i ++) {
//        int x, y; cin >> x >> y;
//        mp2[x] = y;
//        if (y == 0) Lt.push_back(x);
//    }
//    if (!mp2.count(0)) mp2[0] = n;
//    sort(Lt.begin(), Lt.end());
//    int sz = Lt.size() - 1;
//    for (int i = n, j = sz; j >= 0; ) {
//        if (i >= 0 && a[i] > Lt[j]) {
//            p[Lt[j]].push_back(a[i]);
//            i --;
//        } else j --;
//    }
////    for (auto i : Lt) cout << i << ' ';
////    cout << '\n';
////    for (auto [x, y] : p) {
////        cout << x << ":";
////        for (auto i : y) cout << i << ' ';
////        cout << '\n';
////    }
//    int ans = 0;
//    for (auto [x, y] : p) {
//        int c = 0, v = 0;
//        for (auto i : y) {
////            cout << i << ' ' << x + 2 << '\n';
////            cout << x << ' ' << x + 1 << '\n';
//            if (!mp2.count(x + 1)) mp2[x + 1] = y.size();
//            if (i >= x + 2) ans += (i - (x + 2)), c ++;
//
//        }
////        cout << c << ' ' << mp1[x + 1] << '\n';
//        int cc = mp2[x + 1] - mp1[x + 1], vv = mp1[x];
//        ans += cc;
////        cout << ans << '\n';
//    }
////    cout << ans << '\n';
//    if (ans & 1) cout << "Pico\n";
//    else cout << "FuuFuu\n";
//}

typedef struct Point{
    int x,y;
}Point;
Point point[25003];
Point operator-(Point a,Point b){ return {a.x-b.x,a.y-b.y}; }
int operator^(Point a,Point b){ return a.x*b.y-a.y*b.x; }  //叉乘
int n;
int cross(Point a,Point b,Point c){ return (b-a)^(c-a); }
__int128 dist(Point a,Point b){
    __int128 zz=0;
    return zz+(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool cmp(Point a,Point b){
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
int stk[25003],top=0;
void Andrew(){
    sort(point+1,point+n+1,cmp);
    for(int i=1;i<=n;i++){
        while(top>1&&cross(point[stk[top-1]],point[stk[top]],point[i])<=0) top--;
        stk[++top]=i;
    }
    int tt=top;
    for(int i=n-1;i>=1;i--){
        while(top>tt&&cross(point[stk[top-1]],point[stk[top]],point[i])<=0) top--;
        stk[++top]=i;
    }
}
void solve(){
    cin>>n;
    top=0;
    for(int i=1;i<=n;i++) cin>>point[i].x>>point[i].y;
    Andrew();
    if(n<5){ cout<<"NO"<<endl; return; }
    if(top-1>4){
        cout<<"YES"<<endl;
        for(int i=1;i<=5;i++) cout<<point[stk[i]].x<<" "<<point[stk[i]].y<<endl;
    }
    else if(top-1==4){
        cout<<"YES"<<endl;
        vector<bool> vis(n+10,false);
        for(int i=1;i<=top;i++) vis[stk[i]]=true;
        for(int i=1;i<=n;i++) if(!vis[i]){ cout<<point[i].x<<" "<<point[i].y<<endl; break; }
        for(int i=1;i<=4;i++) cout<<point[stk[i]].x<<" "<<point[stk[i]].y<<endl;
    }
    else if(top-1==3){
        vector<bool> vis(n+10,false);
        for(int i=1;i<=top;i++) vis[stk[i]]=true;
        bool check=false;
        vector<vector<bool>> mark(5,vector<bool>(5,false));
        vector<Point> ans;
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            int c1=cross(point[stk[1]],point[stk[2]],point[i]);
            int c2=cross(point[stk[2]],point[stk[3]],point[i]);
            int c3=cross(point[stk[3]],point[stk[4]],point[i]);
            if( (c1>0) == (c2>0) && (c1>0)==(c3>0) && (c2>0)==(c3>0) ){ //在三角形内
                check=true,vis[i]=true;
                ans.eb(point[i]);
                break;
            }
        }
        if(check){ //必然有解
            for(int i=1;i<=n;i++){
                if(vis[i]) continue;
                for(int j=1;j<=3;j++){
                    if(mark[j][j+1]) continue;
                    if(cross(point[stk[j]],point[stk[j+1]],point[i])==0){
                        mark[j][j+1]=true,vis[i]=true;
                        ans.emplace_back(point[i]);
                        break;
                    }
                }
                if(sz(ans)==2) break;
            }
            if(sz(ans)==2){
                cout<<"YES"<<endl;
                cout<<ans[0].x<<" "<<ans[0].y<<endl;
                cout<<ans[1].x<<" "<<ans[1].y<<endl;
                for(int j=1;j<=3;j++) cout<<point[stk[j]].x<<" "<<point[stk[j]].y<<endl;
            }
            else{
                cout<<"YES"<<endl;
                for(int i=1;i<=n;i++){
                    if(vis[i]) continue;
                    int c1=cross(point[stk[1]],ans[0],point[i]);
                    int c2=cross(point[stk[2]],ans[0],point[i]);
                    int c3=cross(point[stk[3]],ans[0],point[i]);
                    if(c1!=0&&c2!=0&&c3!=0){
                        ans.eb(point[i]);
                        cout<<ans[0].x<<" "<<ans[0].y<<endl;
                        cout<<ans[1].x<<" "<<ans[1].y<<endl;
                        for(int j=1;j<=3;j++) cout<<point[stk[j]].x<<" "<<point[stk[j]].y<<endl;
                    }
                    else if(c1==0){
                        __int128 dis1=dist(point[stk[1]],point[i]);
                        __int128 dis2=dist(point[stk[1]],ans[0]);
                        if(dis1>dis2){
                            cout<<ans[0].x<<" "<<ans[0].y<<endl;
                            cout<<point[i].x<<" "<<point[i].y<<endl;
                            for(int j=1;j<=3;j++) cout<<point[stk[j]].x<<" "<<point[stk[j]].y<<endl;
                        }
                        else{
                            cout<<point[i].x<<" "<<point[i].y<<endl;
                            cout<<ans[0].x<<" "<<ans[0].y<<endl;
                            for(int j=1;j<=3;j++) cout<<point[stk[j]].x<<" "<<point[stk[j]].y<<endl;
                        }
                    }
                    else if(c2==0){
                        __int128 dis1=dist(point[stk[2]],point[i]);
                        __int128 dis2=dist(point[stk[2]],ans[0]);
                        if(dis1>dis2){
                            cout<<ans[0].x<<" "<<ans[0].y<<endl;
                            cout<<point[i].x<<" "<<point[i].y<<endl;
                            for(int j=1;j<=3;j++) cout<<point[stk[j]].x<<" "<<point[stk[j]].y<<endl;
                        }
                        else{
                            cout<<point[i].x<<" "<<point[i].y<<endl;
                            cout<<ans[0].x<<" "<<ans[0].y<<endl;
                            for(int j=1;j<=3;j++) cout<<point[stk[j]].x<<" "<<point[stk[j]].y<<endl;
                        }
                    }
                    else if(c3==0){
                        __int128 dis1=dist(point[stk[3]],point[i]);
                        __int128 dis2=dist(point[stk[3]],ans[0]);
                        if(dis1>dis2){
                            cout<<ans[0].x<<" "<<ans[0].y<<endl;
                            cout<<point[i].x<<" "<<point[i].y<<endl;
                            for(int j=1;j<=3;j++) cout<<point[stk[j]].x<<" "<<point[stk[j]].y<<endl;
                        }
                        else{
                            cout<<point[i].x<<" "<<point[i].y<<endl;
                            cout<<ans[0].x<<" "<<ans[0].y<<endl;
                            for(int j=1;j<=3;j++) cout<<point[stk[j]].x<<" "<<point[stk[j]].y<<endl;
                        }
                    }
                    break;
                }
            }
        }
        else{  //还不知道是否有解
            for(int i=1;i<=n;i++){      //是否存在点在凸包的边上.
                if(vis[i]) continue;
                for(int j=1;j<=3;j++){
                    if(mark[j][j+1]) continue;
                    if(cross(point[stk[j]],point[stk[j+1]],point[i])==0){
                        mark[j][j+1]=true;
                        ans.emplace_back(point[i]);
                        break;
                    }
                }
                if(sz(ans)==2) break;
            }
            if(sz(ans)==2){
                cout<<"YES"<<endl;
                cout<<ans[0].x<<" "<<ans[0].y<<endl;
                cout<<ans[1].x<<" "<<ans[1].y<<endl;
                for(int j=1;j<=3;j++) cout<<point[stk[j]].x<<" "<<point[stk[j]].y<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
    else cout<<"NO"<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
