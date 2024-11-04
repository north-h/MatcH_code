#include <bits/stdc++.h>

using namespace std;

using i128 = __int128;

ostream &operator<<(ostream &os, i128 n) {
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    reverse(s.begin(), s.end());
    if (!s.size()) s += '0';
    return os << s;
}
