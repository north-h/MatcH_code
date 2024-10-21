// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;
const double eps = 1e-8;    // 根据题目精度要求进行修改
const double PI = acos(-1.0);   // pai, 3.1415916....

using namespace std;


int sgn(double x) { // 进行判断, 提高精度
    if (fabs(x) < eps) return 0;    // x == 0, 精度范围内的近似相等
    return x > 0 ? 1 : -1;          // 返回正负
}

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}  // 构造函数, 初始值为 0
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
    double operator^ (const Point &B) const {
        return x * B.y - y * B.x;
    }
    // 向量 · 向量 (点积)
    double operator* (const Point &B) const {
        return x * B.x + y * B.y;
    }
    // 点 * 数 = 点, 向量 * 数 = 向量
    Point operator* (const double &B) const {
        return Point(x * B, y * B);
    }
    // 点 / 数 = 点, 向量 / 数 = 向量
    Point operator/ (const double &B) const {
        return Point(x / B, y / B);
    }
    // 判断大小, 一般用于排序
    bool operator< (const Point &B) const {
        return x < B.x || (x == B.x && y < B.y);
    }
    // 判断相等, 点 == 点, 向量 == 向量, 一般用于判断和去重
    bool operator== (const Point &B) const {
        return sgn(x - B.x) == 0 && sgn(y - B.y) == 0;
    }
    // 判断不相等, 点 != 点, 向量 != 向量
    bool operator!= (const Point &B) const {
        return sgn(x - B.x) || sgn(y - B.y);
    }
};

// Need: sgn()

typedef Point Vector;

// 向量 · 向量 (点积)
double operator* (Vector &A, Vector &B) {
    return A.x * B.x + A.y * B.y;
}

// 向量 × 向量 (叉积)
double operator^ (Vector &A, Vector &B) {
    return A.x * B.y - A.y * B.x;
}

// Need: (-, *)

double dist(Point a, Point b) { 
    return sqrt((a - b) * (a - b)); 
}

// Need: (*)

double len(Vector A) { 
    return sqrt(A * A); 
}

// Need: (/), len()

Vector norm(Vector A) { 
    return A / len(A); 
}

// Need: (*), len(), PI

double Angle(Vector A, Vector B) {
    double t = acos((A * B) / len(A) / len(B));
    return t;               // 返回 [0, π]
    // return t * (180 / PI);  // 返回 [0, 180] (角度)
}

// Need: (-, ^), sgn()

// 点在直线上, 返回 0 (三点共线)
// 点在直线的逆时针方向, 返回 1
// 点在直线的顺时针方向, 返回 -1

// 点 a, b (向量ab) 所在的直线和点 c
// 使用的时候要注意 a 和 b 的顺序, 有时顺序不同, 结果不同
int Cross(Point a, Point b, Point c) { 
    return sgn((b - a) ^ (c - a)); 
}

// 两种分情况使用
// double Cross(Point a, Point b, Point c) { 
//     return (b - a) ^ (c - a); 
// }

// Need: (*, ^)

// 向量 A 和要逆时针转的角度 [0, PI]
// PI / 2, 90度
Vector Rotate(Vector A, double b) {
    Vector B(sin(b), cos(b));
    return Vector(A ^ B, A * B);
}

struct Line {
    Point s, e;
    Line() {}
    Line(Point x, Point y): s(x), e(y) {}
};

// Need: sgn(), 操作符重载(-, ^)

bool In_one_line(Point A, Point B, Point C) { 
    return !sgn((B - A) ^ (C - B)); 
}

// Need: (-, ^), len()

// 点 P 到直线 AB 的距离
double Dist_point_to_line(Point P, Point A, Point B) {
    Vector v1 = B - A, v2 = P - A;
    return fabs((v1 ^ v2) / len(v1));
}

// Need: 操作符重载(==, -, *, ^), len(), sgn()

double Dist_point_to_seg(Point P, Point A, Point B) {
    if (A == B) return len(P - A);      // 如果重合, 那么就是两点的距离
    Vector v1 = B - A, v2 = P - A, v3 = P - B;
    if (sgn(v1 * v2) < 0) return len(v2);   // AP 最短
    if (sgn(v1 * v3) > 0) return len(v3);   // BP 最短
    return fabs((v1 ^ v2) / len(v1));       // 垂线
}

// Need: (-, *, ^), sgn()

bool OnSegment(Point P, Point A, Point B) {
    Vector PA = A - P, PB = B - P;
    return sgn(PA ^ PB) == 0 && sgn(PA * PB) <= 0;  // <=, 包括端点; <, 不包括端点
}

// Need: Cross()

// 相交, 返回 true
// 不相交, 返回 false

// 直线 ab 与线段 cd
bool Intersect_line_seg(Point a, Point b, Point c, Point d) {
    return Cross(a, b, c) * Cross(a, b, d) <= 0;
}

// Need: Cross(), OnSegment()

// 相交, 返回 true (包括端点相交)
// 不相交, 返回 false

// 线段 ab 与线段 cd
bool Intersect_seg(Point a, Point b, Point c, Point d) {
    if (OnSegment(a, c, d) || OnSegment(b, c, d) 
        || OnSegment(c, a, b) || OnSegment(d, a, b)) return 1;
    if (Cross(a, b, c) * Cross(a, b, d) >= 0) return 0;
    if (Cross(c, d, a) * Cross(c, d, b) >= 0) return 0;
    return 1;
}

// Need: (-, ^), sgn()

// 返回true: 平行/重合, false: 相交
bool Line_parallel(Line A, Line B) { 
    return sgn((A.s - A.e) ^ (B.s - B.e)) == 0; 
}

// Need: (-, *D, ^)

// 首先要判断两直线是否相交, 即不平行(不重合)
// a, b 所在直线与 c, d 所在直线的交点
Point Intersection_line(Point a, Point b, Point c, Point d) {
    Vector u = b - a, v = d - c;
    double t = ((a - c) ^ v) / (v ^ u);
    return a + u * t;
}

// Need: (-, *D, ^)

// Point Intersection_line(Point a, Vector u, Point b, Vector v) {
//     double t = ((a - b) ^ v) / (v ^ u);
//     return a + u * t;
// }

// Need: 操作符重载(-), len()

double Triangle_area(Point A, Point B, Point C) {
    double a = len(A - B), b = len(A - C), c = len(B - C);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Need: (-, ^)

double Triangle_area2(Point A, Point B, Point C) {
    return fabs((B - A) ^ (C - A)) / 2;
}

// Need: (-, ^)

// 因为叉积求得的三角形面积是有向的, 在外面的面积可以正负抵消掉
// 所以能够求任意多边形面积(凸, !凸)

// p[]下标从 0 开始, 长度为 n
double Polygon_area(Point *p, int n) {
    double area = 0;
    for (int i = 1; i <= n - 2; i++)
        area += (p[i] - p[0]) ^ (p[i + 1] - p[0]);
    return fabs(area / 2);  // 无向面积
    return area / 2;        // 有向面积
}

// Need: (^)

// 原理和上面相同, 不过是把原点(0, 0) 作为被指向点

// p[] 下标从 0 开始, 长度为 n
// double Polygon_area(Point *p, int n) {
//     double area = 0;
//     for (int i = 0, j = n - 1; i < n; j = i++)
//         area += (p[j] ^ p[i]);
//     return fabs(area / 2);  // 无向面积
//     return area / 2;        // 有向面积
// }

// Need: sgn(), OnSegment()

// 适用于任意多边形, 不用考虑精度误差和多边形的给出顺序
// 点在多边形边上, 返回 -1
// 点在多边形内, 返回 1
// 点在多边形外, 返回 0

// p[] 的下标从 0 开始, 长度为 n
int InPolygon(Point P, Point *p, int n) {
    bool flag = false;      // 相当于计数
    for (int i = 0, j = n - 1; i < n; j = i++) {
        Point p1 = p[i], p2 = p[j];
        if (OnSegment(P, p1, p2)) return -1;
        if (sgn(P.y - p1.y) > 0 == sgn(P.y - p2.y) > 0) continue;
        if (sgn((P.y - p1.y) * (p1.x - p2.x) / (p1.y - p2.y) + p1.x - P.x) > 0)
            flag = !flag;
    }
    return flag;
}

// Need: Cross()

// 点在多边形边上, 返回 -1
// 点在多边形内, 返回 1
// 点在多边形外, 返回 0

// p[] 的下标从 0 开始, 长度为 n
// int InPolygon(Point P, Point *p, int n) {
//     int st[3] = {0, 0, 0};
//     for (int i = 0, j = n - 1; i < n; j = i++) {
//         st[Cross(p[j], p[i], P) + 1]++;
//         if (st[0] && st[2]) return 0;
//     }
//     if (st[1]) return -1;
//     return 1;
// }

// Need: (-, ^), sgn()

// 顶点必须按顺时针(或逆时针)给出, 允许共线边
// p[] 下标从 0 开始, 长度为 n
bool Is_contex(Point *p, int n) {
    bool s[3] = {0, 0, 0};
    for (int i = 0, j = n - 1, k = n - 2; i < n; k = j, j = i++) {
        int cnt = sgn((p[i] - p[j]) ^ (p[k] - p[j])) + 1;
        s[cnt] = true;
        if (s[0] && s[2]) return false;
    }
    return true;
}

// Need: Point()

struct Circle {
    Point o;
    double r;
    Circle(Point _o = Point(), double _r = 0) : o(_o), r(_r) {}

    // 圆的面积
    double Circle_S() { return PI * r * r; }
    // 圆的周长
    double circle_C() { return 2 * PI * r; }
};

// Need: (^), Angle(), sgn()

// 扇形的两交点A, B 和圆的半径 R
double SectorArea(Point A, Point B, double R) {
    double angle = Angle(A, B);
    if (sgn(A ^ B) < 0) angle = -angle;
    return R * R * angle / 2;
}

// Need: sgn(), dist()

// 点在圆上, 返回 0
// 点在圆外, 返回 -1
// 点在圆内, 返回 1

int Point_with_circle(Point p, Circle c) {
    double d = dist(p, c.o);
    if (sgn(d - c.r) == 0) return 0;
    if (sgn(d - c.r) > 0) return -1;
    return 1;
}

// Need: sgn(), Dist_point_to_line()

// 相切, 返回 0
// 相交, 返回 1
// 相离, 返回 -1

int Line_with_circle(Point A, Point B, Circle c) {
    double d = Dist_point_to_line(c.o, A, B);
    if (sgn(d - c.r) == 0) return 0;
    if (sgn(d - c.r) > 0) return -1;
    return 1;
}

// Need: (-, +, *P, *D, /), sgn()

// 直线与圆相交, 返回两点
// 直线与圆相切, 返回两个一样的相切点

pair<Point, Point> Intersection_line_circle(Point A, Point B, Circle c) {
    Vector AB = B - A;
    Vector pr = A + AB * ((c.o - A) * AB / (AB * AB));
    double base = sqrt(c.r * c.r - ((pr - c.o) * (pr - c.o)));

    if (sgn(base) == 0) return make_pair(pr, pr);

    Vector e = AB / sqrt(AB * AB);
    return make_pair(pr + e * base, pr - e * base);
}

// Need: dist()

// 相离, 返回 -1
// 外切, 返回 0
// 内切(A 包含 B), 返回 1
// 内切(B 包含 A), 返回 2
// 内含(A 包含 B), 返回 3
// 内含(B 包含 A), 返回 4
// 相交, 返回 5

int Circle_with_circle(Circle A, Circle B) {
    double len1 = dist(A.o, B.o);
    double len2 = A.r + B.r;
    if (sgn(len1 - len2) > 0) return -1;
    if (sgn(len1 - len2) == 0) return 0;
    if (sgn(len1 + len2 - 2 * A.r) == 0) return 1;
    if (sgn(len1 + len2 - 2 * B.r) == 0) return 2;
    if (sgn(len1 + len2 - 2 * A.r) < 0) return 3;
    if (sgn(len1 + len2 - 2 * B.r) < 0) return 4;
    return 5;
}

// Need: (-, +), len()

// 相交, 返回两点坐标
// 相切, 返回两个一样的相切点

// 要先判断是否相交或相切再调用
pair<Point, Point> Intersection_circle_circle(Circle A, Circle B) {
    Vector AB = B.o - A.o;
    double d = len(AB);
    double a = acos((A.r * A.r + d * d - B.r * B.r) / (2.0 * A.r * d));
    double t = atan2(AB.y, AB.x);
    Vector x(A.r * cos(t + a), A.r * sin(t + a));
    Vector y(A.r * cos(t - a), A.r * sin(t - a));
    return make_pair(A.o + x, A.o + y);
}

// Need: (-, *, ^, +), dist()

// 返回两个切点坐标

// 一定要先判断点在圆外, 然后再调用
pair<Point, Point> TangentPoint_point_circle(Point p, Circle c) {
    double d = dist(p, c.o);
    double l = sqrt(d * d - c.r * c.r);
    Vector e = (c.o - p) / d;
    double angle = asin(c.r / d);

    Vector t1(sin(angle), cos(angle));
    Vector t2(sin(-angle), cos(-angle));
    Vector e1(e ^ t1, e * t1);
    Vector e2(e ^ t2, e * t2);
    e1 = e1 * l + p;
    e2 = e2 * l + p;
    return make_pair(e1, e2);
}

// Need: dist()

Circle get_circumcircle(Point A, Point B, Point C) {
    double Bx = B.x - A.x, By = B.y - A.y;
    double Cx = C.x - A.x, Cy = C.y - A.y;
    double D = 2 * (Bx * Cy - By * Cx);

    double x = (Cy * (Bx * Bx + By * By) - By * (Cx * Cx + Cy * Cy)) / D + A.x;
    double y = (Bx * (Cx * Cx + Cy * Cy) - Cx * (Bx * Bx + By * By)) / D + A.y;
    Point P(x, y);
    return Circle(P, dist(A, P));
}

// Need: (*D, /), dist(), Dist_point_to_line()

Circle get_incircle(Point A, Point B, Point C) {
    double a = dist(B, C);
    double b = dist(A, C);
    double c = dist(A, B);
    Point p = (A * a + B * b + C * c) / (a + b + c);
    return Circle(p, Dist_point_to_line(p, A, B));
}

// 要保证传入的点是整点
int IntegerPoint_on_seg(Point A, Point B) {
    int x = abs(A.x - B.x);
    int y = abs(A.y - B.y);
    if (x == 0 || y == 0) return 1;
    return __gcd(x, y) + 1; // 包含端点
    return __gcd(x, y) - 1; // 不包含端点
}

// 返回多边形边上整点的个数
// 点需要是顺时针(逆时针)给出

// p[] 下标从 0 开始, 长度为 n
int IntegerPoint_on_polygon(Point *p, int n) {
    int res = 0;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        int x = abs(p[i].x - p[j].x);
        int y = abs(p[i].y - p[j].y);
        res += __gcd(x, y);
    }
    return res;
}

// Need: Polygon_area(), IntegerPoint_on_polygon()

// 返回不包括边界的, 多边形内整点个数
int IntegerPoint_in_polygon(Point *p, int n) {
    double A = Polygon_area(p, n);
    double B = IntegerPoint_on_polygon(p, n);
    return A - B / 2 + 1;
}

// Need: (-, ^), len(), sgn()

// 排序常数大, 但精度高

Point p[N]; // 要排序的点
Point o(0, 0);  // 极点自定义

// 获取象限 (0, 1, 2, 3)
int Quadrant(Vector p) { 
    return sgn(p.y < 0) << 1 | sgn(p.x < 0) ^ sgn(p.y < 0); 
}

// 比较函数
bool cmp(Point a, Point b) {
    Vector p = a - o, q = b - o;
    int x = Quadrant(p), y = Quadrant(q);
    if (x == y) {
        if (sgn(p ^ q) == 0) return len(p) < len(q);
        return sgn(p ^ q) > 0;
    }
    return x < y;
}

// Need: (<), Cross()

Point s[N]; // 用来存凸包多边形的顶点
int top = 0;

// 点集 p[] 的下标从 1 开始, 长度为 n
void Andrew(Point *p, int n) {
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) {  // 下凸包
        while (top > 1 && Cross(s[top - 1], s[top], p[i]) <= 0) top--;
        s[++top] = p[i];
    }
    int t = top;
    for (int i = n - 1; i >= 1; i--) {  // 上凸包
        while (top > t && Cross(s[top - 1], s[top], p[i]) <= 0) top--;
        s[++top] = p[i];
    }

    top--;  // 因为首尾都会加一次第一个点, 所以去掉最后一个
}

// Need: (+, /), sgn(), dist(), get_circumcircle()

// p[] 下标从 0 开始, 长度为 n
Circle get_min_circle(Point *p, int n) {
    // 随机化, 防止被卡
    for (int i = 0; i < n; i++) swap(p[rand() % n], p[rand() % n]);

    Point o = p[0];
    double r = 0;

    for (int i = 0; i < n; i++) {
        if (sgn(dist(o, p[i]) - r) <= 0) continue;
        o = (p[i] + p[0]) / 2;
        r = dist(p[i], p[0]) / 2;
        for (int j = 1; j < i; j++) {
            if (sgn(dist(o, p[j]) - r) <= 0) continue;
            o = (p[i] + p[j]) / 2;
            r = dist(p[i], p[j]) / 2;
            for (int k = 0; k < j; k++) {
                if (sgn(dist(o, p[k]) - r) <= 0) continue;
                o = get_circumcircle(p[i], p[j], p[k]).o;
                r = dist(o, p[i]);
            }
        }
    }
    return Circle(o, r);
}

Circle c[N];
pair<double, int> st[N << 1];
int n;

double cal(int x) {
    int top = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        double dis = dist(c[i].o, c[x].o);
        double r1 = c[x].r, r2 = c[i].r;
        if (sgn(r1 + dis - r2) <= 0) return 0.0;
        if (sgn(r2 + dis - r1) <= 0 || sgn(r2 + r1 - dis) <= 0) continue;
        double del = acos((r1 * r1 + dis * dis - r2 * r2) / (2 * r1 * dis));
        double angle = atan2(c[i].o.y - c[x].o.y, c[i].o.x - c[x].o.x);
        double l = angle - del, r = angle + del;
        if (sgn(l + PI) < 0) l += 2 * PI;
        if (sgn(r - PI) >= 0) r -= 2 * PI;
        if (sgn(l - r) > 0) cnt++;
        st[++top] = {l, 1}, st[++top] = {r, -1};
    }

    st[0] = { -PI, 0}, st[++top] = {PI, 0};
    sort(st + 1, st + top + 1);
    double res = 0;
    for (int i = 1; i <= top; cnt += st[i++].second) {
        if (cnt) continue;
        Point o = c[x].o;
        double r = c[x].r, t1 = st[i - 1].first, t2 = st[i].first;
        res += r * (r * (t2 - t1) + o.x * (sin(t2) - sin(t1)) - o.y * (cos(t2) - cos(t1)));
    }
    return res;
}

double get_area() {
    sort(c + 1, c + n + 1);
    n = unique(c + 1, c + n + 1) - c - 1;
    double ans = 0;
    for (int i = 1; i <= n; i++) ans += cal(i);
    return ans / 2;
}

// Need: (-, +, *D, *, ^, /), sgn(), Intersection_line(点向量版), OnSegment(), Rotate()
// SectorArea(), Angle(), norm(), len(), dist(),

// 返回圆点到 ab 线段的距离, 并带回圆与线段的交点 pa, pb
double getDP2(Point a, Point b, Circle c, Point &pa, Point &pb) {
    Point o = c.o;
    double R = c.r;
    Point e = Intersection_line(a, b - a, o, Rotate(b - a, PI / 2));    // 垂足点
    double d = dist(o, e);
    if (!OnSegment(e, a, b)) d = min(dist(o, a), dist(o, b));
    if (R <= d) return d;
    double Len = sqrt(R * R - dist(o, e) * dist(o, e));
    pa = e + norm(a - b) * Len;
    pb = e + norm(b - a) * Len;
    return d;
}

double getArea(Point a, Point b, Circle C) {    // 面积的交
    Point o = C.o;
    double R = C.r;
    if (sgn(a ^ b) == 0) return 0;  // 共线
    double da = dist(o, a), db = dist(o, b);
    if (sgn(R - da) >= 0 && sgn(R - db) >= 0) return (a ^ b) / 2;   // ab 在圆内
    Point pa, pb;
    double d = getDP2(a, b, C, pa, pb);
    if (sgn(R - d) <= 0) return SectorArea(a, b, R);    // ab 在圆外
    if (sgn(R - da) >= 0) return (a ^ pb) / 2 + SectorArea(pb, b, R);   // a 在圆内
    if (sgn(R - db) >= 0) return SectorArea(a, pa, R) + (pa ^ b) / 2;   // b 在圆内
    return SectorArea(a, pa, R) + (pa ^ pb) / 2 + SectorArea(pb, b, R); // ab 是割线
}

// 返回所求的面积交
double Intersection_Area(Point *p, int n, Circle C) {
    // 平移
    for (int i = 0; i < n; i++) p[i] = p[i] - C.o;
    C.o = Point(0.0, 0.0);

    double area = 0;
    for (int i = 0, j = n - 1; i < n; j = i++) area += getArea(p[j], p[i], C);
    return fabs(area);
}

// 调用
Point p[N];
int n;
Circle C;

double area = Intersection_Area(p, n, C);

// Need: dist()

Point p[N], t[N];   // p[] 存点, t[] 是辅助数组

double divide(int l, int r) {
    double d = 2e9;
    if (l == r) return d;
    int mid = l + r >> 1;
    Point tmp = p[mid];
    d = min(divide(l, mid), divide(mid + 1, r));    // 分治

    // 归并排序部分
    int k = 0, i = l, j = mid + 1, tt = 0;
    while (i <= mid && j <= r)
        if (p[i].y < p[j].y) t[k++] = p[i++];
        else t[k++] = p[j++];
    while (i <= mid) t[k++] = p[i++];
    while (j <= r) t[k++] = p[j++];
    for (i = l, j = 0; i <= r; i++, j++) p[i] = t[j];

    for (int i = 0; i < k; i++)
        if (fabs(tmp.x - t[i].x) < d) t[tt++] = t[i];

    for (int i = 0; i < tt; i++)
        for (int j = i + 1; j < tt && t[j].y - t[i].y < d; j++)
            d = min(d, dist(t[i], t[j]));
    return d;
}

// 调用
int n;  // 点的个数
double dis = divide(1, n);


void solve() {}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h --) solve();
    return 0;
}