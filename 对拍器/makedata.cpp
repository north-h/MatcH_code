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

	int n, k; n = rand() % 5000 + 1; k = rand() % 1000000000 + 1;
	fout << n << ' ' << k << endl;
	set<int> st;
	vector<int> a;
	for (int i = 1; (int)st.size() < n;) {
		int x = rand() % n + 1;
		// cout << x << ' ' << i << '\n';
		// cout << st.size() << '\n';
		if (!st.count(x)) {
			st.insert(x);
			a.push_back(x);
		}
	}
	for (auto x : a) fout << x << ' ';
	fout << '\n';
	// fout << "6 3 2 4 1 5" << endl;
	for (int i = 1; i <= n; i ++) {
		int x = rand() % 1000 - 1000;
		fout << x << ' ';
	}
    cout << '\n';
	fout.close();
}

int32_t main() {
	int ans = 0;
	int n = 1000;
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
