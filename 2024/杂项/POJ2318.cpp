// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

struct Point { int x, y; };

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; } //求点积，可以判断直线是否垂直

double len(Point a) { return sqrt(a.x * a.x + a.y * a.y); } //求向量的模长

double angle(Point a, Point b) { return acos(dot(a, b) / len(a) / len(b)); } //求两个向量的夹角

Point operator - (Point a, Point b) { return Point{a.x - b.x, a.y - b.y}; } //重载减号

double operator * (Point a,Point b) { return a.x * b.y - a.y * b.x; } //重载乘号

double cross(Point a, Point b, Point c) { return (b - a) * (c - a); } //求叉积，判断点线位置关系

void solve() {}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    // int h_h = 1;
    // cin >> h_h;
    // while (h_h--)solve();
    bool f = true;
    while(true) {
        int n, m, x1, y1, x2, y2;
        cin >> n;
        if(n == 0) break;
        cin >> m >> x1 >> y1 >> x2 >> y2;
        vector<Point> a(n + 1), b(n + 1);
        a[0].x = x1, a[0].y = y1, b[0].x = x1, b[0].y = y2;
        for (int i = 1; i <= n; i++) {
            int u, v;
            cin >> u >> v;
            a[i].y = y1;
            b[i].y = y2;
            a[i].x = u;
            b[i].x = v;
        }
        vector<int> ans(5010);
        while (m--) {
            Point T;
            cin >> T.x >> T.y;
            // int l = 0, r = n, res;
            // while (l <= r) {
            //     int mid = l + r >> 1;
            //     if(cross(b[mid], a[mid], T) <= 0) l = mid + 1, res = mid;
            //     else r = mid - 1;
            // }
            // debug1(res);
            // ans[res] ++;
            for (int i = 0; i <= n; i++) {
                if(i < n){
                    if(cross(b[i], a[i], T) <= 0 && cross(b[i + 1], a[i + 1], T) >= 0){
                        ans[i] ++;
                        break;
                    }
                } else ans[i] ++;
            }
        }
        if(!f) cout << endl;
        else f = false;
        for (int i = 0; i <= n; i++) {
            cout << i << ": " << ans[i] << endl;
        }
    }
    return 0;
}