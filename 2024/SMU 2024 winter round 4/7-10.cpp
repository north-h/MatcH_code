// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

struct edge{
    int xb;
    string fa;
};

void solve() {
    int n;
    cin >> n;
    map<string, edge> mp;
    for (int i = 1; i <= n; i ++) {
        string a, b;
        cin >> a >> b;
        if (b.back() == 'r') {
            mp[a] = {1, b.substr(0, b.size() - 7)};
        } else if (b.back() == 'n') {
            mp[a] = {0, b.substr(0, b.size() - 4)};
        } else {
            // if (b.back() == 'f') mp[a] = {"f", b.substr(0, b.size() - 1)};
            // else mp[a] = {"m", b.substr(0, b.size() - 1)};
            // mp[a].xb = b.back();
            if (b.back() == 'f') mp[a].xb = 1;
            else mp[a].xb = 0;
        }
    }
    // for (auto [x, y] : mp) cout <<x << '|' << y.fa << ' ' << y.xb << endl; 
    auto judge = [&] (string a, string b) -> bool {
        int si = 0;
        for(auto i = a; !i.empty(); i = mp[i].fa, si++){
            int sj = 0;
            for(auto j= b; !j.empty(); j = mp[j].fa, sj++){
                if(si > 5 && sj > 5){//超时的点可能在这
                    return false;
                }
                if(i == j && (si <= 5 || sj <= 5)){
                    return true;
                }
            }
        }
	    return true;
    };
    int m;
    cin >> m;
    while (m --) {
        string a, a2, b, b2;
        cin >> a >> a2 >> b >> b2;
        if (!mp.count(a) || !mp.count(b)) cout << "NA" << endl;
        else if (mp[a].xb == mp[b].xb) cout << "whatever" << endl;
        else {
            if (judge(a, b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}