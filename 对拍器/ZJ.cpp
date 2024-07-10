#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10002
#define LD (o<<1)
#define RD (o<<1|1)
#define INF 0x7fffffff
struct Node{
    int l,r;
    int sum,sum2;
    int add,mul;
};
int n;
struct Tree{
    Node t[N<<2];
    int a[N];
    inline void pushup(Node &o,Node &ld,Node &rd){
        o.sum=ld.sum+rd.sum;
        o.sum2=ld.sum2+rd.sum2;
    }
    inline void fix(Node &o,int add,int mul){
        int len=o.r-o.l+1;
        o.sum2=len*add*add+2*add*mul*o.sum+mul*mul*o.sum2;
        o.sum=add*len+mul*o.sum;

        o.add=add+mul*o.add;
        o.mul=mul*o.mul;

    }
    inline void pushdown(Node &o,Node &ld,Node &rd){
        fix(ld,o.add,o.mul);
        fix(rd,o.add,o.mul);
        o.add=0;
        o.mul=1;
    }
    void build(int o,int l,int r){
        t[o].l=l;t[o].r=r;t[o].add=0,t[o].mul=1;
        if(l==r){t[o]={l,r,a[l],a[l]*a[l],0,1};return;}
        int mid=(l+r)>>1;
        build(LD,l,mid);
        build(RD,mid+1,r);
        pushup(t[o],t[LD],t[RD]);
    }
    void update(int o,int l,int r,int add,int mul){
        if(l<=t[o].l&&t[o].r<=r){
            fix(t[o],add,mul);
            return;
        }
        pushdown(t[o],t[LD],t[RD]);
        int mid=(t[o].l+t[o].r)>>1;
        if(mid>=l)update(LD,l,r,add,mul);
        if(mid<r)update(RD,l,r,add,mul);
        pushup(t[o],t[LD],t[RD]);
    }
    int query(int o,int l,int r,int op){
        if(l<=t[o].l&&t[o].r<=r) {
            if(op==1){
                return t[o].sum;
            }
            else return t[o].sum2;
        }
        pushdown(t[o],t[LD],t[RD]);
        int ans=0,mid=(t[o].l+t[o].r)>>1;
        if(mid>=l)ans+=query(LD,l,r,op);
        if(mid<r)ans+=query(RD,l,r,op);
        pushup(t[o],t[LD],t[RD]);
        return ans;
    }
}A;
signed main(){
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>A.a[i];
    A.build(1,1,n);
    int ans=0;
    while(q--){
        int op,l,r,x;
        cin>>op;
        if(op==1){
            cin>>l>>r;
            cout<<A.query(1,l,r,1)<<endl;
        }
        else if(op==2){
            cin>>l>>r;
            cout<<A.query(1,l,r,2)<<endl;
        }
        else if(op==3){
            cin>>l>>r>>x;
            A.update(1,l,r,0,x);
        }
        else{
            cin>>l>>r>>x;
            A.update(1,l,r,x,1);
        }
    }


    return 0;
}
