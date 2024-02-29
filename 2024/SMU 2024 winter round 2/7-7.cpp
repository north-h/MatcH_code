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

int get(string s) {
    int res = 0;
    for (auto i : s) {
        res += (i - '0');
    }
    return res;
}

void solve() {
    int NA, NB;
    cin >> NA >> NB;
    int SA = get(to_string(NA));
    int SB = get(to_string(NB));
    if (NA % SB == 0 && NB % SA == 0) {
        if (NA > NB) cout << "A" << endl;
        else cout << "B" << endl;
    }
    else if (NA % SB == 0) cout << "A" << endl;
    else if (NB % SA == 0) cout << "B" << endl;
    else {
        if (NA > NB) cout << "A" << endl;
        else cout << "B" << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}