/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-11-03 21:42:01
 *
 * Problem: P2742 [USACO5.1] 圈奶牛Fencing the Cows /【模板】二维凸包
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P2742
 * MemoryL: 128 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f, eps = 1e-8;

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

int Cross(Point a, Point b, Point c) {
    return sgn((b - a) ^ (c - a));
}

vector<Point> Andrew(vector<Point> p) {
    sort(p.begin() + 1, p.end());
    vector<Point> s;
    int sz, top;
    for (int i = 1; i < (int)p.size(); i++) {  // 下凸包
        sz = s.size();
        while (sz > 1 && Cross(s[sz - 2], s[sz - 1], p[i]) <= 0) {
            s.pop_back();
            sz = s.size();
        }
        s.push_back(p[i]);
    }
    top = s.size();
    for (int i = (int)p.size() - 1; i >= 1; i--) {  // 上凸包
        sz = s.size();
        while (sz > top && Cross(s[sz - 2], s[sz - 1], p[i]) <= 0) {
            s.pop_back();
            sz = s.size();
        }
        s.push_back(p[i]);
    }
    s.pop_back();
    return s;
}

void solve() {
    int n; cin >> n;
    vector<Point> p(n + 1);
    for (int i = 1; i <= n; i ++) cin >> p[i].x >> p[i].y;
    auto tb1 = Andrew(p);
    double ans = 0;
    // debug1(top);
    for (int i = 1; i < tb1.size(); i ++) {
        auto [x1, y1] = tb1[i - 1];
        auto [x2, y2] = tb1[i];
        ans += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        // debug1(ans);
    }
    ans += sqrt((tb1.front().x - tb1.back().x) * (tb1.front().x - tb1.back().x) +
                (tb1.front().y - tb1.back().y) * (tb1.front().y - tb1.back().y));
    cout << fixed << setprecision(2) << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}