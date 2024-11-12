/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-11-12 19:37:12
 *
 * Problem: C. Grass
 * Contest: Codeforces - SMU Autumn 2024 Team Round 13
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/565855/problem/C
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

const double eps = 1e-8;    // 根据题目精度要求进行修改

int sgn(double x) { // 进行判断, 提高精度
    if (fabs(x) < eps) return 0;    // x == 0, 精度范围内的近似相等
    return x > 0 ? 1 : -1;          // 返回正负
}

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}  // 构造函数, 初始值为 0
    // 重载运算符
    // 点 - 点 = 向量(向量AB = B - A)
    Point operator- (const Point &B) const {
        return Point(x - B.x, y - B.y);
    }
    // 点 + 点 = 点, 点 + 向量 = 向量, 向量 + 向量 = 向量
    Point operator+ (const Point &B) const {
        return Point(x + B.x, y + B.y);
    }
    // 向量 × 向量 (叉积)
    int operator^ (const Point &B) const {
        return x * B.y - y * B.x;
    }
};

struct Line {
    Point s, e;
    Line() {}
    Line(Point x, Point y): s(x), e(y) {}
};

typedef Point Vector;

int operator^ (Vector &A, Vector &B) {
    return A.x * B.y - A.y * B.x;
}

int operator* (Vector &A, Vector &B) {
    return A.x * B.x + A.y * B.y;
}

bool OS(Point P, Point A, Point B) {
    Vector PA = A - P, PB = B - P;
    return sgn(PA ^ PB) == 0 && sgn(PA * PB) <= 0;  // <=, 包括端点; <, 不包括端点
}

bool check(Point a, Point b, Point c, Point d, Point e) {
    if (OS(c, a, b) || OS(d, a, b) || OS(e, a, b) || 
        OS(d, a, c) || OS(e, a, c) || OS(b, a, c) ||
        OS(c, a, d) || OS(e, a, d) || OS(b, a, d) ||
        OS(d, a, e) || OS(b, a, e) || OS(c, a, e)) 
        return false;
    return true;
}

void solve() {
    int n; cin >> n;
    vector<Point> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].x >> a[i].y;
    }
    if (n <= 4) {
        cout << "NO\n";
        return ;
    }
    Point A = a[1], B = a[2], C = a[3], D = a[4];
    for (int i = 5; i <= n; i ++) {
        if (check(a[i], A, C, D, B)) {
            cout << "YES\n";
            cout << a[i].x << ' ' << a[i].y << '\n';
            cout << A.x << ' ' << A.y << '\n';
            cout << B.x << ' ' << B.y << '\n';
            cout << C.x << ' ' << C.y << '\n';
            cout << D.x << ' ' << D.y << '\n';
            return ;
        }
        if (check(A, a[i], C, D, B)) {
            cout << "YES\n";
            cout << A.x << ' ' << A.y << '\n';
            cout << a[i].x << ' ' << a[i].y << '\n';
            cout << B.x << ' ' << B.y << '\n';
            cout << C.x << ' ' << C.y << '\n';
            cout << D.x << ' ' << D.y << '\n';
            return ;
        }
        if (check(C, a[i], A, D, B)) {
            cout << "YES\n";
            cout << C.x << ' ' << C.y << '\n';
            cout << a[i].x << ' ' << a[i].y << '\n';
            cout << A.x << ' ' << A.y << '\n';
            cout << B.x << ' ' << B.y << '\n';
            cout << D.x << ' ' << D.y << '\n';
            return ;
        }
        if (check(D, a[i], A, C, B)) {
            cout << "YES\n";
            cout << D.x << ' ' << D.y << '\n';
            cout << a[i].x << ' ' << a[i].y << '\n';
            cout << A.x << ' ' << A.y << '\n';
            cout << B.x << ' ' << B.y << '\n';
            cout << C.x << ' ' << C.y << '\n';
            return ;
        }
        if (check(B, a[i], A, C, D)) {
            cout << "YES\n";
            cout << B.x << ' ' << B.y << '\n';
            cout << a[i].x << ' ' << a[i].y << '\n';
            cout << A.x << ' ' << A.y << '\n';
            cout << C.x << ' ' << C.y << '\n';
            cout << D.x << ' ' << D.y << '\n';
            return ;
        }
    }
    cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}