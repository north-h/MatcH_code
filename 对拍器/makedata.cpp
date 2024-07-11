#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

vector<int> p;

void makedata()
{
	ofstream fout("input.txt");
	srand((unsigned int)time(0));
	int n = rand() % 5 + 4;
	// int m = rand() % 4 + 1;
	// int k = 2;
	fout << n << '\n';
	for (int i = 1; i <= n; i ++) {
		int x = rand() % 1000000000 + 1;
		fout << x << ' ';
	}
	fout << '\n';
	// for (int i = 1; i <= m; i ++) {
	// 	int op, l, r, x;
	// 	op = rand() % 4 + 1;
	// 	l = rand() % n + 1;
	// 	r = rand() % n + 1;
	// 	if (l > r) {
	// 		i --;
	// 		continue;
	// 	}
	// 	if (op == 4 || op == 3) {
	// 		x = rand() % 2 + 1;
	// 		fout << op << ' ' << l <<' ' << r << ' ' << x << '\n';
	// 	} else {
	// 		fout << op << ' ' << l << ' ' << r << '\n';
	// 	}
	// }
	fout.close();
}

int main() {
	int ans = 0;
	int n = 1000;
	for (int i = 1; i <= n; i++) {
		printf("Test#%d\n", i);
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
	cout << "Í¨¹ýÂÊ£º" << ans * 1.0 / n * 100 << "%" << endl;

	return 0;
}
