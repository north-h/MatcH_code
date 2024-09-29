#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9;

int n, m, q, sz, blk[100010], mm, s[410][100010];
int a[100010], b[100010], t[400010], l[100010], r[100010];
vector <int> v[100010];

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) 
        cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    m = unique(b + 1, b + n + 1) - b - 1;
    sz = (int)sqrt(m);
    for(int i = 1; i <= n; i++){
        a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
        blk[i] = (i - 1) / sz + 1;
        v[a[i]].push_back(i);
    }
    mm = blk[n];
    for(int i = 1; i <= n; i++)
        s[blk[a[i]]][i]++;
    for(int i = 1; i <= mm; i++)
        for(int j = 1; j <= n; j++)
            s[i][j] += s[i][j - 1];    
    for(int i = 1, now, L, R; i <= n; i++){
        cin >> l[i] >> r[i], now = 0;
        for(int j = 1; j <= mm; j++){
            now += s[j][r[i]] - s[j][l[i] - 1];
            if(now > (r[i] - l[i] + 1) >> 1){
                L = (j - 1) * sz + 1;
                R = j * sz;
                break;
            }
        }
        if(now <= (r[i] - l[i] + 1) >> 1) continue;
        for(int j = R, p1, p2; j >= L; j--){
            p2 = upper_bound(v[j].begin(), v[j].end(), r[i]) - v[j].begin();
            p1 = lower_bound(v[j].begin(), v[j].end(), l[i]) - v[j].begin();
            now -= p2 - p1;
            if(now <= (r[i] - l[i] + 1) >> 1){
                printf("%d\n", b[j]);
                break;
            }
        }
    }
    return 0;
}