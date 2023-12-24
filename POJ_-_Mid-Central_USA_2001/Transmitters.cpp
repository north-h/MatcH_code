/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-22 17:46:00
 *
 * Problem: Transmitters
 * Contest: POJ - Mid-Central USA 2001
 * URL:     http://poj.org/problem?id=1106
 * MemoryL: 10 MB
 * TimeL:   1000 ms
 * ===========================================================================
 */
// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

double cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
double dis(Point a, Point b) {
    return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void solve() {
    Point o, a;
    int n, m, ans = 0;
    double r;
    vector<Point> p;
    while(scanf("%d%d%lf", &o.x, &o.y, &r), r >= 0) {
        n = ans = 0;
        scanf("%d", &m);
        while(m--) {
            scanf("%d%d", &a.x, &a.y);
            if(dis(a, o) <= r) p.push_back(a);
        }
        for(int i = 0; i < p.size(); i++) {
            int cnt = 0;
            for(int j = 0; j < p.size(); j++)
                if(cross(o, p[i], p[j]) >= 0) ++cnt;
            ans = max(ans, cnt);
        }
        printf("%d\n", ans);
    }
}

int main() {
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}
