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

struct Point { int x, y; };

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; } //求点积，可以判断直线是否垂直

double len(Point a) { return sqrt(a.x * a.x + a.y * a.y); } //求向量的模长

double angle(Point a, Point b) { return acos(dot(a, b) / len(a) / len(b)); } //求两个向量的夹角

Point operator - (Point a, Point b) { return Point{a.x - b.x, a.y - b.y}; } //重载减号

double operator * (Point a,Point b) { return a.x * b.y - a.y * b.x; } //重载乘号

double cross(Point a, Point b, Point c) { return (b - a) * (c - a); } //求叉积，判断点线位置关系

double dis(Point a, Point b) { return sqrt((a.x - b.x ) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); } //求两点之间的距离

void solve() {}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    // int h_h = 1;
    // cin >> h_h;
    // while (h_h--)solve();
    while(true) {
        Point O;
        double r;
        cin >> O.x >> O.y >> r;
        if(r < 0) break;
        int  n;
        cin >> n;
        vector<Point> a;
        for (int i = 0; i < n; i++) {
            Point t;
            cin >> t.x >> t.y;
            if(dis(O, t) <= r){
                a.push_back(t);
            }
        }
        int ans = 0;
        for (int i = 0; i < a.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < a.size(); j++) {
                if(cross(O, a[i], a[j]) >= 0) cnt ++;
            }
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}