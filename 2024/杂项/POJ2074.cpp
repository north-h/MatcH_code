// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
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

struct Point { double x, y; };

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; } //求点积，可以判断直线是否垂直

double len(Point a) { return sqrt(dot(a, a)); } //求向量的模长

double angle(Point a, Point b) { return acos(dot(a, b) / len(a) / len(b)); } //求两个向量的夹角

Point operator - (Point a, Point b) { return Point{a.x - b.x, a.y - b.y}; } //重载减号

Point operator * (Point a, double r) { return Point{a.x * r, a.y * r}; } //重载乘号

Point operator + (Point a, Point b) { return Point{a. x + b.x, a.y + b.y}; } //重载加号

double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; } //求叉积，判断点线位置关系

double area(Point a, Point b, Point c) { return cross(b - a, c - a); }

bool intersect(Point a, Point b, Point c, Point d) { //判断两直线知否相交
    if (area(a, b, c) * area(a, b, d) > 0) return false;
    if (area(c, d, a) * area(c, d, b) > 0) return false;
    return true;
}

// double getNode(Point a, Point u, Point b, Point v) {
//     double t = cross(a - b, v) / cross(v, u);
//     Point P = a + u * t;
//     if (P.x <= )
//     return P.x;
// }

void solve() {}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    // int h_h = 1;
    // cin >> h_h;
    // while (h_h--)solve();
    while (true) {
        pair<Point,Point> H, P;
        cin >> H.fi.x >> H.se.x >> H.fi.y, H.se.y = H.fi.y;
        if (H.fi.x == 0 && H.se.x == 0 && H.fi.y == 0) break;
        cin >> P.fi.x >> P.se.x >> P.fi.y, P.se.y = P.fi.y;
        int n;
        cin >> n;
        auto getNode = [&](Point a, Point u, Point b, Point v) {
            double t = cross(a - b, v) / cross(v, u);
            Point T = a + u * t;
            if (T.x < P.fi.x) T.x = P.fi.x;
            if (T.x > P.se.x) T.x = P.se.x;
            return T.x;
        };
        pair<Point, Point> sg;
        vector<pair<double, double>> ans;
        for (int i = 1; i <= n; i++) {
            cin >> sg.fi.x >> sg.se.x >> sg.fi.y;
            sg.se.y = sg.fi.y;
            if (sg.fi.y > H.fi.y || sg.fi.y < P.fi.y) continue;
            double x =  getNode(H.se, sg.fi - H.se, P.fi, P.se - P.fi);
            double y =  getNode(H.fi, sg.se - H.fi, P.fi, P.se - P.fi);
            ans.push_back({x, y});
        }
        if (ans.size() == 0) {
            cout << lf(2) << P.se.x - P.fi.x << endl;
            continue;
        }
        sort(ans.begin(), ans.end());
        double res = max(ans.front().fi - P.fi.x, P.se.x - ans.back().se);
        double r = ans[0].se;
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i].fi > r) res = max(res, ans[i].fi - r);
            r = max(ans[i].se, r);
        }
        if (res == 0) cout << "No View" << endl;
        else cout << lf(2) << res << endl;
    }
    return 0;
}