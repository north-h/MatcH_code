#include <iostream>
#include <vector>
using namespace std;

int countValidRanges(int n, const vector<int>& mushrooms, int x) {
    vector<int> left(n + 1, n + 1);
    vector<int> right(n + 1, 0);
    int result = 0;

    // Calculate left[i] for each mushroom
    for (int i = 1; i <= n; ++i) {
        int currentG = 0;
        int l = i;
        while (l >= 1 && currentG <= x) {
            currentG += mushrooms[l - 1]; // mushrooms 是从 0 到 n-1 的索引
            if (currentG > x) break;
            --l;
        }
        left[i] = l + 1;
    }

    // Calculate right[i] for each mushroom
    for (int i = n; i >= 1; --i) {
        int currentG = 0;
        int r = i;
        while (r <= n && currentG <= x) {
            currentG += mushrooms[r - 1]; // mushrooms 是从 0 到 n-1 的索引
            if (currentG > x) break;
            ++r;
        }
        right[i] = r - 1;
    }

    // Calculate the total number of valid ranges
    for (int i = 1; i <= n; ++i) {
        if (left[i] <= i && i <= right[i]) {
            result += (i - left[i] + 1) * (right[i] - i + 1);
        }
    }

    return result;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> mushrooms(n);
    for (int i = 0; i < n; ++i) {
        cin >> mushrooms[i];
    }

    int result = countValidRanges(n, mushrooms, x);
    cout << result << endl;

    return 0;
}
