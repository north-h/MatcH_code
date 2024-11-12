#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>
#include <random>
#include<numeric>
#include<string>
#include<string.h>
#include<iterator>
#include<fstream>
#include<map>
#include<unordered_map>
#include<stack>
#include<list>
#include<queue>
#include<iomanip>
#include<bitset>

#pragma GCC optimize(2)
#pragma GCC optimize(3)

#define endl '\n'
#define int ll
#define PI acos(-1)
#define INF 0x3f3f3f3f
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll>PII;
const int N = 2e6 + 50, MOD = 1e9 + 7;

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

bool check(vector<PII>& ans)
{
    for (int i = 0; i < 5; i++)
    {
        //记录下每个斜率的点
        unordered_map<double, vector<PII>>res;
        bool flag = true;
        for (int j = 0; j < 5; j++)
        {
            if (i == j)continue;
            //计算斜率：（y2-y1）/（x2-x1）
            double b = (ans[j].second - ans[i].second), a = (ans[j].first - ans[i].first);
            double c = b / a;
            //如果已经有两个点与A共线，那这第三个点显然不对
            if (res[c].size() >= 2)
            {
                flag = false;
                break;
            }
            //如果已经有一个点与A共线，那看A在不在这两个点之间
            else if (res[c].size() == 1)
            {
                int x = abs(ans[i].first - res[c][0].first) + abs(ans[i].second - res[c][0].second);
                int y = abs(ans[i].first - ans[j].first) + abs(ans[i].second - ans[j].second);
                int z = abs(ans[j].first - res[c][0].first) + abs(ans[j].second - res[c][0].second);
                if (x + y == z)
                {
                    res[c].push_back(ans[j]);
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else res[c].push_back(ans[j]);
        }
        if (flag)
        {
            cout << "YES" << endl;
            cout << ans[i].first << " " << ans[i].second << endl;
            for (int j = 0; j < 5; j++)
            {
                if (i == j)continue;
                cout << ans[j].first << " " << ans[j].second << endl;
            }
            return true;
        }
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    unordered_map<double, int>mymap;
    vector<PII>v(n + 1), ans;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
        if (ans.size() < 4)
        {
            //固定前四个点
            ans.push_back(v[i]);
        }
    }
    if (n < 5)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 5; i <= n; i++)
    {
        //找第五个点
        ans.push_back(v[i]);
        if (check( ans ))
        {
            return;
        }
        ans.pop_back();
    }
    cout << "NO" << endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}

