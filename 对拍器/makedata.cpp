#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

vector<int> p;

void makedata()
{
    ofstream fout("input.txt");
//	srand(time(0));
    int n = rand() % 20 + 1;
	int m = rand() % 20 + 1;
	int k = 2;
    fout << n << ' ' << m << ' ' << k << '\n';
	int b, e;
//	while (true) {
	b = rand() % n, e = rand() % m;
//		if (max((n + b - 1) / b, (m + e - 1) / e) <= k * 3) break;
//	}
	fout << b << ' ' << e << '\n';
	for (int i = 1; i <= 4; i ++){
		int x = rand() % 10, y = rand() % 10;
		fout << x << ' ' << y << '\n';
	}
	for (int i = 1; i <= k; i ++) {
		int x = rand() % 10, y = rand() % 10;
		fout << x << ' ' << y << '\n';
	}
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
