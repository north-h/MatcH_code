#include<bits/stdc++.h>
#include<windows.h>

#define int long long

using namespace std;

void makedata() {
	ofstream fout("input.txt");
	srand(time(nullptr));
	int n, m; n = rand() % 10 + 1, m = rand() % 10 + 1;
	fout << n << ' ' << m << endl;
	string a = "", b = "";
	for (int i = 1; i <= n; i ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				if (i == 1 && j == 1 || i == n && j == m) {
					fout << '.';
					continue;
				}
				int x = rand() % 2 + 1;
				if (x == 1) fout << '.';
				else fout << 'X';
			}
			fout << '\n';
		}
		fout.close();
	}
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
