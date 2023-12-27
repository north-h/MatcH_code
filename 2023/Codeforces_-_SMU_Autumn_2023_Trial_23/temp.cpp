#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n';
const int N = 2e5 + 10;
#define inf 0x3f3f3f3f
/*
int read(){
    int f=1,x=0;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x*f;
}
*/
ll a[N];
void solve() {
    memset(a, 0, sizeof(a));
    ll n, l, r;
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        ll x = a[i];
        ll left = i + 1, right = n, mid;
        ll idx_left = 0, idx_right = 0;
        while(left <= right) {
            mid = (left + right) / 2;
            if(x + a[mid] < l) {
                left = mid + 1;
            } else {
                idx_left = mid;
                right = mid - 1;
            }
        }
        left = idx_left;
        right = n;
        if(idx_left == 0)continue;
        while(left <= right) {
            mid = (left + right) / 2;
            if(a[mid] > r - x) {
                right = mid - 1;
            } else  {
                idx_right = mid;
                left = mid + 1;
            }
        }
        if(idx_left > idx_right || idx_right == 0)continue;
        //cout<<"idx_left="<<idx_left<<' '<<"idx_right="<<idx_right<<endl;
        ans += idx_right - idx_left + 1;
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

