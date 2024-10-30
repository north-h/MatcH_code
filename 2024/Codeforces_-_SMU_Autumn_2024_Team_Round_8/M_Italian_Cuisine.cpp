/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-22 21:15:29
 *
 * Problem: M. Italian Cuisine
 * Contest: Codeforces - SMU Autumn 2024 Team Round 8
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/559336/problem/M
 * MemoryL: 1024 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;
using i128 = __int128;

ostream &operator<<(ostream &os, i128 n) {
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    reverse(s.begin(), s.end());
    if (s.size() == 0) s += '0';
    return os << s;
}

const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x) {
    if (fabs(x) < eps) return 0;
    return x > 0 ? 1 : -1;
}

struct Point {
    int x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator- (const Point &B) const {
        return Point(x - B.x, y - B.y);
    }
    Point operator+ (const Point &B) const {
        return Point(x + B.x, y + B.y);
    }
};

typedef Point Vector;

struct Circle {
    Point o;
    int r;
    Circle(Point _o = Point(), int _r = 0) : o(_o), r(_r) {}

    // 圆的面积
    double Circle_S() { return PI * r * r; }
    // 圆的周长
    double circle_C() { return 2 * PI * r; }
};

i128 operator^ (Vector &A, Vector &B) {
    return A.x * B.y - A.y * B.x;
}

double operator* (Vector &A, Vector &B) {
    return A.x * B.x + A.y * B.y;
}

double len(Vector A) {
    return sqrt(A * A);
}

double Dist_point_to_line(Point P, Point A, Point B) {
    Vector v1 = B - A, v2 = P - A;
    return fabs((v1 ^ v2) * 1.0 / len(v1));
}


i128 aabs(i128 x) {
    if (x < 0) x = -x;
    return x;
}

i128 getArea(Point a, Point b, Point c) {
    Vector ba = b - a, ca = c - a;
    return aabs((ba ^ ca));
}

bool check(Point a, Point b, Point c, Point d) {
    Vector da = d - a, ba = b - a, ca = c - a;
    if (ba.x == 0 && ba.y == 0) return true;
    if (sgn(da ^ ba) == -1 && sgn(da ^ ca) == -1) return true;
    return false;
}

void solve() {
    // Point a(0, 0), b(2, 1), c(1, 2);
    // Vector ba = b - a, ca = c - a;
    // cout << (ca ^ ba) << '\n';
    int n; cin >> n;
    Circle c; cin >> c.o.x >> c.o.y >> c.r;
    vector<Point> vv(n);
    for (int i = 0; i < n; i ++) {
        cin >> vv[i].x >> vv[i].y;
    }
    // cout << Dist_point_to_line(c.o, vv[0], vv[3]) << '\n';
    i128 ans = 0, area = 0;
    for (int i = 0, j = 1; i < n; i ++) {
        if (j <= i) j = i + 1;
        // debug2(i, j);
        while (sgn(Dist_point_to_line(c.o, vv[i], vv[j]) - c.r) == 1 &&
                check(vv[i], vv[(j - 1 + n) % n], vv[j], c.o)) {
            area += getArea(vv[i], vv[(j - 1 + n) % n], vv[j]);
            j = (j + 1) % n;
            // debug1(j);
        }
        j = (j - 1 + n) % n;
        // debug2(i, j);
        // debug2(ans, area);
        ans = max(ans, area);
        area -= getArea(vv[j], vv[i], vv[(i + 1) % n]);
        // cerr << "-------------\n";
    }
    cout << ans << '\n';
    // cerr << "-----------" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}