#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int vis[N];
vector<int> prime;

void euler(int n) {
	vis[1] = 1;
	for (int i = 2; i < n; i ++) {
		if (!vis[i]) prime.push_back(i);
		for (auto j : prime) {
			if (j * i >= n) break;
			vis[i * j] = 1;
			if (i % j == 0) break;
		}
	}
}