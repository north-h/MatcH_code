//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define db double
#define vv vector
#define ll long long
#define lll __int128
const ll modd=998244353;
const ll inf=1e9;
inline ll qpow(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1)res=res*a%modd;
        a=a*a%modd;b>>=1;
    }
    return res;
}
inline ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    ll d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
namespace Fio {
    inline string sread() {
        string s=" ";char e=getchar();
        while(e=='\n')e=getchar();
        while(e!='\n')s+=e,e=getchar();
        return s;
    }
    inline void swrite(string s){
        for(char e:s)putchar(e);
        printf("\n");
    }
    inline ll read() {
        ll x=0,y=1;char c=getchar();
        while(!isdigit(c)){if(c=='-')y=-1;c=getchar();}
        while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
        return x*=y;
    }
    inline void write(ll x) {
        if(x<0)x=-x,putchar('-');ll sta[35],top=0;
        do sta[top++]=x%10,x/=10;while(x);
        while(top)putchar(sta[--top]+'0');
    }
}using namespace Fio;
// mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<ll> rd(0,1e18);
// inline ll rnd(){return rd(gen);}



inline void qfl_zzz(){
    ll n,s=0;cin>>n;
    vv<vv<ll>> a(n+1,vv<ll>(n+1));
    vv<pair<ll,ll>> b;
    for(ll i=n;i>=1;--i){
        for(ll j=1;j<=n;++j){
            a[i][j]=a[j][i]=j;
        }
        b.push_back({1,i});
        b.push_back({2,i});
    }
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j){
            s+=a[i][j];
        }
    cout<<s<<" "<<b.size()<<"\n";
    for(ll i=0;i<b.size();++i){
        cout<<b[i].first<<" "<<b[i].second<<" ";
        for(ll j=1;j<=n;++j){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}                       
inline void pre_work(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    //cout<<setiosflags(ios::fixed)<<setprecision(3);

#ifdef LOCAL
    freopen("oo.in","r",stdin);
    freopen("oo.out","w",stdout);
#endif

    pre_work();

    int T=1;
    cin>>T;
    //T=read();
    while(T--)qfl_zzz();

    return 0;
}