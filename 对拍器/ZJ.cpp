#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <iterator>

using namespace std;

int arr[200010];
long long sum[200010];

inline long long cal(long long a, long long b, long long c, long long d)
{
    return max({ a, b, c, d }) - min({ a, b, c, d });
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    for (i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + arr[i];

    int p, q;
    p = 1;
    q = 3;
    for (i = 3; i <= n - 1; i++)
        if (abs(sum[n] - sum[i] - (sum[i] - sum[2])) <= abs(sum[n] - sum[q] - (sum[q] - sum[2])))
            q = i;

    long long res = cal(arr[1], arr[2], sum[q] - sum[2], sum[n] - sum[q]);
    for (i = 3; i <= n - 2; i++)
    {
        while (p < i - 1)
        {
            if (abs(sum[i] - sum[p + 1] - (sum[p + 1] - sum[0])) <= abs(sum[i] - sum[p] - (sum[p] - sum[0])))
                p++;
            else
                break;
        }

        while (q < n - 1)
        {
            if (abs(sum[n] - sum[q + 1] - (sum[q + 1] - sum[i])) <= abs(sum[n] - sum[q] - (sum[q] - sum[i])))
                q++;
            else
                break;
        }

        res = min(cal(sum[p], sum[i] - sum[p], sum[q] - sum[i], sum[n] - sum[q]), res);
    }

    printf("%lld\n", res);
    return 0;
}