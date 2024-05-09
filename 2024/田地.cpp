#include<iostream>
#include<cstring>
#include<vector>
#include<numeric>
#include<functional>
using namespace std;
using LL = long long;

const LL INF = 1e18;
struct Info{
    LL mx = -INF, mn = INF;
    int mnpos = -1;
    LL ans1 = -INF, ans2 = -INF;
};

using Tag = LL;

Info operator+(const Info &a, const Info &b){
    Info ret = Info();
    ret.mx = max(a.mx, b.mx);
    ret.mn = min(a.mn, b.mn);
    if (a.mn < b.mn) ret.mnpos = a.mnpos;
    else ret.mnpos = b.mnpos;
    ret.ans1 = max(a.ans1, b.ans1);
    ret.ans1 = max(ret.ans1, b.mx * 2 - a.mn);
    ret.ans2 = max(a.ans2, b.ans2);
    ret.ans2 = max(ret.ans2, a.mx * 2 - b.mn);
    return ret;
}

void apply(Info &x, Tag &a, Tag f){
    x.mx += f;
    x.mn += f;
    x.ans1 += f;
    x.ans2 += f;
    a += f;
}

template<class Info, class Tag>
struct LazySegmentTree{
    int n;
    vector<Info> info;
    vector<Tag> tag;

    LazySegmentTree() {}

    LazySegmentTree(int n, Info _init = Info()){
        init(vector<Info>(n, _init));
    }

    LazySegmentTree(const vector<Info> &_init){
        init(_init);
    }

    void init(const vector<Info> &_init){
        n = (int)_init.size();
        info.assign((n << 2) + 1, Info());
        tag.assign((n << 2) + 1, Tag());
        function<void(int, int, int)> build = [&](int p, int l, int r){
            if (l == r){
                info[p] = _init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m + 1, r);
            pull(p);
        };
        build(1, 0, n - 1);
    }
    
    void pull(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    
    void apply(int p, const Tag &v){
        ::apply(info[p], tag[p], v);
    }
    
    void push(int p){
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    
    void modify(int p, int l, int r, int x, const Info &v){
        if (l == r){
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x <= m){
            modify(2 * p, l, m, x, v);
        } 
        else{
            modify(2 * p + 1, m + 1, r, x, v);
        }
        pull(p);
    }
    
    void modify(int p, const Info &v){
        modify(1, 0, n - 1, p, v);
    }
    
    Info query(int p, int l, int r, int x, int y){
        if (l > y || r < x){
            return Info();
        }
        if (l >= x && r <= y){
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m + 1, r, x, y);
    }
    
    Info query(int l, int r){
        return query(1, 0, n - 1, l, r);
    }
    
    void modify(int p, int l, int r, int x, int y, const Tag &v){
        if (l > y || r < x){
            return;
        }
        if (l >= x && r <= y){
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        modify(2 * p, l, m, x, y, v);
        modify(2 * p + 1, m + 1, r, x, y, v);
        pull(p);
    }
    
    void modify(int l, int r, const Tag &v){
        return modify(1, 0, n - 1, l, r, v);
    }
};

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        int n, q;
        cin >> n >> q;
        vector<LL> s(n + 1), a(n + 1);
        vector<Info> init(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s[i] = s[i - 1] + a[i];
        }
        for(int i = 0; i <= n; i++){
            init[i] = {s[i], s[i], i, -INF, -INF};
        }
        LazySegmentTree<Info, Tag> seg(init);
    
        while(q--){
            int op, x, y;
            cin >> op >> x >> y;
            if (op == 1){
                seg.modify(x, n, y - a[x]);
                a[x] = y;
            }
            else{
                auto res = seg.query(x - 1, y);
                LL mx1 = seg.query(res.mnpos + 1, y).ans2;
                LL mx2 = seg.query(x - 1, res.mnpos - 1).ans1;
                LL ans = max(mx1, mx2) - res.mn;
                {
                    LL t = 2 * res.mn;
                    t -= seg.query(x - 1, res.mnpos - 1).mn;
                    t -= seg.query(res.mnpos + 1, y).mn;
                    ans = max(ans, t);
                }
                cout << ans << '\n';
            }
        }
    }

}