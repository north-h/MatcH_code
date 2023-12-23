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
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

struct point {
    int x, y;
};

double dis(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) * 1.0 + 1.0 * (a.y - b.y) * (a.y - b.y));
}

double cross(point a, point b, point c) {
    return (b.x - a.x) * (c.y - a.y) * 1.0 - 1.0 * (b.y - a.y) * (c.x - a.x);
}

void solve() {
    point O;
    double r;
    int n, ans = 0;
    // int x = 3;
    while(cin >> O.x >> O.y >> r, r >= 0) {
        cin >> n;
        vector<point> a;
        point b;
        for(int i = 0, x; i < n; i++) {
            cin >> b.x >> b.y;
            if(dis(O, b) <= r)a.push_back(b);
        }
        for(int i = 0; i < a.size(); i++) {
            int cnt = 0;
            for(int j = 0; j < a.size(); j++)if(cross(O, a[i], a[j]) >= 0)cnt++;
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }
}

int32_t main() {
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}
