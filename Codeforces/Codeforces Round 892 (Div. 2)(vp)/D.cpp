/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-14 18:28:26
 * Problem :
 * =====================================
 *                   _   _         _
 *  _ __   ___  _ __| |_| |__     | |__
 * | '_ \ / _ \| '__| __| '_ \    | '_ \
 * | | | | (_) | |  | |_| | | |   | | | |
 * |_| |_|\___/|_|   \__|_| |_|___|_| |_|
 *                           |_____|
 */

#pragma GCC optimize(3)

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PDD pair<double,double>
#define PCI pair<char,int>
#define PSI pair<string,int>
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()
#define int128 __int128
#define endl '\n'
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

struct S {
    int l, r, x, y;
};

void solve() {
    vector<S> a;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        a.push_back({l, r, x, y});
    }
    int q;
    cin >> q;
    vector<int> ask(q);
    for(auto &i : ask)cin >> i;
    sort(a.begin(), a.end(), [](S a, S b) {
        if(a.l != b.l)return a.l < b.l;
        else if(a.r != b.r)return a.r < b.r;
        else if(a.x != b.x)return a.x < b.x;
        return a.y < b.y;
    });
    int pl = a[0].l, pr = a[0].r;
    int sl = a[0].x, sr = a[0].y;
    vector<S> ans;
    for(int i = 1; i < n; i++) {
        if(a[i].l <= pr && sr >= a[i].l) {
            pl = min(pl, a[i].l);
            pr = max(pr, a[i].r);
            sl = min(sl, a[i].x);
            sr = max(sr, a[i].y);
        } else {
            ans.push_back({pl, pr, sl, sr});
            pl = a[i].l;
            pr = a[i].r;
            sl = a[i].x;
            sr = a[i].y;
        }
    }

    ans.push_back({pl, pr, sl, sr});
    auto check = [&](int x, int goal) {
        if(goal >= ans[x].l)return true;
        return false;
    };
    for(auto i : ask) {
        int l = 0, r = ans.size() - 1, res = -1;
        while(l <= r) {
            int mid = l + r >> 1;
            if(check(mid, i))l = mid + 1, res = mid;
            else r = mid - 1;
        }
        if(res == -1)cout << i << ' ';
        else cout << max(ans[res].y, i) << ' ';
    }
    cout << endl ;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}