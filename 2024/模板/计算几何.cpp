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

Point operator * (Point a, double r) { return Point{a.x * r, a.x * r}; } //重载乘号

Point operator + (Point a, Point b) { return Point{a. x + b.x, a.y + b.y}; } //重载加号

double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; } //求叉积，判断点线位置关系

double area(Point a, Point b, Point c) { return cross(b - a, c - a); }

bool intersect(Point a, Point b, Point c, Point d) { //判断两直线知否相交
    if (area(a, b, c) * area(a, b, d) > 0) return false;
    if (area(c, d, a) * area(c, d, b) > 0) return false;
    return true;
}

Point getNode(Point a, Point u, Point b, Point v) {
    double t = cross(a - b, v) / cross(v, u);
    return a + u * t;
}

void solve() {}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}