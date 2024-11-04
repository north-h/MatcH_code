// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f, eps = 1e-8;

using namespace std;

using i128 = __int128;

ostream &operator<<(ostream &os, i128 n) {
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    reverse(s.begin(), s.end());
    if (!s.size()) s += '0';
    return os << s;
}

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
    // 向量 · 向量 (点积)
    int operator* (const Point &B) const {
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
    // return s;
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

i128 Triangle_area2(Point A, Point B, Point C) {
    i128 res = (B - A) ^ (C - A);
    if (res < 0) res = -res;
    return res;
}

void solve() {
    int n; cin >> n;
    map<pair<int, int>, int> mp;
    vector<Point> p(n + 1), pp(1);
    for (int i = 1; i <= n; i ++) {
        cin >> p[i].x >> p[i].y;
        mp[ {p[i].x, p[i].y}] = 1;
    }
    auto tb1 = Andrew(p);
    if (tb1.size() == n) {
        cout << -1 << '\n';
        return ;
    }
    // debug1(tb1.size());
    // for (auto [x, y] : tb1) debug2(x, y);
    i128 sum = 0;
    for (int i = 2; i < tb1.size(); i ++) {
        sum += Triangle_area2(tb1[0], tb1[i - 1], tb1[i]);
        // debug1(sum);
    }
    // cout << "-----------" << '\n';
    // debug1(sum);
    for (auto [x, y] : tb1) mp[ {x, y}] = 0;
    for (int i = 1; i <= n; i ++) {
        if (mp[ {p[i].x, p[i].y}] == 0) continue;
        pp.push_back(p[i]);
    }
    auto tb2 = Andrew(pp);
    i128 ans = 0;
    // debug1(tb2.size());
    // for (auto [x, y] : tb2) debug2(x, y);
    int sz2 = tb2.size(), sz1 = tb1.size();
    if (tb2.size() <= 3) {
        for (auto k : tb2) {
            // cout << k.x << ' ' << k.y << '\n';
            for (int i = 0; i < tb1.size(); i ++) {
                ans = max(ans, sum - Triangle_area2(k, tb1[i], tb1[(i + 1) % sz1]));
                // debug1(ans);
            }
        }
    } else {
        for (int i = 0, k = 0; i < tb1.size(); i ++) {
            int j = (i + 1) % sz1;
            i128 tp = Triangle_area2(tb2[k], tb1[i], tb1[j]);
            ans = max(ans, sum - tp);
            while (Triangle_area2(tb2[(k + 1) % sz2], tb1[i], tb1[j]) < tp) {
                k = (k + 1) % sz2;
                tp = Triangle_area2(tb2[k], tb1[i], tb1[j]);
            }
            ans = max(ans, sum - tp);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}

// 2
// 6
// -2 0
// 1 -2
// 5 2
// 0 4
// 1 2
// 3 1
// 4
// 0 0
// 1 0
// 0 1
// 1 1