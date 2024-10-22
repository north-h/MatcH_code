typedef __int128_t lll;
typedef pair<lll, lll> P;

#define x first
#define y second

// 叉乘
lll cross(P a, P b)
{
    return a.x * b.y - a.y * b.x;
}

// 点积
lll mul(P a, P b)
{
    return a.x * b.x + a.y * b.y;
}

// 点平方和
lll mul(P a)
{
    return a.x * a.x + a.y * a.y;
}

// 计算矢量
P del(P a, P b)
{
    return {a.x - b.x, a.y - b.y};
}

void solve()
{
    int n;
    read(n);

    P C;
    read(C.x);
    read(C.y);

    lll R;
    read(R);

    vector<P> a(n);
    for (int i = 0; i < n; i++)
    {
        read(a[i].x);
        read(a[i].y);
    }
    lll ans = 0;
    lll S = 0;
    for (int l = 0, r = l + 1; l < n; l++)
    {
        while (1)
        {
            // 处理首尾循环
            int rr = r % n + 1;
            // 计算新加点是否在左边界与圆心连线的另一侧
            lll s = cross(del(a[rr], a[l]), del(C, a[l]));
            // 如果在另一侧，说明新加边与圆相交或凸包包含了圆，移动l
            if (s <= 0)
                break;
            // s同时也是新加边与圆心构成的三角形的面积的两倍，利用s=len*d计算边与圆心的距离
            // 如果距离小于R，说明新加边与圆相交，移动l
            if (s * s < mul(del(a[rr], a[l])) * R * R)
                break;
            // 利用叉乘公式计算凸包新增加的三角形面积
            S += cross(del(a[r], a[l]), del(a[rr], a[l]));
            // 移动r
            r = rr;
        }
        ans = max(ans, S);
        // 处理首尾循环
        int ll = l % n + 1;
        // 减去左边界的三角形面积
        S -= cross(del(a[r], a[l]), del(a[r], a[ll]));
    }
    write(ans);
    putchar('\n');
}

int main()
{
    // ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    read(_);
    while (_--)
    {
        solve();
    }
    return 0;
}
