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
//  #define LOCAL
const int N = 1010;
const int INF = 0x3f3f3f3f;

using namespace std;

char a[N][N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			a[i][j] = '#';
		}
	}
    bool ok = false;
    if (n > m) swap(n, m), ok = true;
	char op = 'a';
    if (m == 3) {
        string s1 = "aabbcc", s2 = "bccaab";
        for (int i = 1; i <= n; i ++) {
            a[i][1] = s1[(i - 1) % 6];
        }
        for (int i = 1; i <= n; i ++) {
            a[i][2] = s2[(i - 1) % 6];
        }
        for (int i = 1; i <= n; i ++) {
            a[i][3] = 'd';
        }
        goto w;
    }
	int x;
	if (n & 1) x = n;
	else x = n - 1;
	for (int i = 2; i < m - 1; i ++) {
		a[1][i] = op ++;
		if (op > 'x') op = 'a';
	}
	a[1][1] = 'y';
	a[1][m - 1] = 'y';
	for (int i = 2; i <= x; i ++) {
		for (int j = 2; j < m - 1; j ++) {
			a[i][j] = a[i - 1][j];
		}
        if (i & 1) {
            a[i][1] ^= a[i - 1][1];
            a[i][m - 1] = a[i - 1][m -1];
        } else {
            a[i][m - 1] ^= a[i - 1][m - 1];
            a[i][1] = a[i - 1][1];
        }
	}
	if (n % 2 == 0) {
		a[n][m] = op ++;
	} else {
		a[n - 1][m] = op ++;
		if (op > 'x') op = 'a';
		a[n][m] = op ++;
	}
	for (int i = 1; i < n; i ++) {
		a[i][m] = a[i][m - 1];
	}
	if (n % 2 == 0) {
        for (int i = 1; i < m - 1; i ++) {
            a[n][i] = a[n - 1][i];
        }
        a[n][m - 1] ^= a[n - 1][m - 1];
    }
    w:
    for (int i =1 ; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << (char)tolower(a[i][j]); 
        }
        cout << endl;
    }
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}