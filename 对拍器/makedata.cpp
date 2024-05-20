#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

void makedata()
{
    ofstream fout("input.txt");
    int n = rand() % 10 + 4;
	if (n % 2) n ++;
//	int m = rand() % 5 + 1;
//	int k = rand() % 13 + 1, k = rand() % 13 + 1;
    fout << n << '\n';
	set<int> st;
	for (int i = 1; (int)st.size() < n; i ++){
		int k = rand() % n + 1;
		if (st.count(k)) continue;
		st.insert(k);
//		fout << k << ' ';
	}
//	fout << st.size() << '\n';
	for (auto i : st) fout << i << ' ';
	fout << '\n';
//	for (int i = 1; i <= n; i ++){
//		int k = rand() % n + 1;
//		fout << k << ' ';
//	}
//	fout << '\n';
    fout.close();
}

vector<int> a, b;

bool check() {
	int ac = 0, bc = 0;
	for (int i = 1; i < (int)a.size()  - 1; i ++) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) ac ++;
	}
	for (int i = 1; i < (int)b.size()  - 1; i ++) {
		if (b[i] > b[i - 1] && b[i] > b[i + 1]) bc ++;
	}
	cout << ac << ' ' << bc << '\n';
	return ac == bc;
}

int main() {
    int ans = 0;
	int n = 1000;
    for (int i = 1; i <= n; i++) {
        printf("Test#%d\n", i);
        makedata();
        system("ZJ.exe < input.txt > ZJ_output.txt");
        system("BL.exe < input.txt > BL_output.txt");
		int x; 
		freopen("ZJ_output.txt", "r", stdin);
		while (cin >> x) a.push_back(x);
		freopen("BL_output.txt", "r", stdin);
		while (cin >> x) b.push_back(x);
//		for (auto i : a) cout << i << ' '; cout << '\n';
//		for (auto i : b) cout << i << ' '; cout << '\n';
//        if (system("fc ZJ_output.txt BL_output.txt")) {
//            cout << "Wrong Answer!" << endl << endl << endl;
//            break;
//        } else {
//            cout << "Accepted!" << endl << endl << endl;
//            ans ++;
//        }
		if (check()) {
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
