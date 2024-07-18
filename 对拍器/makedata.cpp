#include<bits/stdc++.h>
#include<windows.h>

#define int long long

using namespace std;

void makedata()
{
	ofstream fout("input.txt");
	srand(time(nullptr)); 
	std::random_device rd;  
    std::mt19937 gen(rd()); 

    std::uniform_int_distribution<int> distribution(1, 5);

	int n, k; n = rand() % 10 + 1;
	fout << n << ' ' << 2 << ' ' << 4 << endl;
	string s = "AWSD";
	for (int i = 1; i <= n; i ++) {
		int x = rand() % 4;
		fout << s[x];
	}
	fout << '\n';
	fout.close();
}

int32_t main() {
	int ans = 0;
	int n = 1000;
	for (int i = 1; i <= n; i++) {
		printf("Test#%lld\n", i);
		makedata();
		system("ZJ. < input.txt > ZJ_output.txt");
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
