#include<bits/stdc++.h>
#include<windows.h>

#define int long long

using namespace std;

void makedata() {
	ofstream fout("input.txt");
	srand(time(nullptr));
	int n, m, q; n = rand() % 10 + 1, m = rand() % 10 + 1, q = rand() % 10 + 1;
	fout << n << " " << m << " " << q << endl;
	set<int> s;
	for (int i = 1; i <= m; i++) {
		int x = rand() % n + 1;
		fout << x << " ";
		s.insert(x);
	}
	fout << endl;
	for (int i = 1; i <= q; i++) {
		while (true) {
			int t = rand() % n + 1;
			if (s.count(t)) continue;
			fout << t << endl;
			break;
		}
	}
	fout.close();
}

int32_t main() {
	int ans = 0;
	int n = 10000;
	for (int i = 1; i <= n; i++) {
		printf("Test#%lld\n", i);
		makedata();
		system("ZJ.exe < input.txt > ZJ_output.txt");
		system("BL.exe < input.txt > BL_output.txt");

		if (system("fc ZJ_output.txt BL_output.txt")) {
			cout << "Wrong Answer!" << endl << endl << endl;
			break;
		} else {
			cout << "Accepted!" << endl << endl << endl;
			ans ++;
		}
	}
	cout << "通过率：" << ans * 1.0 / n * 100 << "%" << endl;
	return 0;
}
