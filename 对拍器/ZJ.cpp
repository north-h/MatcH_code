#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long
//#define endl "\n"
using ll=long long;

//ll n;
//void solve(){
//    string s; cin >> n >> s; s=" "+s;
//    string ans;
//    for(int i=1;i<=n;i++){
//        int g[27]={0},f[27]={0},cnt=0;
////        if(i==3) cout << g[1] << g[3] << "\n";
//        for(int j=i;j;j--) if(!f[s[j]-'a'+1]){
//            g[s[j]-'a'+1]=cnt++;
//            f[s[j]-'a'+1]=1;
////            if(i==3) cout << s[j]-'a'+1 << "\n";
//            if(cnt==26) break;
//        }
////        if(i==3) cout << g[1] << g[3] << "\n";
//        string ts;
//        for(int j=1;j<=i;j++) ts+=(char)('a'+g[s[j]-'a'+1]);
//        ans=max(ts,ans);
////        cout << ts << "\n";
//    }
//    cout << ans;
//}

const int N=1e5+10;
//int dis[N];
//void bfs(){
//    memset(dis,-1,sizeof dis);
//    queue<int>qu;
//    qu.push(0);
//    dis[0]=0;
//    while(!qu.empty()){
//        int num=qu.front(); qu.pop();
//        int a[5]={0};
//        int tnum=num;
//        for(int i=4;i;i--) a[i]=tnum%10,tnum/=10;
//        for(int i=1;i<=4;i++){
//            for(int j=i;j<=4;j++){
//                int num1=0,num2=0;
//                for(int k=1;k<=4;k++){
//                    if(k>=i && k<=j) num1=num1*10+(a[k]+1)%10,num2=num2*10+(a[k]+9)%10;
//                    else num1=num1*10+a[k],num2=num2*10+a[k];
//                }
//                if(dis[num1]==-1) dis[num1]=dis[num]+1,qu.push(num1);
//                if(dis[num2]==-1) dis[num2]=dis[num]+1,qu.push(num2);
//            }
//        }
//    }
//}
//void solve(){
//    bfs();
//    int tc; cin >> tc;
//    while(tc--){
//        string s,tos; cin >> s >> tos;
//        int a[5]={0},b[5]={0};
//        for(int i=0;i<4;i++) a[i+1]=s[i]-'0'+1,b[i+1]=tos[i]-'0'+1;
//        int num=0;
//        for(int i=1;i<=4;i++) num=num*10+(b[i]-a[i]+10)%10;
//        cout << dis[num] << "\n";
////        cout << num << "\n";
//    }
////    cout << dis[7];
//}

int n, m;
vector<pair<int, int>> g[N];
int x[N * 2], y[N * 2], z[N * 2];
int vis[N], vi[N];
bool ok;

int bfs(int u) {
    vector<int> d(n + 1);queue<int> q;
    q.push(u);vis[u] = 1;d[u] = 0;
    while (q.size()) {
        auto t = q.front(); q.pop();
        for (auto [x, y] : g[t]) {
            if (vis[x]) {
                if (y == 1 && d[x] == d[t]) {
                    ok = true;
                    return -1;
                } else if (y == 0 && d[x] != d[t]) {
                    ok = true;
                    return -1;
                }
            } else {
                if (y == 1) d[x] = d[t] ^ 1;
                else d[x] = d[t];
                q.push(x);
                vis[x] = 1;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i ++) sum += d[i];
    return sum;
}

int bfs1(int u) {
    vector<int> d(n + 1);queue<int> q;
    q.push(u);vi[u] = 1;d[u] = 1;
    while (q.size()) {
        auto t = q.front();q.pop();
        for (auto [x, y] : g[t]) {
            if (vi[x]) {
                if (y == 1 && d[x] == d[t]) {
                    ok = true;
                    return -1;
                } else if (y == 0 && d[x] != d[t]) {
                    ok = true;
                    return -1;
                }
            } else {
                if (y == 1) d[x] = d[t] ^ 1;
                else d[x] = d[t];
                q.push(x);
                vi[x] = 1;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i ++) sum += d[i];
    return sum;
}

void solve() {
    cin >> n >> m;
//    map<pair<int, int>, int> mp;
    unordered_map<int, unordered_map<int, int>> mp;
    for (int i = 1; i <= m; i ++) {
        int u, v, w; cin >> u >> v >> w;
        x[i] = u, y[i] = v, z[i] = w;
//        if (!mp.count({u, v})) mp[{u, v}] = w;
//        else if (mp[{u, v}] != w) ok = true;
            if (mp[u][v] == 0) mp[u][v] = w;
            else if (mp[u][v] != w) ok = true;
    }
    if (ok) {
        cout << -1 << '\n';
        return ;
    }
    int ans = 0;
    for (int i = 0; i < 30; i ++) {
        for (int j = 1; j <= n; j ++) g[j].clear();
        for (int j = 1; j <= m; j ++) {
            int u = x[j], v = y[j], w = z[j];
            if (w >> i & 1) {
                g[u].push_back({v, 1});
                g[v].push_back({u, 1});
            } else {
                g[u].push_back({v, 0});
                g[v].push_back({u, 0});
            }
        }
//        for (int j = 1; j <= n; j ++) {
//            cout << j << ":\n";
//            for (auto [x, y] : g[j]) cout << x << '|' << y << '\n';
//        }
        for (int j = 1; j <= n; j ++) vi[j] = vis[j] = 0;
        for (int j = 1; j <= n; j ++) {
            if (!vis[j]) {
//                cout << bfs(j) << ' ' << bfs1(j) << '\n';
                ans += min(bfs(j), bfs1(j)) * (1ll << i);
                if (ok) {cout << -1 << '\n'; return ;}
            }
        }
//        cout << i << ' ' << ans << ' ' << ok << endl;
    }
    if (ok) cout << -1 << '\n';
    else cout << ans << '\n';
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
