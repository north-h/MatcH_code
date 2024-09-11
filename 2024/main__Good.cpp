#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans;
string s;
int num = 0;
int h;
int n;
void dfs(int i, int ji, int ou, int f) {
    if (h)return;
    if (ji > (n + 2) / 2 || ou > ((n + 2) / 2) - 1) {
        return;
    }
    if (i == n) {
        cout << s << endl;
        num++;
        if (num == 100)h = 1;
        return;
    }
    s += "b";
    dfs(i + 1, ji + f, ou + !f, f);
    s.pop_back();
    s += "r";
    dfs(i + 1, ji + !f, ou + f, !f);
    s.pop_back();
}
signed main()
{
    cin >> n;
    int x =  (n + 1) / 2;
    if ( n % 2 == 0 )x++;
    ans = (n + n % 2) * x / 2;
    cout << ans << endl;
    dfs(0, 0, 0, 0);
    return 0;
}

