#include<bits/stdc++.h>
#define int  long long
#define x first
#define y second
using namespace std;
inline void print(__int128 n) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    if (n > 9) print(n / 10);
    putchar(n % 10 + '0');
}
void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    __int128 l1 = 0 , r1 = 0, l2 = 0, r2 = 0 ;
    __int128 M = 0 ;
    for (int i = 0 ; i < n / 2; i ++)
    {
        M = M * 10 + 9 ;
        l1 = l1 * 10 + a[i] - '0' ;
        l2 = l2 * 10 + b[i] - '0' ;
    }
    for (int i = n / 2 ; i < n ; i ++)
    {
        r1 = r1 * 10 + a[i] - '0' ;
        r2 = r2 * 10 + b[i] - '0' ;
    }
    print(l1); cout << ' ';
    print(l2); cout << ' ';
    print(r1); cout << ' ';
    print(r2); cout << ' ';
    cout << '\n';
    auto get1 = [&](__int128 l , __int128 r , __int128 x)->__int128
    {
        while (l < r)
        {
            __int128 mid = l + r >> 1;
            if (mid * mid >= x) r = mid;
            else l = mid + 1;
        }
        return l  ;
    };
    auto get2 = [&](__int128 l , __int128 r , __int128 x)->__int128
    {
        while (l < r)
        {
            __int128 mid = l + r + 1 >> 1;
            if (mid * mid <= x) l = mid;
            else r = mid - 1;
        }
        return l  ;
    };
    __int128 ans = 0 , L = 0 , R = 1e16 ;

    if (l1 == l2)
    {
        __int128 k = get1(L, R, l1) ;
        if (k * k == l1)
        {
            __int128 l = get1(L, R, r1) , r = get2(L, R, r2) ;
            ans = (r - l + 1) ;
        }
        print(ans) ;
        return ;
    }
    __int128 n1 = get1(L, R, l1) , n2 = get2(L, R, l2) ;
    if (n1 * n1 == l1) n1 ++ ;
    if (n2 * n2 == l2) n2 -- ;
    if (n1 <= n2)
        ans += (n2 - n1 + 1) * (get2(L, R, M) + 1) ;
    if ((n1 - 1) * (n1 - 1) == l1)
    {
        int k = get2(L, R, M) - get1(L, R, r1) + 1;
        ans += k ;
    }
    if ((n2 + 1) * (n2 + 1) == l2)
    {
        int k = get2(L, R, r2) + 1;
        ans += k ;
    }
    print(ans) ;
}
signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    //cin>>T;

    while (T --)
    {
        solve();
    }
    return 0;
}
