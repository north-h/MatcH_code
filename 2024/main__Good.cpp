#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef struct Point {
    int x, y;
} Point;
Point operator-(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }
__int128 operator^(Point a, Point b) { return a.x * b.y - a.y * b.x; }
__int128 cross(Point a, Point b, Point c) { return (b - a) ^ (c - a); }
Point point[100005];
Point pointTemp[100005];
int idx = 0;
bool cmp(Point a, Point b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
int n;
int stk1[100005];
int top1 = 0;
bool mark[100005];
void Andrew1() {
    sort(point + 1, point + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        while (top1 > 1 && cross(point[stk1[top1 - 1]], point[stk1[top1]], point[i]) <= 0) top1--;
        stk1[++top1] = i;
    }
    int tt = top1;
    for (int i = n - 1; i >= 1; i--) {
        while (top1 > tt && cross(point[stk1[top1 - 1]], point[stk1[top1]], point[i]) <= 0) top1--;
        stk1[++top1] = i;
    }
}
int stk2[100005];
int top2 = 0;
void Andrew2() {
    sort(pointTemp + 1, pointTemp + idx + 1, cmp);
    for (int i = 1; i <= idx; i++) {
        while (top2 > 1 && cross(pointTemp[stk2[top2 - 1]], pointTemp[stk2[top2]], pointTemp[i]) <= 0) top2--;
        stk2[++top2] = i;
    }
    int tt = top2;
    for (int i = idx - 1; i >= 1; i--) {
        while (top2 > tt && cross(pointTemp[stk2[top2 - 1]], pointTemp[stk2[top2]], pointTemp[i]) <= 0) top2--;
        stk2[++top2] = i;
    }
}
__int128 myabs(__int128 x) { return x < 0 ? -x : x; }
__int128 S = 0, ans = 0;
void magic() {
    int idx0 = 1;
    __int128 mi = 10;
    for (int i = 1; i <= 20; i++) mi *= 10;
    if (top2 == 1) {
        for (int i = 1; i < top1; i++) {
            __int128 res = myabs(cross(point[stk1[i]], point[stk1[i + 1]], pointTemp[1]));
            ans = max(ans, S - res);
        }
        return;
    }
    for (int j = 1; j < top2; j++) {
        __int128 res = myabs(cross(point[stk1[1]], point[stk1[2]], pointTemp[stk2[j]]));
        if (res < mi) mi = res, idx0 = j;
    }
    ans = max(ans, S - mi);
    for (int i = 1; i < top1; i++) {
        __int128 res = myabs(cross(point[stk1[i]], point[stk1[i + 1]], pointTemp[stk2[idx0]]));
        mi = res;
        while (myabs(cross(point[stk1[i]], point[stk1[i + 1]], pointTemp[stk2[(idx0 + 1 - 1) % (top2 - 1) + 1]])) < mi) {
            mi = myabs(cross(point[stk1[i]], point[stk1[i + 1]], pointTemp[stk2[(idx0 + 1 - 1) % (top2 - 1) + 1]]));
            idx0 = (idx0 + 1 - 1) % (top2 - 1) + 1;
        }
        ans = max(ans, S - mi);
    }
}
void write(__int128 x) {
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
//Concave Hull
//https://codeforces.com/gym/105459/problem/B
void solve() {
    cin >> n;
    top1 = 0, top2 = 0, S = 0, ans = 0, idx = 0;
    for (int i = 1; i <= n; i++) mark[i] = false;
    for (int i = 1; i <= n; i++) cin >> point[i].x >> point[i].y;
    Andrew1();
    if (top1 - 1 == n) { cout << "-1" << endl; return; }
    for (int i = 1; i <= top1; i++) mark[stk1[i]] = true;
    for (int i = 1; i <= n; i++) if (!mark[i]) pointTemp[++idx] = point[i];
    Andrew2();
    for (int i = 1; i < top1; i  ++) cout << point[stk1[i]].x << ' ' << point[stk1[i]].y << '\n';
    for (int j = 3; j < top1; j++) {
        S += cross(point[stk1[1]], point[stk1[j - 1]], point[stk1[j]]);
    }
    write(S);
    puts("");
    magic();
    if (ans == 0) { cout << "-1" << "\n"; return; }
    write(ans);
    puts("");
}

int32_t main() {
//  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
