#include <iostream>
using namespace std;
int n, k;

int query(int x) {
    int ret = 0;
    for (int i = 1, j = n ; i <= n; i++) {
        bool f = 0;
        j++;
        while (!f && j) {
            j--;
            if (!j)
                return ret;
            cout << "? " << i << " " << j << " " << x << endl;
            cout.flush();
            cin >> f;
        }
        ret += j;
    }
    return ret;
}

int main() {
    cin >> n >> k;
    int l = 1, r = n * n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (query(mid) <= n * n - k + 1) {
            l = mid + 1;
            ans = mid;
        }
        else {
            r = mid - 1 ;
        }
    }
    cout << "! " << l << endl;
    return 0;
}